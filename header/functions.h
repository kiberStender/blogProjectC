/* 
 * File:   functions.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 2:18 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

/*Se estiver no Windows mude para cls*/
#define CLEAR "clear"

/*Se estiver no Windows mude para pause*/
#define PAUSE "read -p \"Pressione enter para sair...\""

/*
 * Mensagens do sistema
 */
#define MSG  "Máximo de registros permitidos já cheio!!!"
#define MSG1 "Não existem registros!!!"
#define MSG2 "O registro que buscas nao existe."
#define MSG3 "Removido com sucesso!!!"

/*funcoes que independem de modulo*/
    void desenhaMenu1();
    void desenhaMenu2(char[15]);
    
#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */

