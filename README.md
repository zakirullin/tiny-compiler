# Tiny compiler for a simple language with [LL(2) grammar](https://en.wikipedia.org/wiki/LL_grammar) implemented in pure C language. 
## Build
```gcc main.c```
## Language description in [EBNF](https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form):
```
program = expr, ";", { program } ;
expr = id, "=", expr | ("+"|"-"), term, { ("+"|"-"), term } ;
term = factor, { ("*"|"/"), factor } ;
factor = "id" | "num" | (expr) ;
```

