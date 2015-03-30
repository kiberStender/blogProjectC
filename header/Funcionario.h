/* 
 * File:   Funcionario.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 2:27 PM
 */

#ifndef FUNCIONARIO_H
#define	FUNCIONARIO_H

#include "Data.h"
#include "Endereco.h"


#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct Funcionario {
        char* nome;
        char* sobrenome;
        char* rg;
        char* cartTrab;
        Data* dataNasc;
        Endereco* end;
    } Funcionario;
    
    Funcionario* construtorFuncionario(char*, char*, char*, char*, Data*, Endereco*);
    Funcionario* construtorFuncionario1(char*);
    Funcionario* construtorFuncionario2(Funcionario*);
    void freeFuncionario(Funcionario**);
    
    int funcionarioCmp(Funcionario*, Funcionario*);
    int equalsFuncionario(Funcionario*, Funcionario*);
    int funcionarioMaiorQue(Funcionario*, Funcionario*);
    
    void setFuncionarioNome(Funcionario**, char*);
    
    void setFuncionarioSobrenome(Funcionario**, char*);
    
    void setFuncionarioRG(Funcionario**, char*);
    
    void setFuncionarioCartTrab(Funcionario**, char*);
    
    void setFuncionarioDataNasc(Funcionario**, Data*);
    
    void setFuncionarioEnd(Funcionario**, Endereco*);
    
    void printFuncionario(Funcionario*);

#ifdef	__cplusplus
}
#endif

#endif	/* FUNCIONARIO_H */

