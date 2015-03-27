#ifndef CLIENTEFN_H
#define CLIENTEFN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/
#include "cliente.h"
#include "functions.h"

/*Variaveis de cliente*/
Cliente clientes[MAXREG];
/*A cada registro adicionado, iterator aumenta seu valor em 1
 * e a cada registro removido, diminui seu valor em 1
 */
int iteratorCli;

/*Acoes com cliente*/
int buscaCliente(Cliente[MAXREG], char[20]);
int existeCliente(Cliente[MAXREG], Cliente);
void cadastraCliente();
void deleteCliente(int);
void atualizaCliente(int);
void verCliente(int);

#endif
