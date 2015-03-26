#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/
//Kleber

/*Máximo de registros que nosso programa irá guardar*/
#define MAXREG 10

/*Se estiver no Windows mude para cls*/
#define CLEAR "clear"

/*Se estiver no Windows mude para pause*/
#define PAUSE "read -p \"Pressione enter para sair...\""

/*
 * Mensagens do sistema
 */
#define msg  "Máximo de registros permitidos já cheio!!!"
#define msg1 "Não existem registros!!!"
#define msg2 "O registro que buscas nao existe."
#define msg3 "Removido com sucesso!!!"

/*funcoes que independem de modulo*/
int buscaRG(char[MAXREG][20], char[20]);
void desenhaMenu1();
void desenhaMenu2(char[15]);

/*Acoes com cliente*/
void cadastraCliente();
void deleteCliente();
void atualizaCliente();
void verCliente();

/*Acoes com funcionario*/
void cadastraFuncionario();
void deleteFuncionario();
void atualizaFuncionario();
void verFuncionario();

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

int main(int argc, char **argv){
  int opMenu1;
  
  desenhaMenu1();
  scanf("%i", &opMenu1);
  
  do {
    int opMenuCli, opMenuFun;
    
    switch(opMenu1){
      case 1:
        desenhaMenu2("cliente");
        scanf("%i", &opMenuCli);
        
        do{
          switch(opMenuCli){
            case 1:
                cadastraCliente();
              break;
            case 2:
                deleteCliente();
              break;
            case 3:
              atualizaCliente();
              break;
            case 4:
              verCliente();
              break;
          }
        } while(opMenuCli != 5);
        break;
      case 2:
        desenhaMenu2("funcionario");
        scanf("%i", &opMenuFun);
        
        do{
          switch(opMenuFun){
            case 1:
              cadastraFuncionario();
              break;
            case 2:
              deleteFuncionario();
              break;
            case 3:
              atualizaFuncionario();
              break;
            case 4:
              verFuncionario();
              break;
          }
        } while(opMenuFun != 5);
        break;
    }
    
    opMenu1 = 0; /*Para prevenir que volte a menu que estava*/
    
    if(opMenu1 != 3){
      desenhaMenu1();
      scanf("%i", &opMenu1);
    }
  } while(opMenu1 != 3);
  
  system(CLEAR);
  
  return 0;
}

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
void deleteCliente(){
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
}

void atualizaCliente(){
  system(CLEAR);
  
  if(iteratorCli > 0){
    char tempRg[20];
    int posicao;
    
    printf("Digite o RG do cliente: ");
    /*Guardando numa variavel temporaria*/
    scanf("%s", tempRg);
    
    /*Buscar o cliente a ser atualizado*/
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
}

void verCliente(){
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
}

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
void deleteFuncionario(){
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
}

void atualizaFuncionario(){
  system(CLEAR);
  
  if(iteratorFun > 0){
    char tempRg[20];
    int posicao;
    
    printf("Digite o RG do cliente: ");
    /*Guardando numa variavel temporaria*/
    scanf("%s", tempRg);
    
    /*Buscar o funcionario a ser atualizado*/
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
}

void verFuncionario(){
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
}
