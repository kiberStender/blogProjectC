#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

/*Máximo de registros que nosso programa irá guardar*/
#define MAXREG 10

/*Se estiver no Windows mude para cls*/
#define CLEAR "clear"

/*Se estiver no Windows mude para pause*/
#define PAUSE "read -p \"Pressione enter para sair...\""

int buscaRG(char rgs[MAXREG][20], char rg[20]){
  int i;

  for(i = 0; i < MAXREG; i++){
    if(strncmp(rgs[i], rg, 20) == 0){
      return i;
    }
  }
  return -1;
}

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

int main(){
  int opMenu1;
  /*Variaveis de cliente*/
  char nomeCli[MAXREG][20], sobrenomeCli[MAXREG][20], rgCli[MAXREG][20],
    cpf[MAXREG][20], datanascCli[MAXREG][15];
  /*A cada registro adicionado, iterator aumenta seu valor em 1
   * e a cada registro removido, diminui seu valor em 1
   */
  int iteratorCli = 0;

  /*Variaveis de funcionario*/
  char nomeFun[MAXREG][20], sobrenomeFun[MAXREG][20], rgFun[MAXREG][20],
    cartTrab[MAXREG][20], datanascFun[MAXREG][15];
  /*A cada registro adicionado, iterator aumenta seu valor em 1
   * e a cada registro removido, diminui seu valor em 1
   */
  int iteratorFun = 0;

  desenhaMenu1();
  scanf("%i", &opMenu1);

  do {
    char msg[] = "Máximo de registros permitidos já cheio!!!";
    char msg1[] = "Não existem registros!!!";
    char msg2[] = "O registro que buscas nao existe.";
    char msg3[] = "Removido com sucesso!!!";
    int opMenuCli, opMenuFun;

    switch(opMenu1){
      case 1:
        desenhaMenu2("cliente");
        scanf("%i", &opMenuCli);

        do {
          switch(opMenuCli){
            case 1:
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
              break;
            case 2:
              system(CLEAR);

              if(iteratorCli > 0){
                char tempRg[20];
                int posicao;

                printf("Digite o RG do cliente: ");
                /*Guardando numa variavel temporaria*/
                scanf("%s", tempRg);

                /*Buscar o cliente a ser apagado*/
                posicao = buscaRG(rgCli, tempRg);
                /*Busca terminada*/

                if(posicao > -1){
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
                } else {
                  printf(msg2);
                }

              } else {
                printf(msg1);
              }
              break;
            case 3:
              system(CLEAR);

              if(iteratorCli > 0){
                char tempRg[20];
                int posicao;

                printf("Digite o RG do cliente: ");
                /*Guardando numa variavel temporaria*/
                scanf("%s", tempRg);

                /*Buscar o funcionario a ser apagado*/
                posicao = buscaRG(rgCli, tempRg);
                /*Busca terminada*/

                if(posicao > -1){
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

                } else {
                  printf(msg2);
                }
              } else {
                printf(msg1);
              }
              break;
            case 4:
              system(CLEAR);

              if(iteratorCli > 0){
                char tempRg[20];
                int posicao;

                printf("Digite o RG do cliente: ");
                /*Guardando numa variavel temporaria*/
                scanf("%s", tempRg);

                /*Buscar o funcionario a ser apagado*/
                posicao = buscaRG(rgCli, tempRg);
                /*Busca terminada*/

                if(posicao > -1){
                  printf("Nome: %s \n", nomeCli[posicao]);/*Nome*/
                  printf("Sobrenome: %s \n", sobrenomeCli[posicao]);/*Sobrenome*/
                  printf("RG: %s \n", rgCli[posicao]);/*RG*/
                  printf("CPF: %s \n", cpf[posicao]);/*CPF*/
                  /*Data de nascimento*/
                  printf("Data de nascimento: %s \n", datanascCli[posicao]);
                  system(PAUSE);
                } else {
                  printf(msg2);
                }
              } else {
                printf(msg1);
              }
              break;
            case 6:
              /*Bonus para imprimir todos os dados do array*/
              if(iteratorCli > 0){
                int j;
                for(j = 0; j < MAXREG; j++){
                  printf("Nome: %s \n", nomeCli[j]);/*Nome*/
                  printf("Sobrenome: %s \n", sobrenomeCli[j]);/*Sobrenome*/
                  printf("RG: %s \n", rgCli[j]);/*RG*/
                  printf("CPF: %s \n", cpf[j]);/*CPF*/
                  /*Data de nascimento*/
                  printf("Data de nascimento: %s \n\n\n", datanascCli[j]);
                }
                system(PAUSE);
              } else {
                printf("Nenhum registro");
              }
              break;
          }

          opMenuCli = 0; /*Impedir que volte ao menu que ja estava*/

          desenhaMenu2("cliente");
          scanf("%i", &opMenuCli);

        } while(opMenuCli != 5);
        break;
      case 2:
        desenhaMenu2("funcionario");
        scanf("%i", &opMenuFun);

        do {
          switch(opMenuFun){
            case 1:
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
              break;
            case 2:
              if(iteratorFun > 0){
                char tempRg[20];
                int posicao;

                printf("Digite o RG do funcionario: ");
                /*Guardando numa variavel temporaria*/
                scanf("%s", tempRg);

                /*Buscar o funcionario a ser apagado*/
                posicao = buscaRG(rgFun, tempRg);
                /*Busca terminada*/

                if(posicao > -1){
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
                } else {
                  printf(msg2);
                }

              } else {
                printf(msg1);
              }
              break;
            case 3:
              system(CLEAR);

              if(iteratorFun > 0){
                char tempRg[20];
                int posicao;

                printf("Digite o RG do cliente: ");
                /*Guardando numa variavel temporaria*/
                scanf("%s", tempRg);

                /*Buscar o funcionario a ser apagado*/
                posicao = buscaRG(rgFun, tempRg);
                /*Busca terminada*/

                if(posicao > -1){
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
                    strcpy(nomeCli[posicao], nome);
                  }
                  if(strncmp(sNome, "_", 1) != 0){
                    strcpy(sobrenomeCli[posicao], sNome);
                  }
                  if(strncmp(rg, "_", 1) != 0){
                    strcpy(rgCli[posicao], rg);
                  }
                  if(strncmp(cartTrab_, "_", 1) != 0){
                    strcpy(cartTrab[posicao], cartTrab_);
                  }
                  if(strncmp(dtNasc, "_", 1) != 0){
                    strcpy(datanascCli[posicao], dtNasc);
                  }

                } else {
                  printf(msg2);
                }
              } else {
                printf(msg1);
              }
              break;
            case 4:
              system(CLEAR);

              if(iteratorFun > 0){
                char tempRg[20];
                int posicao;

                printf("Digite o RG do funcionario: ");
                /*Guardando numa variavel temporaria*/
                scanf("%s", tempRg);

                /*Buscar o funcionario a ser apagado*/
                posicao = buscaRG(rgFun, tempRg);
                /*Busca terminada*/

                if(posicao > -1){
                  printf("Nome: %s \n", nomeFun[posicao]);/*Nome*/
                  printf("Sobrenome: %s \n", sobrenomeFun[posicao]);/*Sobrenome*/
                  printf("RG: %s \n", rgFun[posicao]);/*RG*/
                  printf("CPF: %s \n", cartTrab[posicao]);/*CPF*/
                  /*Data de nascimento*/
                  printf("Data de nascimento: %s \n", datanascFun[posicao]);
                  system(PAUSE);
                } else {
                  printf(msg2);
                }
              } else {
                printf(msg1);
              }
              break;
          }

          opMenuFun = 0; /*Prevenir que volte ao menu que ja estava*/
          desenhaMenu2("funcionario");
          scanf("%i", &opMenuFun);

        } while(opMenuFun != 5);
        break;
    }

    opMenu1 = 0; /*Para prevenir que volte a menu que estava*/

    desenhaMenu1();
    scanf("%i", &opMenu1);
  } while(opMenu1 != 3);

  system(CLEAR);
  return 0;
}
