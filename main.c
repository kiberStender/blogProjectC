#include <stdio.h>
#include "./header/clientefn.h"
#include "./header/funcionariofn.h"

enum acoes {DELETAR = 1, EDITAR, VER};

enum modulos{CLIENTE = 1, FUNCIONARIO};

void realizaAcaoSwitch(int, int, int);
void realizaAcao(int, int, int);
void switchOptions(int, int);

int main(int argc, char **argv){
  int opMenu1;
  
  desenhaMenu1();
  scanf("%i", &opMenu1);
  
  do {    
    switch(opMenu1){
      case 1:
        switchOptions(iteratorCli, CLIENTE);
        break;
      case 2:
        switchOptions(iteratorCli, FUNCIONARIO);
        break;
    }
    
    if(opMenu1 != 3){
      desenhaMenu1();
      scanf("%i", &opMenu1);
    }
  } while(opMenu1 != 3);
  
  system(CLEAR);
  
  return 0;
}

void realizaAcaoSwitch(int modulo, int acao, int posicao){
  switch(acao){
    case DELETAR:
      if(modulo == CLIENTE){
        deleteCliente(posicao);
      } else {
        deleteFuncionario(posicao);
      }
      break;
    case EDITAR:
      if(modulo == CLIENTE){
        atualizaCliente(posicao);
      } else {
        atualizaFuncionario(posicao);
      }
      break;
    case VER:
      if(modulo == CLIENTE){
        verCliente(posicao);
      } else {
        verFuncionario(posicao);
      }
      break;
  }
}

void realizaAcao(int iterator, int modulo, int acao){
  system(CLEAR);
  
  if(iterator > 0){
    char tempRg[20];
    
    printf("Digite o RG: ");
    /*Guardando numa variavel temporaria*/
    scanf("%s", tempRg);
    
    if(modulo == FUNCIONARIO){      
      realizaAcaoSwitch(modulo, acao, buscaRG(rgFun, tempRg));
    } else if(modulo == CLIENTE){
      realizaAcaoSwitch(modulo, acao, buscaRG(rgCli, tempRg));
    } else {
      printf("Por favor escolha um dos modulos: Funcionario ou Cliente");
    }    
  } else {
    printf(msg1);
  }
}

void switchOptions(int iterator, int modulo){
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
          cadastraCliente();
        } else {
          cadastraFuncionario();
        }
        break;
      case 2:
        realizaAcao(iterator, modulo, DELETAR);
        break;
      case 3:
        realizaAcao(iterator, modulo, EDITAR);
        break;
      case 4:
        realizaAcao(iterator, modulo, VER);
        break;
    }
          
    if(opMenu != 5){
      desenhaMenu2(mod);
      scanf("%i", &opMenu);
    }          
  } while(opMenu != 5);
}
