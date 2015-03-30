#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../header/Cliente.h"

Cliente* construtorCliente(
  char* nome, char* sobrenome, char* rg, 
  char* cpf, Data* dtNasc, Endereco* end
){
  Cliente* c = (Cliente*) calloc(1, sizeof(Cliente));
  
  c->nome = (char*) calloc(strlen(nome), sizeof(char));
  strcpy(c->nome, nome);
  
  c->sobrenome = (char*) calloc(strlen(sobrenome), sizeof(char));
  strcpy(c->sobrenome, sobrenome);
  
  c->rg = (char*) calloc(strlen(rg), sizeof(char));
  strcpy(c->rg, rg);
  
  c->cpf = (char*) calloc(strlen(cpf), sizeof(char));
  strcpy(c->cpf, cpf);
  
  c->dataNasc = construtorData2(dtNasc);
  c->end = construtorEndereco1(end);
  
  return c;
}
Cliente* construtorCliente1(char* rg){
  Data* dt = construtorData("01/01/1999");
  Endereco* end = construtorEndereco("cep", "casa", "rua", "bair", "cid", "est", "pais");
  
  return construtorCliente("", "", rg, "", dt, end);
}

Cliente* construtorCliente2(Cliente* c) {
  return construtorCliente(c->nome, c->sobrenome, c->rg, c->cpf, c->dataNasc, c->end);
}

void freeCliente(Cliente** c){
  if(*c != NULL) {
    freeData(&(*c)->dataNasc);
    freeEndereco(&(*c)->end);

    free((*c)->nome);
    (*c)->nome = NULL;

    free((*c)->sobrenome);
    (*c)->sobrenome = NULL;

    free((*c)->rg);
    (*c)->rg = NULL;

    free((*c)->cpf);
    (*c)->cpf = NULL;

    free(*c);
    *c = NULL;
  }
}

int clienteCmp(Cliente* a, Cliente* b){  
  return strncmp(a->rg, b->rg, strlen(a->rg));
}

int equalsCliente(Cliente* a, Cliente* b){
  if(strncmp(a->rg, b->rg, strlen(a->rg)) == 0){
    if(strncmp(a->cpf, b->cpf, strlen(a->cpf)) == 0){
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

int clienteMaiorQue(Cliente* a, Cliente* b){
  switch(clienteCmp(a, b)){
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

void setClienteNome(Cliente** c, char* nome){
  free((*c)->nome);
  (*c)->nome = (char*) calloc(strlen(nome), sizeof(char));
  strcpy((*c)->nome, nome);  
}

void setClienteSobrenome(Cliente** c, char* sobrenome){
  free((*c)->sobrenome);
  (*c)->sobrenome = (char*) calloc(strlen(sobrenome), sizeof(char));
  strcpy((*c)->sobrenome, sobrenome);
}
  

void setClienteRG(Cliente** c, char* rg){
  free((*c)->rg);
  (*c)->rg = (char*) calloc(strlen(rg), sizeof(char));
  strcpy((*c)->rg, rg);
}

void setClienteCpf(Cliente** c, char* cpf){
  free((*c)->cpf);
  (*c)->cpf = (char*) calloc(strlen(cpf), sizeof(char));
  strcpy((*c)->cpf, cpf);
}

void setClienteDataNasc(Cliente** c, Data* dt){
  (*c)->dataNasc = construtorData2(dt);
}

void setClienteEnd(Cliente** c, Endereco* end){
  (*c)->end = construtorEndereco1(end);
}

void printCliente(Cliente* c){
  if(c != NULL){
    printf("Nome: %s\n", c->nome);
    printf("Sobrenome: %s\n", c->sobrenome);
    printf("RG: %s\n", c->rg);
    printf("CPF: %s\n", c->cpf);
    printf("Data de nascimento: ");
    printData(c->dataNasc);
    printf("\nEndereço: \n");
    printEndereco(c->end);
  } else {
   printf("NULL");
  }
}