#ifndef FUNCIONARIOFN_H
#define FUNCIONARIOFN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/
#include "data.h"
#include "endereco.h"
#include "funcionario.h"
#include "functions.h"
#include "DbFuncionario.h"

/*Acoes com funcionario*/
void cadastraFuncionario(DbFuncionario*);
void deleteFuncionario(DbFuncionario*, int);
void atualizaFuncionario(DbFuncionario*, int);
void verFuncionario(DbFuncionario*, int);

#endif
