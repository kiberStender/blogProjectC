#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/
#include "functions.h"

#ifndef CLIENTEFN_H
#define CLIENTEFN_H

/*Variaveis de cliente*/
char nomeCli[MAXREG][20], sobrenomeCli[MAXREG][20], rgCli[MAXREG][20],
  cpf[MAXREG][20], datanascCli[MAXREG][15];
/*A cada registro adicionado, iterator aumenta seu valor em 1
 * e a cada registro removido, diminui seu valor em 1
 */
int iteratorCli;

/*Acoes com cliente*/
void cadastraCliente();
void deleteCliente(int);
void atualizaCliente(int);
void verCliente(int);

#endif
