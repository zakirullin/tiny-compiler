#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "lex.h"
#include "input.h"
#include "defs.h"
#include "func.h"
#include "sym.h"
#include "ast.h"

#define MAX_IDENTIFIER_LENGTH 256

typedef enum {
    TOKEN_END_OF_PROGRAM,
    TOKEN_OPERATOR_ADD,
    TOKEN_OPERATOR_SUB,
    TOKEN_OPERATOR_MUL,
    TOKEN_OPERATOR_DIV,
    TOKEN_LEFT_PARENTHESIS,
    TOKEN_RIGHT_PARENTHESIS,
    TOKEN_ASSIGNMENT,
    TOKEN_SEMICOLON,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    void* attribute;
    int line;
    int column;
    char* error_message;
} Token;

typedef struct {
    char* buffer;
    int position;
    int length;
    int line;
    int column;
} InputBuffer;

InputBuffer input_buffer;

void init_input_buffer() {
    input_buffer.buffer = NULL;
    input_buffer.position = 0;
    input_buffer.length = 0;
    input_buffer.line = 1;
    input_buffer.column = 0;
}

void free_input_buffer() {
    if (input_buffer.buffer != NULL) {
        free(input_buffer.buffer);
        input_buffer.buffer = NULL;
    }
}

bool load_input_buffer(const char* filename) {
    free_input_buffer();

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }

    fseek(file, 0, SEEK_END);
    input_buffer.length = ftell(file);
    fseek(file, 0, SEEK_SET);

    input_buffer.buffer = (char*)malloc(input_buffer.length + 1);
    if (input_buffer.buffer == NULL) {
        fclose(file);
        return false;
    }

    input_buffer.position = 0;
    input_buffer.buffer[input_buffer.length] = '\0';

    size_t result = fread(input_buffer.buffer, 1, input_buffer.length, file);
    fclose(file);

    if (result != input_buffer.length) {
        free_input_buffer();
        return false;
    }

    return true;
}

int read_char() {
    if (input_buffer.position >= input_buffer.length) {
        return EOF;
    }

    char c = input_buffer.buffer[input_buffer.position++];
    input_buffer.column++;

    if (c == '\n') {
        input_buffer.line++;
        input_buffer.column = 0;
    }

    return (int)c;
}

void unread_char(int c) {
    if (c == EOF) {
        return;
    }

    input_buffer.position--;
    input_buffer.column--;

    if (c == '\n') {
        input_buffer.line--;
        int i = input_buffer.position - 1;
        while (i >= 0 && input_buffer.buffer[i] != '\n') {
            i--;
        }
        input_buffer.column = input_buffer.position - i - 1;
    }
}

bool is_identifier_start(int c) {
    return isalpha(c) || c == '_';
}

bool is_identifier_body(int c) {
    return isalnum(c) || c == '_';
}

Token lex_identifier() {
    char* buffer = (char*)malloc(MAX_IDENTIFIER_LENGTH + 1);
    int i = 0;

    int c = read_char();
    while (is_identifier_body(c) && i < MAX_IDENTIFIER_LENGTH) {
        buffer[i++] = (char)c;
        c = read_char();
    }
    unread_char(c);
    buffer[i] = '\0';

    Token token;
    token.type = TOKEN_IDENTIFIER;
    token.attribute = add_sym(buffer);
    token.line = input
