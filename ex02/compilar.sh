gcc -c util.c -o util.o
gcc -c estoque.c -o estoque.o
gcc -c arqtxt.c -o arqtxt.o
gcc -c menu.c -o menu.o
gcc -c ex02.c -o main.o

gcc util.o estoque.o arqtxt.o menu.o main.o -o main