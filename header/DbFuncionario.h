/* 
 * File:   DbFuncionario.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 2:37 PM
 */

#ifndef DBFUNCIONARIO_H
#define	DBFUNCIONARIO_H

#include <stdlib.h>

#include "Funcionario.h"


#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct DbFuncionario {
        Funcionario* funcionario;
        struct DbFuncionario* prox;
    } DbFuncionario;
    
    DbFuncionario* construtorDbFuncionario();
    DbFuncionario* construtorDbFuncionario1(DbFuncionario*, Funcionario*);
    void freeDbFuncionario(DbFuncionario**);
    
    int tamanhoDbFuncionario(DbFuncionario*);
    
    DbFuncionario* consFuncionario(DbFuncionario*, Funcionario*);
    void adicionarFuncionario(DbFuncionario**, Funcionario*);
    
    void removerFuncionario(DbFuncionario**, Funcionario*);
    
    void setDbFuncionarioFuncionario(DbFuncionario**, Funcionario*, Funcionario*);
    
    Funcionario* getDbFuncionarioFuncionario(DbFuncionario*, Funcionario*);
    
    int existeFuncionario(DbFuncionario*, Funcionario*);

#ifdef	__cplusplus
}
#endif

#endif	/* DBFUNCIONARIO_H */