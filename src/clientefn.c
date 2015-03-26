#include "../header/clientefn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

int iteratorCli = 0;

/*Acoes com cliente*/
void cadastraCliente(){
  system(CLEAR);
  
  if(iteratorCli < MAXREG){
  
    printf("Digite o nome do cliente: ");
    scanf("%s", nomeCli[iteratorCli]); /*Pegando o nome do sujeito*/
  
    printf("Digite o sobrenome do cliente: ");
    scanf("%s", sobrenomeCli[iteratorCli]); /*Pegando o sobrenome do sujeito*/
  
    printf("Digite o RG do cliente: ");
    scanf("%s", rgCli[iteratorCli]); /*Pegando o rg do sujeito*/
  
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf[iteratorCli]); /*Pegando o cpf do sujeito*/
  
    printf("Digite a data de nascimento do cliente: ");
    scanf("%s", datanascCli[iteratorCli]); /*Pegando o datanasc do sujeito*/

    iteratorCli = iteratorCli + 1;
    /*iteratorCli++; se preferir*/

  } else {
    printf(msg);
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
    strcpy(nomeCli[j], nomeCli[j + 1]);
    strcpy(nomeCli[j + 1], "!");
        
    strcpy(sobrenomeCli[j], sobrenomeCli[j + 1]);
    strcpy(sobrenomeCli[j + 1], "!");
        
    strcpy(rgCli[j], rgCli[j + 1]);
    strcpy(rgCli[j + 1], "!");
        
    strcpy(cpf[j], cpf[j + 1]);
    strcpy(cpf[j + 1], "!");
        
    strcpy(datanascCli[j], datanascCli[j + 1]);
    strcpy(datanascCli[j + 1], "!");
  }
      
  printf(msg3);
  iteratorCli = iteratorCli - 1;
  /*iteratorCli--; se preferir*/
}

void atualizaCliente(int posicao){
  char nome[20], sNome[20], rg[20], cpf_[20], dtNasc[15];
  
  printf("Dados originais \n\n");
  printf("Nome: %s \n", nomeCli[posicao]);/*Nome*/
  printf("Sobrenome: %s \n", sobrenomeCli[posicao]);/*Sobrenome*/
  printf("RG: %s \n", rgCli[posicao]);/*RG*/
  printf("CPF: %s \n", cpf[posicao]);/*CPF*/
  /*Data de nascimento*/
  printf("Data de nascimento: %s \n", datanascCli[posicao]);
      
  printf("\n\nPara manter o mesmo valor digite _ \n\n");
      
  printf("Digite um novo valor para o nome: ");
  scanf("%s", nome);
  printf("Digite um novo valor para o sobrenome: ");
  scanf("%s", sNome);
  printf("Digite um novo valor para o rg: ");
  scanf("%s", rg);
  printf("Digite um novo valor para o cpf: ");
  scanf("%s", cpf_);
  printf("Digite um novo valor para o data de nascimento: ");
  scanf("%s", dtNasc);

  if(strncmp(nome, "_", 1) != 0){
    strcpy(nomeCli[posicao], nome);
  }
  if(strncmp(sNome, "_", 1) != 0){
    strcpy(sobrenomeCli[posicao], sNome);
  }
  if(strncmp(rg, "_", 1) != 0){
    strcpy(rgCli[posicao], rg);
  }
  if(strncmp(cpf_, "_", 1) != 0){
    strcpy(cpf[posicao], cpf_);
  }
  if(strncmp(dtNasc, "_", 1) != 0){
    strcpy(datanascCli[posicao], dtNasc);
  }
}

void verCliente(int posicao){
  printf("Nome: %s \n", nomeCli[posicao]);/*Nome*/
  printf("Sobrenome: %s \n", sobrenomeCli[posicao]);/*Sobrenome*/
  printf("RG: %s \n", rgCli[posicao]);/*RG*/
  printf("CPF: %s \n", cpf[posicao]);/*CPF*/
  /*Data de nascimento*/
  printf("Data de nascimento: %s \n", datanascCli[posicao]);
  system(PAUSE);
}
