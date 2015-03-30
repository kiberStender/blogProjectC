#ifndef ENDERECO_H
#define ENDERECO_H

#include <string.h>
#include <stdio.h>

typedef struct Endereco{
  char *cep;
  char *num;
  char *rua;
  char *bairro;
  char *cidade;
  char *estado;
  char *pais;
} Endereco;

Endereco construtorEndereco(char[], char[], char[], char[], char[], char[], char[]);

Endereco construtorEndereco1(Endereco);

int enderecoEquals(Endereco, Endereco);

void setEnderecoCep(Endereco*, char*);

void setEnderecoNum(Endereco*, char*);

void setEnderecoRua(Endereco*, char*);

void setEnderecoBairro(Endereco*, char*);

void setEnderecoCidade(Endereco*, char*);

void setEnderecoEstado(Endereco*, char*);

void setEnderecoPais(Endereco*, char*);

void printEndereco(Endereco);

void freeEndereco(Endereco*);

#endif
