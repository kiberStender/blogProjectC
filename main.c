#include <stdio.h>

#include "header/ControladorCliente.h"
#include "header/functions.h"
#include "header/ControladorFuncionario.h"

typedef enum Modulo {CLIENTE, FUNCIONARIO} Modulo;
typedef enum Acao {EDITAR, DELETAR, VER} Acao;

void switchOptions(ControladorCliente*, ControladorFuncionario*, Modulo);
void realizaAcao(ControladorCliente*, ControladorFuncionario*, Modulo, Acao);
void realizaAcaoCliente(ControladorCliente**, Acao, Cliente*);
void realizaAcaoFuncionario(ControladorFuncionario*, Acao, Funcionario*);

int main(){
  ControladorCliente cCli = construtorControladorCliente();
  ControladorFuncionario cFun = construtorControladorFuncionario();
  int opMenu1;
  
  desenhaMenu1();
  scanf("%i", &opMenu1);
  
  do {    
    switch(opMenu1){
      case 1:
        switchOptions(&cCli, &cFun, CLIENTE);        
        break;
      case 2:
        switchOptions(&cCli, &cFun, FUNCIONARIO);
        break;
    }
    
    if(opMenu1 != 3){
      desenhaMenu1();
      scanf("%i", &opMenu1);
    }
    
  } while(opMenu1 != 3);  
  
  freeControladorCliente(&cCli);
  freeControladorFuncionario(&cFun);
  
  system(CLEAR);
  
  return 0;
}

void switchOptions(ControladorCliente* cCli, ControladorFuncionario* cFun, Modulo m) {
  int opMenu;
  char mod[15];
  
  if(m == CLIENTE){
    strcpy(mod, "cliente");
    carregaArquivoCC(cCli);
  } else {
    strcpy(mod, "funcionario");
  }
  
  desenhaMenu2(mod);
  scanf("%i", &opMenu);
  
  do {
    switch(opMenu){
      case 1:
        if(m == CLIENTE){
          cadastraCliente(cCli);          
        } else {
          cadastraFuncionario(cFun);
        }
        break;
      case 2:
        realizaAcao(cCli, cFun, m, DELETAR);
        break;
      case 3:
        realizaAcao(cCli, cFun, m, EDITAR);
        break;
      case 4:        
        realizaAcao(cCli, cFun, m, VER);
        break;
    }
    
    if(opMenu != 5){
      desenhaMenu2(mod);
      scanf("%i", &opMenu);
    }
    
  } while(opMenu != 5);
  
  if(m == CLIENTE){
    if(tamanhoDbCliente(cCli->lista) > 0){
      gravaArquivoCC(cCli);
    }
  } else {
    
  }
  
}

void realizaAcao(ControladorCliente* cCli, ControladorFuncionario* cFun, Modulo m, Acao a){
  system(CLEAR);
  char rg[13]; //PT na véia
  
  printf("Digite o RG: ");
  scanf("%s", rg);
  
  switch(m){
    case CLIENTE:
      realizaAcaoCliente(&cCli, a, construtorCliente1(rg));
      break;
    case FUNCIONARIO:
      realizaAcaoFuncionario(cFun, a, construtorFuncionario1(rg));
      break;
  }
  
}

void realizaAcaoCliente(ControladorCliente** cCli, Acao a, Cliente* prc) {  
  switch(a){
    case DELETAR:
      deleteCliente(*cCli, prc);
      break;
    case EDITAR:
      atualizaCliente(*cCli, prc);
      break;
    case VER:
      if((*cCli)->lista == NULL){
        printf("NULL");
      } else {
        printf("not NULL");
      }
      
      verCliente(*cCli, prc);
      break;
  }
}

void realizaAcaoFuncionario(ControladorFuncionario* cFun, Acao a, Funcionario* prc) {
  switch(a){
    case DELETAR:
      deleteFuncionario(cFun, prc);
      break;
    case EDITAR:
      atualizaFuncionario(cFun, prc);
      break;
    case VER:
      verFuncionario(*cFun, prc);
      break;
  }
}