## ICG Optimization
Steps to run this
```
flex lex.l
bison -d int_code.y
gcc int_code.tab.c
```
To then use the compiler with an input source file just run
```
a .cpp
```
or 
```
a input.cpp
```
This should create the following files:
1. icg.txt
2. symtab.txt
3. tokens.txt

To optimize the intermediate code present in icg.txt file, you can run the below code. 
```
python Optimization.py
```