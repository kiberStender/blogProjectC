#include <stdlib.h>
#include <stdio.h>

#include "../header/Cliente.h"
#include "../header/DbCliente.h"

DbCliente* construtorDbCliente(){
  return NULL;
}

DbCliente* construtorDbCliente1(DbCliente* tail, Cliente* head){
  DbCliente* novo = calloc(1, sizeof(DbCliente));
  
  novo->cliente = head;
  novo->prox = tail;
  
  return novo;
}

void freeDbCliente(DbCliente** db){
  if(*db != NULL){
    Cliente* del = (*db)->cliente;
    DbCliente* prox = (*db)->prox;
    
    freeCliente(&del);
    db = NULL;
    
    freeDbCliente(&prox);    
  }
}

int tamanhoDbCliente(DbCliente* db){
  if(db == NULL){
    return 0;
  } else {
    return 1 + tamanhoDbCliente(db->prox);
  }
}

DbCliente* consCliente(DbCliente* db, Cliente* c){
  if(db == NULL){
    return construtorDbCliente1(db, c);
  } else {
    Cliente* head = db->cliente;
    DbCliente* calda = db->prox;
    int cmp = clienteCmp(head, c);
    
    if(cmp < 0){
      return construtorDbCliente1(consCliente(calda, c), head);
    } else if(cmp == 0) {
      if(equalsCliente(head, c)){
        return db;
      } else {
        return consCliente(calda, c);
      }
    } else {
      return construtorDbCliente1(construtorDbCliente1(calda, head), c);
    }
  }
}

void adicionarCliente(DbCliente** db, Cliente* c){
  *db = consCliente(*db, c);
}

void removerCliente(DbCliente** db, Cliente* c){
  if(*db != NULL){
    DbCliente* atual = *db;
    DbCliente* aux = NULL;
    Cliente* del = NULL;
    
    while(atual != NULL){
      if(!equalsCliente(aux->cliente, c)){
        aux = consCliente(aux, aux->cliente);
      } else {
        del = aux->cliente;
      }
    }
    
    atual = atual->prox;
    freeCliente(&del);
    del = NULL;
  }
}

void setDbClienteCliente(DbCliente** db, Cliente* prc, Cliente* novo) {
  if(*db != NULL){
    if(equalsCliente((*db)->cliente, prc)){
      (*db)->cliente = construtorCliente2(novo);
    } else {
      setDbClienteCliente(&(*db)->prox, prc, novo);
    }
  }
}

Cliente* getDbClienteCliente(DbCliente* db, Cliente* prc){
  if(db == NULL){
    return NULL;
  } else {
    if(equalsCliente(db->cliente, prc)){
      return db->cliente;
    } else {
      return getDbClienteCliente(db->prox, prc);
    }
  }
}

int existeCliente(DbCliente* db, Cliente* prc){
  if(db == NULL){
    return 0;
  } else {
    if(equalsCliente(db->cliente, prc)){
      return 1;
    } else {
      return existeCliente(db, prc);
    }
  }
}