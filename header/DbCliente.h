/* 
 * File:   DbCliente.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 7:39 AM
 */

#ifndef DBCLIENTE_H
#define	DBCLIENTE_H

#include <stdlib.h>
#include <stdio.h>
#include "Cliente.h"


#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct DbCliente {
        Cliente* cliente;
        struct DbCliente* prox;
    } DbCliente;
    
    DbCliente* construtorDbCliente();
    DbCliente* construtorDbCliente1(DbCliente*, Cliente*);
    void freeDbCliente(DbCliente**);
    
    int tamanhoDbCliente(DbCliente*);
    
    DbCliente* consCliente(DbCliente*, Cliente*);
    void adicionarCliente(DbCliente**, Cliente*);
    
    void removerCliente(DbCliente**, Cliente*);
    
    void setDbClienteCliente(DbCliente**, Cliente*, Cliente*);
    
    Cliente* getDbClienteCliente(DbCliente*, Cliente*);
    
    int existeCliente(DbCliente*, Cliente*);

#ifdef	__cplusplus
}
#endif

#endif	/* DBCLIENTE_H */

