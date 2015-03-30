#include "../header/funcionario.h"
#include <string.h>

Funcionario* construtorFuncionario(
  char nome[], char sobrenome[], char rg[], char cartTrab[], 
        Data dataNasc, Endereco end){
  Funcionario *f = (Funcionario*) calloc(1, sizeof(Funcionario));
  
  f->nome = (char*) calloc(strlen(nome), sizeof(char));
  strcpy(f->nome, nome);
  
  f->sobrenome = (char*) calloc(strlen(sobrenome), sizeof(char));
  strcpy(f->sobrenome, sobrenome);
  
  f->rg = (char*) calloc(strlen(rg), sizeof(char));
  strcpy(f->rg, rg);
  
  f->cartTrab = (char*) calloc(strlen(cartTrab), sizeof(char));
  strcpy(f->cartTrab, cartTrab);
  
  f->dataNasc = construtorData2(dataNasc);
  f->end = construtorEndereco1(end);
  
  return f;
}

int equalsFuncionario(Funcionario a, Funcionario b){
  if(strncmp(a.rg, b.rg, strlen(a.rg)) != 0){
    return 0;
  } else if(strncmp(a.rg, b.rg, strlen(a.rg)) != 0){
    return 0;
  } else {
    return 1;
  }
}

void setFuncionarioNome(Funcionario* f, char* nome) {
  free(f->nome);
  f->nome = (char*) calloc(strlen(nome), sizeof(char));
  strcpy(f->nome, nome);
}

void setFuncionarioSobrenome(Funcionario* f, char* sobrenome){
  free(f->sobrenome);
  f->sobrenome = (char*) calloc(strlen(sobrenome), sizeof(char));
  strcpy(f->sobrenome, sobrenome);
}

void setFuncionarioRG(Funcionario* f, char* rg){
  free(f->rg);
  f->rg = (char*) calloc(strlen(rg), sizeof(char));
  strcpy(f->rg, rg);
}

void setFuncionarioCartTrab(Funcionario* f, char* cartTrab){
  free(f->cartTrab);
  f->cartTrab = (char*) calloc(strlen(cartTrab), sizeof(char));
  strcpy(f->cartTrab, cartTrab);
}

void setFuncionarioDataNasc(Funcionario* f, Data d){
  f->dataNasc = d;
}

void setFuncionarioEnd(Funcionario* f, Endereco e){
  f->end = e;
}

void printFuncionario(Funcionario f){
  
  printf("Nome: %s\n", f.nome);
  printf("Sobrenome: %s\n", f.sobrenome);
  printf("RG: %s\n", f.rg);
  printf("Carteira de trabalho: %s\n", f.cartTrab);
  printf("Data de nascimento: ");
  printData(f.dataNasc);
  printf("Endereco: \n");
  printEndereco(f.end);
}

void freeFuncionario(Funcionario* f){
  freeData(&f->dataNasc);
  freeEndereco(&f->end);

  free(f->nome);
  f->nome = NULL;
  
  free(f->sobrenome);
  f->sobrenome = NULL;
  
  free(f->rg);
  f->rg = NULL;
  
  free(f->cartTrab);
  f->cartTrab = NULL;
  
  free(f);
  f = NULL;
}
