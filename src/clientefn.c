#include "../header/clientefn.h"
#include "../header/cliente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

int iteratorCli = 0;

/*Acoes com cliente*/
int buscaCliente(Cliente clis[MAXREG], char rg[20]){
  int i;

  for(i = 0; i < MAXREG; i++){
    if(strncmp(clis[i].rg, rg, 20) == 0){
      return i;
    }
  }
  return -1;
}

int existeCliente(Cliente clis[MAXREG], Cliente c){
  int i;

  for(i = 0; i < MAXREG; i++){
    if(equalsCliente(clis[i], c)){
      return i;
    }
  }
  return -1;
}

void cadastraCliente(){
  system(CLEAR);
  
  if(iteratorCli < MAXREG){
    char nome[20], sobrenome[20], rg[20], cpf[20], dataNasc[15];
  
    printf("Digite o nome do cliente: ");
    scanf("%s", nome); /*Pegando o nome do sujeito*/
  
    printf("Digite o sobrenome do cliente: ");
    scanf("%s", sobrenome); /*Pegando o sobrenome do sujeito*/
  
    printf("Digite o RG do cliente: ");
    scanf("%s", rg); /*Pegando o rg do sujeito*/
  
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf); /*Pegando o cpf do sujeito*/
  
    printf("Digite a data de nascimento do cliente: ");
    scanf("%s", dataNasc); /*Pegando o datanasc do sujeito*/
    
    Cliente c = ClienteConstrutor(nome, sobrenome, rg, cpf, dataNasc);
    
    if(existeCliente(clientes, c) > -1){
      printf("Cliente já existente");
    } else {
      clientes[iteratorCli] = c;

      iteratorCli = iteratorCli + 1;
      /*iteratorCli++; se preferir*/
    }

  } else {
    printf(MSG);
  }
}

void deleteCliente(int posicao){
  int j;
      
  /*Se soh apagarmos e deixamos por isso mesmo, uma hora nao teremos
   * onde guardar, porque estaremos cheio de buracos no array
   * Esse for retira o buraco feito pelo ato de apagar, deixando os
   * espacos vazios para o fim do array
   */
  for(j = posicao; j < MAXREG; j++){
    
    clientes[j] = clientes[j + 1];
    //clientes[j + 1] = NULL;
  }
      
  printf(MSG3);
  iteratorCli = iteratorCli - 1;
  /*iteratorCli--; se preferir*/
}

void atualizaCliente(int posicao){
  char nome[20], sNome[20], rg[20], cpf[20], dtNasc[15];
  
  printf("Dados originais \n\n");
  printf("Nome: %s \n", clientes[posicao].nome);/*Nome*/
  printf("Sobrenome: %s \n", clientes[posicao].sobrenome);/*Sobrenome*/
  printf("RG: %s \n", clientes[posicao].rg);/*RG*/
  printf("CPF: %s \n", clientes[posicao].cpf);/*CPF*/
  /*Data de nascimento*/
  printf("Data de nascimento: %s \n", clientes[posicao].dataNasc);
      
  printf("\n\nPara manter o mesmo valor digite _ \n\n");
      
  printf("Digite um novo valor para o nome: ");
  scanf("%s", nome);
  printf("Digite um novo valor para o sobrenome: ");
  scanf("%s", sNome);
  printf("Digite um novo valor para o rg: ");
  scanf("%s", rg);
  printf("Digite um novo valor para o cpf: ");
  scanf("%s", cpf);
  printf("Digite um novo valor para o data de nascimento: ");
  scanf("%s", dtNasc);

  if(strncmp(nome, "_", 1) != 0){
    strcpy(clientes[posicao].nome, nome);
  }
  if(strncmp(sNome, "_", 1) != 0){
    strcpy(clientes[posicao].sobrenome, sNome);
  }
  if(strncmp(rg, "_", 1) != 0){
    strcpy(clientes[posicao].rg, rg);
  }
  if(strncmp(cpf, "_", 1) != 0){
    strcpy(clientes[posicao].cpf, cpf);
  }
  if(strncmp(dtNasc, "_", 1) != 0){
    strcpy(clientes[posicao].dataNasc, dtNasc);
  }
}

void verCliente(int posicao){
  printf("Nome: %s \n", clientes[posicao].nome);/*Nome*/
  printf("Sobrenome: %s \n", clientes[posicao].sobrenome);/*Sobrenome*/
  printf("RG: %s \n", clientes[posicao].rg);/*RG*/
  printf("CPF: %s \n", clientes[posicao].cpf);/*CPF*/
  /*Data de nascimento*/
  printf("Data de nascimento: %s \n", clientes[posicao].dataNasc);
  system(PAUSE);
}
