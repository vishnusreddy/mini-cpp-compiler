## ICG
This is to generate the intermediate code which is machine independent. 

## How do I run this?
You can make use of the shell script provided or use the below commands.
```
yacc -d --warning=none Yacc.y
lex lex.l
gcc -w y.tab.c lex.yy.c
```
After this you can use 
```
a < input.cpp
a < .cpp
```
or if you are doing this on Linux
```
./a.out < input.cpp
```