/* 
 * File:   DbFuncionario.h
 * Author: sirkleber
 *
 * Created on February 16, 2015, 11:34 AM
 */

#ifndef DBFUNCIONARIO_H
#define	DBFUNCIONARIO_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
#include "funcionario.h"
#include "functions.h"

typedef struct DbFuncionario {
  Funcionario* db[MAXREG];
  int iterator;
} DbFuncionario;

DbFuncionario construtorDbFuncionario();

void adicionarFuncionario(DbFuncionario*, Funcionario*);

void removerFuncionario(DbFuncionario*, int);

void setDbFuncionarioFuncionario(DbFuncionario*, Funcionario*, int);

Funcionario* getDbFuncionarioFuncionario(DbFuncionario*, int);

int buscaFuncionario(DbFuncionario* db, char rg[]);

int existeFuncionario(DbFuncionario*, Funcionario);

int estaCheioFuncionario(DbFuncionario*);

int temEspacoFuncionario(DbFuncionario*);

void freeDbFuncionario(DbFuncionario*);

#ifdef	__cplusplus
}
#endif

#endif	/* DBFUNCIONARIO_H */

