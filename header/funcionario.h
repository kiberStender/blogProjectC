#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct Funcionario {
  char nome[20];
  char sobrenome[20];
  char rg[20];
  char cartTrab[20];
  char dataNasc[15];
} Funcionario;

Funcionario FuncionarioConstrutor(char[20], char[20], char[20], char[20], char[15]);

#endif
