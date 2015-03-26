#ifndef FUNCIONARIOFN_H
#define FUNCIONARIOFN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/
#include "functions.h"

/*Variaveis de funcionario*/
char nomeFun[MAXREG][20], sobrenomeFun[MAXREG][20], rgFun[MAXREG][20],
  cartTrab[MAXREG][20], datanascFun[MAXREG][15];
/*A cada registro adicionado, iterator aumenta seu valor em 1
 * e a cada registro removido, diminui seu valor em 1
 */
int iteratorFun;

/*Acoes com funcionario*/
void cadastraFuncionario();
void deleteFuncionario(int);
void atualizaFuncionario(int);
void verFuncionario(int);

#endif
