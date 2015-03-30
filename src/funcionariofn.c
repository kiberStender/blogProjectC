#include "../header/data.h"
#include "../header/endereco.h"
#include "../header/funcionario.h"
#include "../header/functions.h"
#include "../header/funcionariofn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

void cadastraFuncionario(DbFuncionario* db){
  system(CLEAR);
  
  if(db->iterator < MAXREG){
    char nome[20], sobrenome[20], rg[20], cartTrab[20], dataNasc[15], cep[15], 
            num[15], rua[25], bairro[25], cid[25], est[25], pais[25];       
    
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
    
    printf("Digite o Cep do funcionario: ");
    scanf("%s", cep);
    
    printf("Digite o numero da casa do funcionario: ");
    scanf("%s", num);
    
    printf("Digite a rua do funcionario: ");
    scanf("%s", rua);
    
    printf("Digite o bairro do funcionario: ");
    scanf("%s", bairro);
    
    printf("Digite cidade do funcionario: ");
    scanf("%s", cid);
    
    printf("Digite o estado do funcionario: ");
    scanf("%s", est);
    
    printf("Digite o pais do funcionario: ");
    scanf("%s", pais);
    
    Data dt = construtorData(dataNasc);
    Endereco end = construtorEndereco(cep, num, rua, bairro, cid, est, pais);
    Funcionario * f = construtorFuncionario(nome, sobrenome, rg, cartTrab, dt, end);
    
    if(existeFuncionario(db, *f)){
      printf("Funcionario ja existente!!!");
    } else {
      adicionarFuncionario(db, f);
      
      printf("Cadastrado com sucesso!!!");
    }
  } else {
    printf(MSG);
  }
}

void deleteFuncionario(DbFuncionario* db, int posicao){
  int i;
      
  /**
   * Primeiro dou free em Funcionario
   * Depois copio o dados da próxima posição
   * para a posição recem- apagada
   * apenas se ela não for NULL
   */
  for(i = posicao; i < MAXREG; i++){
    removerFuncionario(db, posicao);
    
    Funcionario* f = getDbFuncionarioFuncionario(db, i + 1);
        
    if(f != NULL){
      setDbFuncionarioFuncionario(db, f, i);
    }
  }
      
  printf(MSG3);
}

void atualizaFuncionario(DbFuncionario* db, int posicao){
  char nome[20], sNome[20], rg[13], cartTrab[15], dtNasc[12], cep[15], 
            num[15], rua[25], bairro[25], cid[25], est[25], pais[25];
  
  Funcionario* f = getDbFuncionarioFuncionario(db, posicao);
      
  printFuncionario(*f);
  
  printf("\n\nPara manter o mesmo valor digite _ \n\n");
      
  printf("Digite um novo valor para o nome: ");
  scanf("%s", nome);
  printf("Digite um novo valor para o sobrenome: ");
  scanf("%s", sNome);
  printf("Digite um novo valor para o rg: ");
  scanf("%s", rg);
  printf("Digite um novo valor para a carteira de Trabalho: ");
  scanf("%s", cartTrab);
  printf("Digite um novo valor para a data de nascimento: ");
  scanf("%s", dtNasc);
  printf("Digite um novo valor para o cep: ");
  scanf("%s", cep);
  printf("Digite um novo valor para o numero dac casa: ");
  scanf("%s", num);
  printf("Digite um novo valor para rua: ");
  scanf("%s", rua);
  printf("Digite um novo valor para o bairro: ");
  scanf("%s", bairro);
  printf("Digite um novo valor para a cidade: ");
  scanf("%s", cid);
  printf("Digite um novo valor para o estado: ");
  scanf("%s", est);
  printf("Digite um novo valor para o pais: ");
  scanf("%s", pais);
  
  Endereco end = f->end;

  if(strncmp(nome, "_", 1) != 0){
    setFuncionarioNome(f, nome);
  }
  if(strncmp(sNome, "_", 1) != 0){
    setFuncionarioSobrenome(f, sNome);
  }
  if(strncmp(rg, "_", 1) != 0){
    setFuncionarioRG(f, rg);
  }
  if(strncmp(cartTrab, "_", 1) != 0){
    setFuncionarioCartTrab(f, cartTrab);
  }
  if(strncmp(dtNasc, "_", 1) != 0) {
    setFuncionarioDataNasc(f, construtorData(dtNasc));
  }
  if(strncmp(cep, "_", 1) != 0)  {
    setEnderecoCep(&end, cep);
  }
  if(strncmp(num, "_", 1) != 0)  {
    setEnderecoNum(&end, num);
  }  
  if(strncmp(rua, "_", 1) != 0)  {
    setEnderecoRua(&end, rua);
  }
  if(strncmp(bairro, "_", 1) != 0)  {
    setEnderecoBairro(&end, bairro);
  }
  if(strncmp(cid, "_", 1) != 0)  {
    setEnderecoCidade(&end, cid);
  }
  if(strncmp(est, "_", 1) != 0)  {
    setEnderecoEstado(&end, est);
  }
  if(strncmp(pais, "_", 1) != 0)  {
    setEnderecoPais(&end, pais);
  }
  
  setFuncionarioEnd(f, end);
  setDbFuncionarioFuncionario(db, f, posicao);
}

void verFuncionario(DbFuncionario *db, int posicao){
  
  printFuncionario(*getDbFuncionarioFuncionario(db, posicao));
  
  system(PAUSE);
}