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

void removerFuncionario(DbFuncionario** db, Funcionario* c){
  if(*db != NULL){
    DbFuncionario* atual = *db;
    DbFuncionario* aux = NULL;
    Funcionario* del = NULL;
    
    while(atual != NULL){
      if(!equalsFuncionario(aux->funcionario, c)){
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

DbFuncionario** splitDbFR(int curN, DbFuncionario* curL, DbFuncionario* pre){  
  DbFuncionario** tupla = calloc(2, sizeof(DbFuncionario));
  
  if(curL == NULL){
    tupla[0] = pre;
    tupla[1] = NULL;
    return tupla;
  } else {
    if(curN == 0){
      tupla[0] = pre;
      tupla[1] = curL;
      
      return tupla;
    } else {
      return splitDbFR(curN - 1, curL->prox, consFuncionario(pre, curL->funcionario));
    }
  }
}

DbFuncionario** splitDbF(DbFuncionario* db, int n){
  return splitDbFR(n, db, NULL);
}

void setDbFuncionarioFuncionario(DbFuncionario** db, Funcionario* prc, Funcionario* novo) {
  if(*db != NULL){
    DbFuncionario** tupla = splitDbF(*db, tamanhoDbFuncionario(*db) / 2);
    int cmp = funcionarioCmp(prc, tupla[1]->funcionario);

    if(cmp >= 0){
      if(equalsFuncionario(tupla[1]->funcionario, prc)){
        tupla[1]->funcionario = construtorFuncionario2(novo);
      } else {
        setDbFuncionarioFuncionario(&tupla[1], prc, novo);
      }
    } else {
      setDbFuncionarioFuncionario(&tupla[0], prc, novo);
    }
  }
}

Funcionario* getDbFuncionarioFuncionario(DbFuncionario* db, Funcionario* prc){
  if(db == NULL){
    return NULL;
  } else {
    DbFuncionario** tupla = splitDbF(db, tamanhoDbFuncionario(db) / 2);
    int cmp = funcionarioCmp(prc, tupla[1]->funcionario);

    if(cmp >= 0){
      if(equalsFuncionario(tupla[1]->funcionario, prc)){
        return tupla[1]->funcionario;
      } else {
        return getDbFuncionarioFuncionario(tupla[1], prc);
      }
    } else {
      return getDbFuncionarioFuncionario(tupla[0], prc);
    }
  }
}

int existeFuncionario(DbFuncionario* db, Funcionario* prc){
  if(db == NULL){
    return 0;
  } else {
    DbFuncionario** tupla = splitDbF(db, tamanhoDbFuncionario(db) / 2);
    int cmp = funcionarioCmp(prc, tupla[1]->funcionario);

    if(cmp >= 0){
      if(equalsFuncionario(tupla[1]->funcionario, prc)){
        return 1;
      } else {
        return existeFuncionario(tupla[1], prc);
      }
    } else {
      return existeFuncionario(tupla[0], prc);
    }
  }
}