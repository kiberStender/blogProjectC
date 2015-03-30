#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../header/functions.h"
#include "../header/DbFuncionario.h"
#include "../header/ControladorFuncionario.h"

ControladorFuncionario construtorControladorFuncionario(){
  ControladorFuncionario cc;
  cc.lista = NULL;
  cc.arquivo = NULL;
  
  return cc;
}

void freeControladorFuncionario(ControladorFuncionario* cf){
  freeDbFuncionario(&cf->lista);
  cf->lista = NULL;
}

void cadastraFuncionario(ControladorFuncionario* cf) {
  system(CLEAR);
  
  char nome[20], sobrenome[20], rg[13], cartTrab[15], dataNasc[12], cep[15], 
    num[15], rua[25], bairro[25], cid[25], est[25], pais[25];
  
  printf("Digite o nome do cliente: ");
  scanf("%s", nome); /*Pegando o nome do sujeito*/
  
  printf("Digite o sobrenome do cliente: ");
  scanf("%s", sobrenome); /*Pegando o sobrenome do sujeito*/
  
  printf("Digite o RG do cliente: ");
  scanf("%s", rg); /*Pegando o rg do sujeito*/
  
  printf("Digite a carteira de trabalho do cliente: ");
  scanf("%s", cartTrab); /*Pegando o cartTrab do sujeito*/
  
  printf("Digite a data de nascimento do cliente: ");
  scanf("%s", dataNasc); /*Pegando o datanasc do sujeito*/
    
  printf("Digite o Cep do cliente: ");
  scanf("%s", cep);
    
  printf("Digite o numero da casa do cliente: ");
  scanf("%s", num);
    
  printf("Digite a rua do cliente: ");
  scanf("%s", rua);
    
  printf("Digite o bairro do cliente: ");
  scanf("%s", bairro);
    
  printf("Digite cidade do cliente: ");
  scanf("%s", cid);
   
  printf("Digite o estado do cliente: ");
  scanf("%s", est);
    
  printf("Digite o pais do cliente: ");
  scanf("%s", pais);
    
  Data* dt = construtorData(dataNasc);
  Endereco* end = construtorEndereco(cep, num, rua, bairro, cid, est, pais);
  
  Funcionario* f = construtorFuncionario(nome, sobrenome, rg, cartTrab, dt, end);
    
  if(existeFuncionario(cf->lista, f)){
    printf("Funcionario já existente!!!");
  } else {
    adicionarFuncionario(&cf->lista, f);
    printf("Cadastrado com sucesso!!!");
  }
}

void deleteFuncionario(ControladorFuncionario* cf, Funcionario* f){
  removerFuncionario(&cf->lista, getCfFuncionario(*cf, f));
}

void atualizaFuncionario(ControladorFuncionario* cf, Funcionario* f){
  char nome[20], sNome[20], rg[13], cartTrab[15], dtNasc[12], cep[15], 
            num[15], rua[25], bairro[25], cid[25], est[25], pais[25];
  
  Funcionario* f1 = getCfFuncionario(*cf, f);
      
  printFuncionario(f1);
  
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
  
  Endereco* end = f1->end;

  if(strncmp(nome, "_", 1) != 0){
    setFuncionarioNome(&f1, nome);
  }
  if(strncmp(sNome, "_", 1) != 0){
    setFuncionarioSobrenome(&f1, sNome);
  }
  if(strncmp(rg, "_", 1) != 0){
    setFuncionarioRG(&f1, rg);
  }
  if(strncmp(cartTrab, "_", 1) != 0){
    setFuncionarioCartTrab(&f1, cartTrab);
  }
  if(strncmp(dtNasc, "_", 1) != 0) {
    setFuncionarioDataNasc(&f1, construtorData(dtNasc));
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
  
  setFuncionarioEnd(&f1, end);
  
  setDbFuncionarioFuncionario(&cf->lista, f, f1);
}

void verFuncionario(ControladorFuncionario cf, Funcionario* f) {
  printFuncionario(getCfFuncionario(cf, f));
}

Funcionario* getCfFuncionario(ControladorFuncionario cf, Funcionario* f){
  return getDbFuncionarioFuncionario(cf.lista, f);
}