#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../header/functions.h"
#include "../header/DbCliente.h"
#include "../header/ControladorCliente.h"

ControladorCliente construtorControladorCliente(){
  ControladorCliente cc;
  cc.lista = NULL;
  
  return cc;
}

void freeControladorCliente(ControladorCliente* cc){
  freeDbCliente(&cc->lista);
}

void cadastraCliente(ControladorCliente* cc){
  system(CLEAR);
  
  /*char nome[20], sobrenome[20], rg[13], cpf[15], dataNasc[12], cep[15], 
    num[15], rua[25], bairro[25], cid[25], est[25], pais[25];
  
  printf("Digite o nome do cliente: ");
  scanf("%s", nome); //Pegando o nome do sujeito
  
  printf("Digite o sobrenome do cliente: ");
  scanf("%s", sobrenome); //Pegando o sobrenome do sujeito
   
  printf("Digite o RG do cliente: ");
  scanf("%s", rg); //Pegando o rg do sujeito
  /
  printf("Digite o CPF do cliente: ");
  scanf("%s", cpf); //Pegando o cpf do sujeito
     
  printf("Digite a data de nascimento do cliente: ");
  scanf("%s", dataNasc); //Pegando o datanasc do sujeito
    
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
    
  Cliente *c = construtorCliente(nome, sobrenome, rg, cpf, dt, end);*/
  
  Data* dt = construtorData("20/09/1989");
  Endereco* end = construtorEndereco("3698", "32", "bloa", "bair", "ga", "pes", "br");
    
  Cliente *c = construtorCliente("Kleber", "stender", "366", "989", dt, end);
    
  if(existeCliente(cc->lista, c)){
    printf("Cliente já existente!!!");
  } else {
    
    adicionarCliente(&cc->lista, c);
    
    printf("Cadastrado com sucesso!!!");    
  }
}

void deleteCliente(ControladorCliente* cc, Cliente* c){
  removerCliente(&cc->lista, getCcCliente(cc, c));
}
void atualizaCliente(ControladorCliente* cc, Cliente* c){
  char nome[20], sNome[20], rg[13], cpf[15], dtNasc[12], cep[15], 
            num[15], rua[25], bairro[25], cid[25], est[25], pais[25];
  
  Cliente* c1 = getCcCliente(cc, c);
      
  printCliente(c1);
  
  printf("\n\nPara manter o mesmo valor digite _ \n\n");
      
  printf("Digite um novo valor para o nome: ");
  scanf("%s", nome);
  printf("Digite um novo valor para o sobrenome: ");
  scanf("%s", sNome);
  printf("Digite um novo valor para o rg: ");
  scanf("%s", rg);
  printf("Digite um novo valor para a carteira de Trabalho: ");
  scanf("%s", cpf);
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
  
  Endereco* end = c1->end;

  if(strncmp(nome, "_", 1) != 0){
    setClienteNome(&c1, nome);
  }
  if(strncmp(sNome, "_", 1) != 0){
    setClienteSobrenome(&c1, sNome);
  }
  if(strncmp(rg, "_", 1) != 0){
    setClienteRG(&c1, rg);
  }
  if(strncmp(cpf, "_", 1) != 0){
    setClienteCpf(&c1, cpf);
  }
  if(strncmp(dtNasc, "_", 1) != 0) {
    setClienteDataNasc(&c1, construtorData(dtNasc));
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
  
  setClienteEnd(&c1, end);
  setDbClienteCliente(&cc->lista, c, c1);  
}

void verCliente(ControladorCliente* cc, Cliente* prc) { 
  printCliente(getCcCliente(cc, prc));
  system(PAUSE);
}

Cliente* getCcCliente(ControladorCliente* cc, Cliente* prc){
  return getDbClienteCliente(cc->lista, prc);
}