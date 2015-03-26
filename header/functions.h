#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

/*Máximo de registros que nosso programa irá guardar*/
#define MAXREG 10

/*Se estiver no Windows mude para cls*/
#define CLEAR "clear"

/*Se estiver no Windows mude para pause*/
#define PAUSE "read -p \"Pressione enter para sair...\""

/*
 * Mensagens do sistema
 */
#define msg  "Máximo de registros permitidos já cheio!!!"
#define msg1 "Não existem registros!!!"
#define msg2 "O registro que buscas nao existe."
#define msg3 "Removido com sucesso!!!"

/*funcoes que independem de modulo*/
int buscaRG(char[MAXREG][20], char[20]);
void desenhaMenu1();
void desenhaMenu2(char[15]);
