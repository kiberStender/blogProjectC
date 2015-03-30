#include <stdio.h>
#include "./header/clientefn.h"
#include "./header/funcionariofn.h"

typedef enum Acao {DELETAR = 1, EDITAR, VER} Acao;

typedef enum Modulo{CLIENTE = 1, FUNCIONARIO} Modulo;

void realizaAcaoSwitch(DbCliente*, DbFuncionario*, Modulo, Acao, int);
void realizaAcao(DbCliente*, DbFuncionario*,  Modulo, Acao);
void switchOptions(DbCliente*, DbFuncionario*, Modulo);

int main(int argc, char **argv){  
  int opMenu1;
  
  DbCliente dbCli = construtorDbCliente();
  DbFuncionario dbFun = construtorDbFuncionario();   
    
  desenhaMenu1();
  scanf("%i", &opMenu1);
  
  do {    
    switch(opMenu1){
      case 1:
        switchOptions(&dbCli, &dbFun, CLIENTE);
        break;
      case 2:
        switchOptions(&dbCli, &dbFun, FUNCIONARIO);
        break;
    }
    
    if(opMenu1 != 3){
      desenhaMenu1();
      scanf("%i", &opMenu1);
    }
  } while(opMenu1 != 3);
  
  freeDbCliente(&dbCli);
  freeDbFuncionario(&dbFun);
  
  system(CLEAR);
  
  return 0;
}

void realizaAcaoSwitch(DbCliente* dbCli, DbFuncionario* dbFun, Modulo mod, Acao acao, int posicao){
  switch(acao){
    case DELETAR:
      if(mod == CLIENTE){
        deleteCliente(dbCli, posicao);
      } else {
        deleteFuncionario(dbFun, posicao);
      }
      break;
    case EDITAR:
      if(mod == CLIENTE){
        atualizaCliente(dbCli, posicao);
      } else {
        atualizaFuncionario(dbFun, posicao);
      }
      break;
    case VER:
      if(mod == CLIENTE){
        verCliente(dbCli, posicao);
      } else {
        verFuncionario(dbFun, posicao);
      }
      break;
  }
}

void realizaAcao(DbCliente* dbCli, DbFuncionario* dbFun, Modulo mod, Acao acao){
  system(CLEAR);
  
  switch(mod){
    case CLIENTE:
      if(temEspacoCliente(dbCli)){
        char rg[13];
        
        printf("Digite o RG: ");
        /*Guardando numa variavel temporaria*/
        scanf("%s", rg);
        
        realizaAcaoSwitch(dbCli, dbFun, mod, acao, buscaCliente(dbCli, rg));
      } else {
        printf(MSG1);
      }
      break;
    case FUNCIONARIO:
      if(temEspacoFuncionario(dbFun)){
        char rg[13];
        
        printf("Digite o RG: ");
        /*Guardando numa variavel temporaria*/
        scanf("%s", rg);
        
        realizaAcaoSwitch(dbCli, dbFun, mod, acao, buscaFuncionario(dbFun, rg));
        
      } else {
        printf(MSG1);
      }
      break;
  }
}

void switchOptions(DbCliente* dbC, DbFuncionario* dbF, Modulo modulo){
  int opMenu;
  char mod[15];
  
  if(modulo == CLIENTE){
    strcpy(mod, "cliente");
  } else {
    strcpy(mod, "funcionario");
  }
  
  desenhaMenu2(mod);
  scanf("%i", &opMenu);
  
  do{
    switch(opMenu){
      case 1:
        if(modulo == CLIENTE){
          cadastraCliente(dbC);
        } else {
          cadastraFuncionario(dbF);
        }
        break;
      case 2:
        realizaAcao(dbC, dbF, modulo, DELETAR);
        break;
      case 3:
        realizaAcao(dbC, dbF, modulo, EDITAR);
        break;
      case 4:
        realizaAcao(dbC, dbF, modulo, VER);
        break;
    }
          
    if(opMenu != 5){
      desenhaMenu2(mod);
      scanf("%i", &opMenu);
    }          
  } while(opMenu != 5);
}
