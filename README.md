## Tiny compiler
A tiny compiler for a language featuring [LL(2) grammar](https://en.wikipedia.org/wiki/LL_grammar). With Lexer, Parser, ASM-like codegen and VM. Complex enough to give you a flavour of how the "real" thing works whilst not being a mere toy example.

## The compiler consist of typical parts, known as:
* [Lexer](https://en.wikipedia.org/wiki/Lexical_analysis) ([`lex.h`](lex.h))
* [Parser](https://en.wikipedia.org/wiki/Parsing) ([`parser.h`](parser.h))
* Assembler like [code generator](https://en.wikipedia.org/wiki/Code_generation_(compiler)) ([`gen.h`](gen.h))
* [Virtual machine](https://en.wikipedia.org/wiki/Virtual_machine) ([`vm.h`](vm.h))
* [Symbol table](https://en.wikipedia.org/wiki/Symbol_table) ([`sym.h`](sym.h))
* [Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree) ([`ast.h`](ast.h))
## It is by no means a complete industry standard implementation. Some parts are simplified for the sake of better understanding
## Build
```$ make```
## Usage
```$ ./compiler program.src```
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
## The language grammar in [EBNF](https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form):
```
program = expr, ";", { program } ;
expr = id, "=", expr | term, { ("+"|"-"), term } ;
term = factor, { ("*"|"/"), factor } ;
factor = id | num | "(", expr, ")" ;
```

This grammar can be parsed with an LL (left-to-right, leftmost derivation) parser with only 2 tokens of lookahead. In other words, we only need to examine at most 2 upcoming lexical tokens to unambiguously determine which production rule to apply.  

If we look at a single `id` token, we can't tell whether it's an `expr` or a `factor`. We need to look at one more token to remove the ambiguity. That makes it an LL(2) grammar.  

It is also a context-free grammar, which means that on the left side of every production rule there is a single non-terminal symbol.  
