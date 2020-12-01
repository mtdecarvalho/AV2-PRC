gcc -c util.c -o util.o
gcc -c conjuntos.c -o conjuntos.o
gcc -c ex04.c -o main.o

gcc util.o conjuntos.o main.o -o main