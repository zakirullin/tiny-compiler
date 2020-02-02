# A tiny compiler for a simple synthetic language featuring [LL(2) grammar](https://en.wikipedia.org/wiki/LL_grammar), written in pure C 
## The compiler consist of typical parts, known as:
* [Lexer](https://en.wikipedia.org/wiki/Lexical_analysis) ([`lexer.c`](./src/lexer.c))
* [Parser](https://en.wikipedia.org/wiki/Parsing) ([`parser.c`](./src/parser.c))
* Assembler like [code generator](https://en.wikipedia.org/wiki/Code_generation_(compiler)) ([`gen.c`](./src/gen.c))
* [Virtual machine](https://en.wikipedia.org/wiki/Virtual_machine) ([`vm.c`](./src/vm.c))
* [Symbol table](https://en.wikipedia.org/wiki/Symbol_table) ([`sym.c`](./src/sym.c))
* [Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree) ([`ast.c`](./src/ast.c))
## The compiler is implemented for educational purposes. Some parts are simplified for the sake of better understanding
## Build
```$ make```
## Usage
```$ ./compiler <source>```
## An example program for Pythagorean theorem:
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
