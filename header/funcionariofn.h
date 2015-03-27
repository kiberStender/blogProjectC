#ifndef FUNCIONARIOFN_H
#define FUNCIONARIOFN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/
#include "funcionario.h"
#include "functions.h"

/*Variaveis de funcionario*/
Funcionario funcionarios[MAXREG];
/*A cada registro adicionado, iterator aumenta seu valor em 1
 * e a cada registro removido, diminui seu valor em 1
 */
int iteratorFun;

/*Acoes com funcionario*/
int buscaFuncionario(Funcionario[MAXREG], char[20]);
void cadastraFuncionario();
void deleteFuncionario(int);
void atualizaFuncionario(int);
void verFuncionario(int);

#endif
