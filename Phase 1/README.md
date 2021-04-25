## Phase 1
This is the first phase of the project.  

## How do I run this?
You can make use of the shell script ```./ex.sh``` or
```
lex sym.l
yacc -d sym.y
yacc -v sym.y
gcc y.tab.c lex.yy.c -ll -lfl -o compiler
cat input.cpp | ./compiler

```