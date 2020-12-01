gcc -c uteis.c -o uteis.o
gcc -c contatos.c -o contatos.o
gcc -c arqtxt.c -o arqtxt.o
gcc -c menu.c -o menu.o
gcc -c ex01.c -o main.o

gcc uteis.o contatos.o arqtxt.o menu.o main.o -o main