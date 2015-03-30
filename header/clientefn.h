#ifndef CLIENTEFN_H
#define CLIENTEFN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/
#include "data.h"
#include "endereco.h"
#include "cliente.h"
#include "functions.h"
#include "DbCliente.h"

/*Acoes com cliente*/
void cadastraCliente(DbCliente*);
void deleteCliente(DbCliente*, int);
void atualizaCliente(DbCliente*, int);
void verCliente(DbCliente*, int);

#endif
