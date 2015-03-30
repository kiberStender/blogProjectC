#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "data.h"
#include "endereco.h"

typedef struct Funcionario {
  char *nome;
  char *sobrenome;
  char *rg;
  char *cartTrab;
  Data dataNasc;
  Endereco end;
} Funcionario;

Funcionario* construtorFuncionario(char[], char[], char[], char[], Data, Endereco);

int equalsFuncionario(Funcionario, Funcionario);

void setFuncionarioNome(Funcionario*, char*);

void setFuncionarioSobrenome(Funcionario*, char*);

void setFuncionarioRG(Funcionario*, char*);

void setFuncionarioCartTrab(Funcionario*, char*);

void setFuncionarioDataNasc(Funcionario*, Data);

void setFuncionarioEnd(Funcionario*, Endereco);

void printFuncionario(Funcionario);

void freeFuncionario(Funcionario*);

#endif
