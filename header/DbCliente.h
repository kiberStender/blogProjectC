/* 
 * File:   DbCliente.h
 * Author: sirkleber
 *
 * Created on February 14, 2015, 7:11 PM
 */

#ifndef DBCLIENTE_H
#define	DBCLIENTE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
#include "cliente.h"
#include "functions.h"
    
typedef struct DbCliente {
  Cliente* db[MAXREG];
  int iterator;
} DbCliente;

DbCliente construtorDbCliente();

void adicionarCliente(DbCliente*, Cliente*);

void removerCliente(DbCliente*, int);

void setDbClienteCliente(DbCliente*, Cliente*, int);

Cliente* getDbClienteCliente(DbCliente*, int);

int buscaCliente(DbCliente* db, char rg[]);

int existeCliente(DbCliente* db, Cliente c);

int estaCheioCliente(DbCliente*);

int temEspacoCliente(DbCliente*);

void freeDbCliente(DbCliente*);

#ifdef	__cplusplus
}
#endif

#endif	/* DBCLIENTE_H */

