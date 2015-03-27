#include <stdio.h>
#include "./header/clientefn.h"
#include "./header/funcionariofn.h"

typedef enum acao {DELETAR = 1, EDITAR, VER} Acao;

typedef enum modulo{CLIENTE = 1, FUNCIONARIO} Modulo;

void realizaAcaoSwitch(Modulo, Acao, int);
void realizaAcao(int, Modulo, Acao);
void switchOptions(int, Modulo);

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

void realizaAcaoSwitch(Modulo mod, Acao acao, int posicao){
  switch(acao){
    case DELETAR:
      if(mod == CLIENTE){
        deleteCliente(posicao);
      } else {
        deleteFuncionario(posicao);
      }
      break;
    case EDITAR:
      if(mod == CLIENTE){
        atualizaCliente(posicao);
      } else {
        atualizaFuncionario(posicao);
      }
      break;
    case VER:
      if(mod == CLIENTE){
        verCliente(posicao);
      } else {
        verFuncionario(posicao);
      }
      break;
  }
}

void realizaAcao(int iterator, Modulo mod, Acao acao){
  system(CLEAR);
  
  if(iterator > 0){
    char tempRg[20];
    
    printf("Digite o RG: ");
    /*Guardando numa variavel temporaria*/
    scanf("%s", tempRg);
    
    if(mod == FUNCIONARIO){      
      realizaAcaoSwitch(mod, acao, buscaFuncionario(funcionarios, tempRg));
    } else {
      realizaAcaoSwitch(mod, acao, buscaCliente(clientes, tempRg));
    }    
  } else {
    printf(MSG1);
  }
}

void switchOptions(int iterator, Modulo modulo){
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
