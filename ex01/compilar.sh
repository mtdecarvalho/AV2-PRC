gcc -c util.c -o util.o
gcc -c contatos.c -o contatos.o
gcc -c arqtxt.c -o arqtxt.o
gcc -c menu.c -o menu.o
gcc -c ex01.c -o main.o

gcc util.o contatos.o arqtxt.o menu.o main.o -o main