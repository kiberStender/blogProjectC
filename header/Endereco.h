/* 
 * File:   Endereco.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 5:49 AM
 */

#ifndef ENDERECO_H
#define	ENDERECO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct Endereco {
        char* cep;
        char* num;
        char* rua;
        char* bairro;
        char* cidade;
        char* estado;
        char* pais;
    } Endereco;
    
    Endereco* construtorEndereco(char*, char*, char*, char*, char*, char*, char*);
    
    Endereco* construtorEndereco1(Endereco*);
    
    void freeEndereco(Endereco**);
    
    int enderecoEquals(Endereco*, Endereco*);
    
    void setEnderecoCep(Endereco**, char*);
    
    void setEnderecoNum(Endereco**, char*);
    
    void setEnderecoRua(Endereco**, char*);
    
    void setEnderecoBairro(Endereco**, char*);
    
    void setEnderecoCidade(Endereco**, char*);
    
    void setEnderecoEstado(Endereco**, char*);
    
    void setEnderecoPais(Endereco**, char*);
    
    void printEndereco(Endereco*);

#ifdef	__cplusplus
}
#endif

#endif	/* ENDERECO_H */

