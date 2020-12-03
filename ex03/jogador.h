#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "campo.h"

void inicio ();
void mudajogador( int * jogador, int area[][4] );
int fimdejogo ( int area[][4], int jogador );

#endif