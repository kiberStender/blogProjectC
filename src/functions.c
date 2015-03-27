#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/
#include "../header/functions.h"

void desenhaMenu1(){
  /*Para limpar a tela usando uma chamada do próprio sistema operacional
   *Vem da lib stdlib.h
   */
  system(CLEAR);

  printf("\nEscolha uma das opcoes abaixo\n");
  printf("1- Clientes\n");
  printf("2- Funcionarios\n");
  printf("3- Sair do programa\n");
  printf("Digite aqui: ");
}

void desenhaMenu2(char modulo[15]){
  char emMaiusculo[15];
  strcpy(emMaiusculo, modulo);
  emMaiusculo[0] = toupper(emMaiusculo[0]);

  system(CLEAR);
  printf("\n%ss\n", emMaiusculo);
  printf("\t1- Cadastrar novo %s\n", modulo);
  printf("\t2- Remover %s\n", modulo);
  printf("\t3- Atualizar dados de %s\n", modulo);
  printf("\t4- Ver dados de %s\n", modulo);
  printf("\t5- Sair de %ss\n", emMaiusculo);
  printf("Digite aqui: ");
}
