# Tiny compiler for simple language with [LL(2) grammar](https://en.wikipedia.org/wiki/LL_grammar) written in pure C language. 
# Compiler consist of typical parts, known as:
* [Lexer](https://en.wikipedia.org/wiki/Lexical_analysis) (```lexer.h```)
* [Parser](https://en.wikipedia.org/wiki/Parsing) (```parser.h```)
* Assembler like [code generator](https://en.wikipedia.org/wiki/Code_generation_(compiler)) (```generator.h```)
* [Virtual machine](https://en.wikipedia.org/wiki/Virtual_machine) (```virtual_machine.h```)
## Example of generated code
Following source:
```
var = 3 + 2 * 2;
```
will produces asm-like code:
```
PUSH 3
PUSH 2
PUSH 2
MUL POP, POP
ADD POP, POP
WRITE var
RET
```
## Build
```gcc main.c -o compiler```
## Usage
```compiler source```
## Language description in [EBNF](https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form):
```
program = expr, ";", { program } ;
expr = id, "=", expr | ("+"|"-"), term, { ("+"|"-"), term } ;
term = factor, { ("*"|"/"), factor } ;
factor = "id" | "num" | (expr) ;
```
## Compiler are implemented for education purposes. Some things are simplified for better understanding.

