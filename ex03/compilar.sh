gcc -c util.c -o util.o
gcc -c campo.c -o campo.o
gcc -c entrada.c -o entrada.o
gcc -c jogador.c -o jogador.o
gcc -c ex03.c -o main.o

gcc util.o campo.o entrada.o jogador.o main.o -o main