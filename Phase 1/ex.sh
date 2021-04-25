#!/bin/bash
lex sym.l
yacc -d sym.y
yacc -v sym.y
gcc y.tab.c lex.yy.c -ll -lfl 
