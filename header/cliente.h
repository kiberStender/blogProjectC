#ifndef CLIENTE_H
#define CLIENTE_H

#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "endereco.h"
#include "cliente.h"

typedef struct Cliente {
  char *nome;
  char *sobrenome;
  char *rg;
  char *cpf;
  Data dataNasc;
  Endereco end;
} Cliente;

Cliente* construtorCliente(char[], char[], char[], char[], Data, Endereco);

int equalsCliente(Cliente, Cliente);

void setClienteNome(Cliente*, char*);

void setClienteSobrenome(Cliente*, char*);

void setClienteRG(Cliente*, char*);

void setClienteCpf(Cliente*, char*);

void setClienteDataNasc(Cliente*, Data);

void setClienteEnd(Cliente*, Endereco);

void printCliente(Cliente);

void freeCliente(Cliente*);

#endif
