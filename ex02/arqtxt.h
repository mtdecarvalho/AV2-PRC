#ifndef _ARQTXT_H_
#define _ARQTXT_H_

#include "estoque.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerAte(FILE *arq, char sep, char strdest[], int max);
void lerestoque (char nomearq[], Testoque * a);
void gravarestoque (char nomearq[], Testoque a);

#endif