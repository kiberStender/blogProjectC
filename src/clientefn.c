#include "../header/endereco.h"
#include "../header/data.h"
#include "../header/cliente.h"
#include "../header/clientefn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
/*Lib para o toupper*/

/*Acoes com cliente*/

void cadastraCliente(DbCliente* db){
  system(CLEAR);
  
  if(!estaCheioCliente(db)){
    char nome[20], sobrenome[20], rg[13], cpf[15], dataNasc[12], cep[15], 
            num[15], rua[25], bairro[25], cid[25], est[25], pais[25];
  
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
    
    Data dt = construtorData(dataNasc);
    Endereco end = construtorEndereco(cep, num, rua, bairro, cid, est, pais);
    
    Cliente *c = construtorCliente(nome, sobrenome, rg, cpf, dt, end);
    
    if(existeCliente(db, *c)){
      printf("Cliente já existente!!!");
    } else {
      adicionarCliente(db, c);
      
      printf("Cadastrado com sucesso!!!");
    }

  } else {
    printf(MSG);
  }
}

void deleteCliente(DbCliente* db, int posicao){
  int i;
      
  /**
   * Primeiro dou free em Cliente
   * Depois copio o dados da próxima posição
   * para a posição recem- apagada
   * apenas se ela não for NULL
   */
  for(i = posicao; i < MAXREG; i++){
    removerCliente(db, i);
    
    Cliente* c = getDbClienteCliente(db, i + 1);
    
    if(c != NULL){
      setDbClienteCliente(db, c, i);
    }
  }
  printf(MSG3);
}

void atualizaCliente(DbCliente* db, int posicao){
  char nome[20], sNome[20], rg[13], cpf[15], dtNasc[12], cep[15], 
            num[15], rua[25], bairro[25], cid[25], est[25], pais[25];
  
  printf("Dados originais \n\n");
  printCliente(*getDbClienteCliente(db, posicao));
      
  printf("\n\nPara manter o mesmo valor digite _ \n\n");
      
  printf("Digite um novo valor para o nome: ");
  scanf("%s", nome);
  printf("Digite um novo valor para o sobrenome: ");
  scanf("%s", sNome);
  printf("Digite um novo valor para o rg: ");
  scanf("%s", rg);
  printf("Digite um novo valor para o cpf: ");
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
  
  Cliente* c = db->db[posicao];
  Endereco end = c->end;

  if(strncmp(nome, "_", 1) != 0){
    setClienteNome(c, nome);
  }
  if(strncmp(sNome, "_", 1) != 0){
    setClienteSobrenome(c, sNome);
  }
  if(strncmp(rg, "_", 1) != 0){
    setClienteRG(c, rg);
  }
  if(strncmp(cpf, "_", 1) != 0){
    setClienteCpf(c, cpf);
  }
  if(strncmp(dtNasc, "_", 1) != 0){
    setClienteDataNasc(c, construtorData(dtNasc));
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
  
  setClienteEnd(c, end);
  setDbClienteCliente(db, c, posicao);
}

void verCliente(DbCliente* db, int posicao){
  printCliente(*getDbClienteCliente(db, posicao));
  system(PAUSE);
}


