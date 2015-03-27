#include "../header/funcionariofn.h"
#include "../header/funcionario.h"
#include "../header/functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

int iteratorFun = 0;

/*Acoes com funcionario*/
int buscaFuncionario(Funcionario funs[MAXREG], char rg[20]){
  int i;

  for(i = 0; i < MAXREG; i++){
    if(strncmp(funs[i].rg, rg, 20) == 0){
      return i;
    }
  }
  return -1;
}

void cadastraFuncionario(){
  system(CLEAR);
  
  if(iteratorFun < MAXREG){
    char nome[20], sobrenome[20], rg[20], cartTrab[20], dataNasc[15];       
    
    printf("Digite o nome do funcionario: ");
    scanf("%s", nome); /*Pegando o nome do sujeito*/
    
    printf("Digite o sobrenome do funcionario: ");
    scanf("%s", sobrenome); /*Pegando o sobrenome do sujeito*/
    
    printf("Digite o RG do funcionario: ");
    scanf("%s", rg); /*Pegando o rg do sujeito*/
    
    printf("Digite o numero da carteira de trabalho do funcionario: ");
    scanf("%s", cartTrab); /*Pegando o cpf do sujeito*/
    
    printf("Digite a data de nascimento do funcionario: ");
    scanf("%s", dataNasc); /*Pegando o datanasc do sujeito*/
    
    funcionarios[iteratorFun] = FuncionarioConstrutor(nome, sobrenome, rg, cartTrab, dataNasc);
    
    iteratorFun++;
  } else {
    printf(MSG);
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
  
    funcionarios[j] = funcionarios[j + 1];
    
    //funcionarios[j + 1] = NULL;
  }
   
  iteratorFun--;
}

void atualizaFuncionario(int posicao){
  char nome[20], sNome[20], rg[20], cartTrab[20], dtNasc[15];
      
  printf("Dados originais \n\n");
  printf("Nome: %s \n", funcionarios[posicao].nome);/*Nome*/
  printf("Sobrenome: %s \n", funcionarios[posicao].sobrenome);/*Sobrenome*/
  printf("RG: %s \n", funcionarios[posicao].rg);/*RG*/
  printf("Carteira de trabalho: %s \n", funcionarios[posicao].cartTrab);/*CartTrab*/
  /*Data de nascimento*/
  printf("Data de nascimento: %s \n", funcionarios[posicao].dataNasc);
  printf("\n\nPara manter o mesmo valor digite _ \n\n");
      
  printf("Digite um novo valor para o nome: ");
  scanf("%s", nome);
  printf("Digite um novo valor para o sobrenome: ");
  scanf("%s", sNome);
  printf("Digite um novo valor para o rg: ");
  scanf("%s", rg);
  printf("Digite um novo valor para a carteira de trabalho: ");
  scanf("%s", cartTrab);
  printf("Digite um novo valor para o data de nascimento: ");
  scanf("%s", dtNasc);
      
  if(strncmp(nome, "_", 1) != 0){
    strcpy(funcionarios[posicao].nome, nome);
  }
  if(strncmp(sNome, "_", 1) != 0){
    strcpy(funcionarios[posicao].sobrenome, sNome);
  }
  if(strncmp(rg, "_", 1) != 0){
    strcpy(funcionarios[posicao].rg, rg);
  }
  if(strncmp(cartTrab, "_", 1) != 0){
    strcpy(funcionarios[posicao].cartTrab, cartTrab);
  }
  if(strncmp(dtNasc, "_", 1) != 0){
    strcpy(funcionarios[posicao].dataNasc, dtNasc);
  }
}

void verFuncionario(int posicao){
  printf("Nome: %s \n", funcionarios[posicao].nome);/*Nome*/
  printf("Sobrenome: %s \n", funcionarios[posicao].sobrenome);/*Sobrenome*/
  printf("RG: %s \n", funcionarios[posicao].rg);/*RG*/
  printf("CPF: %s \n", funcionarios[posicao].cartTrab);/*CPF*/
  /*Data de nascimento*/
  printf("Data de nascimento: %s \n", funcionarios[posicao].dataNasc);
  system(PAUSE);
}
