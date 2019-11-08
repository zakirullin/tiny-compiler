# A tiny compiler for a simple synthetic language with [LL(2) grammar](https://en.wikipedia.org/wiki/LL_grammar), written in pure C 
## The compiler consist of typical parts, known as:
* [Lexer](https://en.wikipedia.org/wiki/Lexical_analysis) (```lexer.h```)
* [Parser](https://en.wikipedia.org/wiki/Parsing) (```parser.h```)
* Assembler like [code generator](https://en.wikipedia.org/wiki/Code_generation_(compiler)) (```generator.h```)
* [Virtual machine](https://en.wikipedia.org/wiki/Virtual_machine) (```virtual_machine.h```)
* [Symbol table](https://en.wikipedia.org/wiki/Symbol_table) (```symbol_table.h```)
* [Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree) (```ast.h```)
## The compiler is implemented for educational purposes. Some parts are simplified for better understanding
## Build
```$ gcc main.c -o compiler```
## Usage
```$ ./compiler source```
## Example program for Pythagorean theorem:
```
cath1 = 3;
cath2 = 4;
hypsquare = cath1 * cath1 + cath2 * cath2;
```
Execution result:
```
hypsquare = 25
```
Generated ASM:
```asm
PUSH 3
WRITE cath1
PUSH 4
WRITE cath2
READ cath1
READ cath1
MUL POP, POP
READ cath2
READ cath2
MUL POP, POP
ADD POP, POP
WRITE hypsquare
```
## The language description in [EBNF](https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form):
```
program = expr, ";", { program } ;
expr = id, "=", expr | ("+"|"-"), term, { ("+"|"-"), term } ;
term = factor, { ("*"|"/"), factor } ;
factor = "id" | "num" | (expr) ;
```
