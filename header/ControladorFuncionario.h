/* 
 * File:   ControladorFuncionario.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 2:49 PM
 */

#ifndef CONTROLADORFUNCIONARIO_H
#define	CONTROLADORFUNCIONARIO_H
#include "functions.h"
#include "DbFuncionario.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct ControladorFuncionario {
        DbFuncionario* lista;
    } ControladorFuncionario;
    
    ControladorFuncionario construtorControladorFuncionario();
    void freeControladorFuncionario(ControladorFuncionario*);
    
    void cadastraFuncionario(ControladorFuncionario*);
    void deleteFuncionario(ControladorFuncionario*, Funcionario*);
    void atualizaFuncionario(ControladorFuncionario*, Funcionario*);
    void verFuncionario(ControladorFuncionario, Funcionario*);
    
    Funcionario* getCfFuncionario(ControladorFuncionario, Funcionario*);

#ifdef	__cplusplus
}
#endif

#endif	/* CONTROLADORFUNCIONARIO_H */

