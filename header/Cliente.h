/* 
 * File:   Cliente.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 5:48 AM
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Endereco.h"
#include "Data.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct Cliente {
        char* nome;
        char* sobrenome;
        char* rg;
        char* cpf;
        Data* dataNasc;
        Endereco* end;
    } Cliente;
    
    Cliente* construtorCliente(char*, char*, char*, char*, Data*, Endereco*);
    Cliente* construtorCliente1(char*);
    Cliente* construtorCliente2(Cliente*);
    void freeCliente(Cliente**);
    
    int clienteCmp(Cliente*, Cliente*);
    int equalsCliente(Cliente*, Cliente*);
    int clienteMaiorQue(Cliente*, Cliente*);
    
    void setClienteNome(Cliente**, char*);
    
    void setClienteSobrenome(Cliente**, char*);
    
    void setClienteRG(Cliente**, char*);
    
    void setClienteCpf(Cliente**, char*);
    
    void setClienteDataNasc(Cliente**, Data*);
    
    void setClienteEnd(Cliente**, Endereco*);
    
    void printCliente(Cliente*);

#ifdef	__cplusplus
}
#endif

#endif	/* CLIENTE_H */

