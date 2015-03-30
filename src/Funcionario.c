#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../header/Funcionario.h"

Funcionario* construtorFuncionario(
  char* nome, char* sobrenome, char* rg, 
  char* cartTrab, Data* dtNasc, Endereco* end
){
  Funcionario* f = (Funcionario*) calloc(1, sizeof(Funcionario));
  
  f->nome = (char*) calloc(strlen(nome), sizeof(char));
  strcpy(f->nome, nome);
  
  f->sobrenome = (char*) calloc(strlen(sobrenome), sizeof(char));
  strcpy(f->sobrenome, sobrenome);
  
  f->rg = (char*) calloc(strlen(rg), sizeof(char));
  strcpy(f->rg, rg);
  
  f->cartTrab = (char*) calloc(strlen(cartTrab), sizeof(char));
  strcpy(f->cartTrab, cartTrab);
  
  f->dataNasc = construtorData2(dtNasc);
  f->end = construtorEndereco1(end);
  
  return f;
}
Funcionario* construtorFuncionario1(char* rg){
  Data* dt = construtorData("01/01/1999");
  Endereco* end = construtorEndereco("", "", "", "", "", "", "");
  
  return construtorFuncionario("", "", rg, "", dt, end);
}

Funcionario* construtorFuncionario2(Funcionario* f) {
  return construtorFuncionario(f->nome, f->sobrenome, f->rg, f->cartTrab, f->dataNasc, f->end);
}

void freeFuncionario(Funcionario** f){
  freeData(&(*f)->dataNasc);
  freeEndereco(&(*f)->end);
  
  free((*f)->nome);
  (*f)->nome = NULL;
  
  free((*f)->sobrenome);
  (*f)->sobrenome = NULL;
  
  free((*f)->rg);
  (*f)->rg = NULL;
  
  free((*f)->cartTrab);
  (*f)->cartTrab = NULL;
  
  free(*f);
  *f = NULL;
}

int funcionarioCmp(Funcionario* a, Funcionario* b){  
  return strncmp(a->rg, b->rg, strlen(a->rg));
}

int equalsFuncionario(Funcionario* a, Funcionario* b){
  if(strncmp(a->rg, b->rg, strlen(a->rg)) == 0){
    if(strncmp(a->cartTrab, b->cartTrab, strlen(a->cartTrab)) == 0){
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

int funcionarioMaiorQue(Funcionario* a, Funcionario* b){
  switch(funcionarioCmp(a, b)){
    case -1: 
      return 0;
    case 0: 
      return 0;
    case 1: 
      return 1;
    default:
      return 0;
  }
}

void setFuncionarioNome(Funcionario** f, char* nome){
  free((*f)->nome);
  (*f)->nome = (char*) calloc(strlen(nome), sizeof(char));
  strcpy((*f)->nome, nome);  
}

void setFuncionarioSobrenome(Funcionario** f, char* sobrenome){
  free((*f)->sobrenome);
  (*f)->sobrenome = (char*) calloc(strlen(sobrenome), sizeof(char));
  strcpy((*f)->sobrenome, sobrenome);
}
  

void setFuncionarioRG(Funcionario** f, char* rg){
  free((*f)->rg);
  (*f)->rg = (char*) calloc(strlen(rg), sizeof(char));
  strcpy((*f)->rg, rg);
}

void setFuncionarioCartTrab(Funcionario** f, char* cartTrab){
  free((*f)->cartTrab);
  (*f)->cartTrab = (char*) calloc(strlen(cartTrab), sizeof(char));
  strcpy((*f)->cartTrab, cartTrab);
}

void setFuncionarioDataNasc(Funcionario** f, Data* dt){
  (*f)->dataNasc = construtorData2(dt);
}

void setFuncionarioEnd(Funcionario** f, Endereco* end){
  (*f)->end = construtorEndereco1(end);
}

void printFuncionario(Funcionario* f){
  printf("Nome: %s\n", f->nome);
  printf("Sobrenome: %s\n", f->sobrenome);
  printf("RG: %s\n", f->rg);
  printf("CPF: %s\n", f->cartTrab);
  printf("Data de nascimento: ");
  printData(f->dataNasc);
  printf("\nEndereço: \n");
  printEndereco(f->end);
}
