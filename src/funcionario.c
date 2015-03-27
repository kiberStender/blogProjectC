#include "../header/funcionario.h"
#include <string.h>

Funcionario FuncionarioConstrutor(
  char nome[20], char sobrenome[20], char rg[20], char cartTrab[20], char dataNasc[15]
){
  Funcionario f;
  
  strcpy(f.nome, nome);
  strcpy(f.sobrenome, sobrenome);
  strcpy(f.rg, rg);
  strcpy(f.cartTrab, cartTrab);
  strcpy(f.dataNasc, dataNasc);
  
  return f;
}
