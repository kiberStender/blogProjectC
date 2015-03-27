#ifndef CLIENTE_H
#define CLIENTE_H

#include <string.h>

typedef struct Cliente {
  char nome[20];
  char sobrenome[20];
  char rg[20];
  char cpf[20];
  char dataNasc[15];
} Cliente;

Cliente ClienteConstrutor(char[20], char[20], char[20], char[20], char[15]);

int equalsCliente(Cliente, Cliente);

#endif
