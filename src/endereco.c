#include "../header/endereco.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Endereco construtorEndereco(
  char cep[], char num[], char rua[], char bairro[],
        char cidade[], char estado[], char pais[]){
  Endereco end;
  
  end.cep = (char*) calloc(strlen(cep), sizeof(char));
  strcpy(end.cep, cep);
  
  end.num = (char*) calloc(strlen(num), sizeof(char));
  strcpy(end.num, num);
  
  end.rua = (char*) calloc(strlen(rua), sizeof(char));
  strcpy(end.rua, rua);
  
  end.bairro = (char*) calloc(strlen(bairro), sizeof(char));
  strcpy(end.bairro, bairro);
  
  end.cidade = (char*) calloc(strlen(cidade), sizeof(char));
  strcpy(end.cidade, cidade);
  
  end.estado = (char*) calloc(strlen(estado), sizeof(char));
  strcpy(end.estado, estado);
  
  end.pais = (char*) calloc(strlen(pais), sizeof(char));
  strcpy(end.pais, pais);
  
  return end;
}

Endereco construtorEndereco1(Endereco e){
  return construtorEndereco(e.cep, e.num, e.rua, e.bairro, e.cidade, e.estado, e.pais);
}

int enderecoEquals(Endereco a, Endereco b){
  if(strncmp(a.cep, b.cep, 15) != 0){
    return 0;
  }
  return 1;
}

void setEnderecoCep(Endereco* e, char* cep){
  free(e->cep);
  e->cep = (char*) calloc(strlen(cep), sizeof(char));
  strcpy(e->cep, cep);
}

void setEnderecoNum(Endereco* e, char* num){
  free(e->num);
  e->num = (char*) calloc(strlen(num), sizeof(char));
  strcpy(e->num, num);
}

void setEnderecoRua(Endereco* e, char* rua){
  free(e->rua);
  e->rua = (char*) calloc(strlen(rua), sizeof(char));
  strcpy(e->rua, rua);
}

void setEnderecoBairro(Endereco* e, char* bairro){
  free(e->bairro);
  e->bairro = (char*) calloc(strlen(bairro), sizeof(char));
  strcpy(e->bairro, bairro);
}

void setEnderecoCidade(Endereco* e, char* cidade){
  free(e->cidade);
  e->cidade = (char*) calloc(strlen(cidade), sizeof(char));
  strcpy(e->cidade, cidade);  
}

void setEnderecoEstado(Endereco* e, char* estado){
  free(e->estado);
  e->estado = (char*) calloc(strlen(estado), sizeof(char));
  strcpy(e->estado, estado);
}

void setEnderecoPais(Endereco* e, char* pais){
  free(e->pais);
  e->pais = (char*) calloc(strlen(pais), sizeof(char));
  strcpy(e->pais, pais);
}

void printEndereco(Endereco end){
  printf("CEP: %s\n", end.cep);
  printf("Numero da casa: %s\n", end.cep);
  printf("Rua: %s\n", end.rua);
  printf("Bairro: %s\n", end.bairro);
  printf("Cidade: %s\n", end.cidade);
  printf("Estado: %s\n", end.estado);
  printf("Pais: %s\n", end.pais);
}

void freeEndereco(Endereco* end){
  
  free(end->cep);
  end->cep = NULL;
  
  free(end->num);
  end->num = NULL;
  
  free(end->rua);
  end->rua = NULL;
  
  free(end->bairro);
  end->bairro = NULL;
  
  free(end->cidade);
  end->cidade = NULL;
  
  free(end->estado);
  end->estado = NULL;
  
  free(end->pais);
  end->pais = NULL;  
}