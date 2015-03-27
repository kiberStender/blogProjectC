#include "../header/cliente.h"
#include <string.h>

Cliente ClienteConstrutor(
  char nome[20], char sobrenome[20], char rg[20], char cpf[20], char dataNasc[15]
){
  Cliente c;
  
  strcpy(c.nome, nome);
  strcpy(c.sobrenome, sobrenome);
  strcpy(c.rg, rg);
  strcpy(c.cpf, cpf);
  strcpy(c.dataNasc, dataNasc);
  
  return c;
}

int equalsCliente(Cliente a, Cliente b){
  if(strncmp(a.rg, b.rg, 20) != 0){
    return 0;
  } else if(strncmp(a.cpf, b.cpf, 20) != 0){
    return 0;
  } else {
    return 1;
  }
}
