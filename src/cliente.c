#include "../header/cliente.h"
#include <string.h>
#include <stdlib.h>

Cliente* construtorCliente(
  char nome[], char sobrenome[], char rg[], char cpf[], Data dataNasc, Endereco end){
  Cliente* c = (Cliente*) calloc(1, sizeof(Cliente));
  
  c->nome = (char*) calloc(strlen(nome), sizeof(char));
  strcpy(c->nome, nome);
  
  c->sobrenome = (char*) calloc(strlen(sobrenome), sizeof(char));
  strcpy(c->sobrenome, sobrenome);
  
  c->rg = (char*) calloc(strlen(rg), sizeof(char));
  strcpy(c->rg, rg);
  
  c->cpf = (char*) calloc(strlen(cpf), sizeof(char));
  strcpy(c->cpf, cpf);
  
  c->dataNasc = construtorData2(dataNasc);
  c->end = construtorEndereco1(end);
  
  return c;
}

int equalsCliente(Cliente a, Cliente b){
  if(strncmp(a.rg, b.rg, strlen(a.rg)) != 0){
    return 0;
  } else if(strncmp(a.cpf, b.cpf, 20) != 0){
    return 0;
  } else {
    return 1;
  }
}

void setClienteNome(Cliente* c, char* nome){
  free(c->nome);
  c->nome = (char*) calloc(strlen(nome), sizeof(char));
  strcpy(c->nome, nome);  
}

void setClienteSobrenome(Cliente* c, char* sobrenome){
  free(c->sobrenome);
  c->sobrenome = (char*) calloc(strlen(sobrenome), sizeof(char));
  strcpy(c->sobrenome, sobrenome);  
}

void setClienteRG(Cliente* c, char* rg){
  free(c->rg);
  c->rg = (char*) calloc(strlen(rg), sizeof(char));
  strcpy(c->rg, rg);
}

void setClienteCpf(Cliente* c, char* cpf){
  free(c->cpf);
  c->cpf = (char*) calloc(strlen(cpf), sizeof(char));
  strcpy(c->cpf, cpf);  
}

void setClienteDataNasc(Cliente* c, Data d){
  c->dataNasc = d;
}

void setClienteEnd(Cliente* c, Endereco end){
  c->end = end;
}

void printCliente(Cliente c){
  printf("Nome: %s\n", c.nome);
  printf("Sobrenome: %s\n", c.sobrenome);
  printf("RG: %s\n", c.rg);
  printf("CPF: %s\n", c.cpf);
  printf("Data de nascimento: ");
  printData(c.dataNasc);
  printf("\nEndereço: \n");
  printEndereco(c.end);
}

void freeCliente(Cliente* c){
  freeData(&c->dataNasc);
  freeEndereco(&c->end);
  
  free(c->nome);
  c->nome = NULL;
  
  free(c->sobrenome);
  c->sobrenome = NULL;
  
  free(c->rg);
  c->rg = NULL;
  
  free(c->cpf);
  c->cpf = NULL;
  
  free(c);
  c = NULL;
}


