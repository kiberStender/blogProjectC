#include "../header/funcionariofn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

int iteratorFun = 0;

/*Acoes com funcionario*/
void cadastraFuncionario(){
  system(CLEAR);
  
  if(iteratorFun < MAXREG){
    printf("Digite o nome do funcionario: ");
    scanf("%s", nomeFun[iteratorFun]); /*Pegando o nome do sujeito*/
    
    printf("Digite o sobrenome do funcionario: ");
    scanf("%s", sobrenomeFun[iteratorFun]); /*Pegando o sobrenome do sujeito*/
    
    printf("Digite o RG do funcionario: ");
    scanf("%s", rgFun[iteratorFun]); /*Pegando o rg do sujeito*/
    
    printf("Digite o numero da carteira de trabalho do funcionario: ");
    scanf("%s", cartTrab[iteratorFun]); /*Pegando o cpf do sujeito*/
    
    printf("Digite a data de nascimento do funcionario: ");
    scanf("%s", datanascFun[iteratorFun]); /*Pegando o datanasc do sujeito*/
    
    iteratorFun = iteratorFun + 1;
    
    /*iteratorFun++ se preferir*/
  } else {
    printf(msg);
  }
}

void deleteFuncionario(int posicao){
  int j;
      
  /*Se soh apagarmos e deixamos por isso mesmo, uma hora nao teremos
   * onde guardar, porque estaremos cheio de buracos no array
   * Esse for retira o buraco feito pelo ato de apagar, deixando os
   * espacos vazios para o fim do array
   */
  for(j = posicao; j < MAXREG; j++){
    strcpy(nomeFun[j], nomeFun[j + 1]);
    strcpy(nomeFun[j + 1], "!");
        
    strcpy(sobrenomeFun[j], sobrenomeFun[j + 1]);
    strcpy(sobrenomeFun[j + 1], "!");
        
    strcpy(rgFun[j], rgFun[j + 1]);
    strcpy(rgFun[j + 1], "!");
        
    strcpy(cartTrab[j], cartTrab[j + 1]);
    strcpy(cartTrab[j + 1], "!");
        
    strcpy(datanascFun[j], datanascFun[j + 1]);
    strcpy(datanascFun[j + 1], "!");
  }
   
  iteratorFun = iteratorFun - 1;
  /*iteratorFun--; se preferir*/
}

void atualizaFuncionario(int posicao){
  char nome[20], sNome[20], rg[20], cartTrab_[20], dtNasc[15];
      
  printf("Dados originais \n\n");
  printf("Nome: %s \n", nomeFun[posicao]);/*Nome*/
  printf("Sobrenome: %s \n", sobrenomeFun[posicao]);/*Sobrenome*/
  printf("RG: %s \n", rgFun[posicao]);/*RG*/
  printf("Carteira de trabalho: %s \n", cartTrab[posicao]);/*CartTrab*/
  /*Data de nascimento*/
  printf("Data de nascimento: %s \n", datanascFun[posicao]);
  printf("\n\nPara manter o mesmo valor digite _ \n\n");
      
  printf("Digite um novo valor para o nome: ");
  scanf("%s", nome);
  printf("Digite um novo valor para o sobrenome: ");
  scanf("%s", sNome);
  printf("Digite um novo valor para o rg: ");
  scanf("%s", rg);
  printf("Digite um novo valor para a carteira de trabalho: ");
  scanf("%s", cartTrab_);
  printf("Digite um novo valor para o data de nascimento: ");
  scanf("%s", dtNasc);
      
  if(strncmp(nome, "_", 1) != 0){
    strcpy(nomeFun[posicao], nome);
  }
  if(strncmp(sNome, "_", 1) != 0){
    strcpy(sobrenomeFun[posicao], sNome);
  }
  if(strncmp(rg, "_", 1) != 0){
    strcpy(rgFun[posicao], rg);
  }
  if(strncmp(cartTrab_, "_", 1) != 0){
    strcpy(cartTrab[posicao], cartTrab_);
  }
  if(strncmp(dtNasc, "_", 1) != 0){
    strcpy(datanascFun[posicao], dtNasc);
  }
}

void verFuncionario(int posicao){
  printf("Nome: %s \n", nomeFun[posicao]);/*Nome*/
  printf("Sobrenome: %s \n", sobrenomeFun[posicao]);/*Sobrenome*/
  printf("RG: %s \n", rgFun[posicao]);/*RG*/
  printf("CPF: %s \n", cartTrab[posicao]);/*CPF*/
  /*Data de nascimento*/
  printf("Data de nascimento: %s \n", datanascFun[posicao]);
  system(PAUSE);
}
