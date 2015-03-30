/* 
 * File:   ControladorCliente.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 8:42 AM
 */

#ifndef CONTROLADORCLIENTE_H
#define	CONTROLADORCLIENTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "DbCliente.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct ControladorCliente {
        DbCliente* lista;
        FILE* arquivo;
    } ControladorCliente;
    
    ControladorCliente construtorControladorCliente();
    void freeControladorCliente(ControladorCliente*);
    
    //Operações com arquivps
    
    void carregaArquivoCC(ControladorCliente*);
    void gravaArquivoCC(ControladorCliente*);
    
    void cadastraCliente(ControladorCliente*);
    void deleteCliente(ControladorCliente*, Cliente*);
    void atualizaCliente(ControladorCliente*, Cliente*);
    void verCliente(ControladorCliente*, Cliente*);
    
    Cliente* getCcCliente(ControladorCliente*, Cliente*);


#ifdef	__cplusplus
}
#endif

#endif	/* CONTROLADORCLIENTE_H */

