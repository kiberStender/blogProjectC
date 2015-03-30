#include <stdlib.h>
#include <stdio.h>

#include "../header/Funcionario.h"
#include "../header/DbFuncionario.h"

DbFuncionario* construtorDbFuncionario(){
  DbFuncionario* db = calloc(1, sizeof(DbFuncionario));
  db->prox = NULL;

  return db;
}

DbFuncionario* construtorDbFuncionario1(DbFuncionario* tail, Funcionario* head){
  DbFuncionario* novo = construtorDbFuncionario();
  
  novo->funcionario = head;
  novo->prox = tail;
  
  return novo;
}

void freeDbFuncionario(DbFuncionario** db){
  if(*db != NULL){
    Funcionario* del = (*db)->funcionario;
    DbFuncionario* prox = (*db)->prox;
    
    freeFuncionario(&del);
    db = NULL;
    
    freeDbFuncionario(&prox);    
  }
}

int tamanhoDbFuncionario(DbFuncionario* db){
  if(db == NULL){
    return 0;
  } else {
    return 1 + tamanhoDbFuncionario(db->prox);
  }
}

DbFuncionario* consFuncionario(DbFuncionario* db, Funcionario* c){
  if(db == NULL){
    return construtorDbFuncionario1(db, c);
  } else {
    Funcionario* head = db->funcionario;
    DbFuncionario* calda = db->prox;
    int cmp = funcionarioCmp(head, c);
    
    if(cmp < 0){
      return construtorDbFuncionario1(consFuncionario(calda, c), head);
    } else if(cmp == 0) {
      if(equalsFuncionario(head, c)){
        return db;
      } else {
        return consFuncionario(calda, c);
      }
    } else {
      return construtorDbFuncionario1(construtorDbFuncionario1(calda, head), c);
    }
  }
}

void adicionarFuncionario(DbFuncionario** db, Funcionario* c){
  *db = consFuncionario(*db, c);
}

void removerFuncionario(DbFuncionario** db, Funcionario* prc){
  if(*db != NULL){
    DbFuncionario* atual = *db;
    DbFuncionario* aux = NULL;
    Funcionario* del = NULL;
    
    while(atual != NULL){
      Funcionario* f = aux->funcionario;
      
      if(strncmp(f->rg, prc->rg, strlen(f->rg)) != 0){
        aux = consFuncionario(aux, aux->funcionario);
      } else {
        del = aux->funcionario;
      }
    }
    
    atual = atual->prox;
    freeFuncionario(&del);
    del = NULL;
  }
}

void setDbFuncionarioFuncionario(DbFuncionario** db, Funcionario* prc, Funcionario* novo) {
  if(*db != NULL){
    Funcionario* f = (*db)->funcionario;
    
    if(strncmp(f->rg, prc->rg, strlen(f->rg)) == 0){
      (*db)->funcionario = construtorFuncionario2(novo);
    } else {
      setDbFuncionarioFuncionario(&(*db)->prox, prc, novo);
    }
  }
}

Funcionario* getDbFuncionarioFuncionario(DbFuncionario* db, Funcionario* prc){
  if(db == NULL){
    return NULL;
  } else {
    Funcionario* f = db->funcionario;
    
    if(strncmp(f->rg, prc->rg, strlen(f->rg)) == 0){
      return f;
    } else {
      return getDbFuncionarioFuncionario(db->prox, prc);
    }
  }
}

int existeFuncionario(DbFuncionario* db, Funcionario* prc){
  if(db == NULL){
    return 0;
  } else {
    Funcionario* f = db->funcionario;
    
    if(strncmp(f->rg, prc->rg, strlen(f->rg)) == 0){
      return 1;
    } else {
      return existeFuncionario(db->prox, prc);
    }
  }
}