#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
#include "../header/functions.h"
#include "../header/funcionario.h"
#include "../header/DbFuncionario.h"

DbFuncionario construtorDbFuncionario(){
  DbFuncionario db;
  int i;
  
  for(i = 0; i < MAXREG; i++){
    db.db[i] = NULL;
  }

  db.iterator = 0;
  
  return db;
}

void adicionarFuncionario(DbFuncionario* db, Funcionario* f){
  db->db[db->iterator] = f;
  db->iterator++;
}

void removerFuncionario(DbFuncionario* db, int pos){
  freeFuncionario(db->db[pos]);  
  db->db[pos] = NULL;
  db->iterator--;
}

void setDbFuncionarioFuncionario(DbFuncionario* db, Funcionario* f, int pos){
  Funcionario* f0 = db->db[pos];
  db->db[pos] = construtorFuncionario(
    f->nome, f->sobrenome, f->rg, f->cartTrab, f->dataNasc, f->end
  );
  
  if(f0 != db->db[pos]){
    freeFuncionario(f0);
  }
  f0 = NULL;
}

Funcionario* getDbFuncionarioFuncionario(DbFuncionario* db, int pos){
  return db->db[pos];
}

int buscaFuncionario(DbFuncionario* db, char rg[]){
    int i;

  for(i = 0; i < MAXREG; i++){
      Funcionario* f = getDbFuncionarioFuncionario(db, i);
      
    if(strncmp(f->rg, rg, strlen(f->rg)) == 0){
      return i;
    }
  }
  return -1;
}

int existeFuncionario(DbFuncionario* db, Funcionario f){
  int i;

  for(i = 0; i < MAXREG; i++){
    Funcionario* f0 = getDbFuncionarioFuncionario(db, i);
    
    if(f0 != NULL){
      return equalsFuncionario(*f0, f);
    }
  }
  return 0;
}

int estaCheioFuncionario(DbFuncionario* db){
  return db->iterator >= MAXREG;
}

int temEspacoFuncionario(DbFuncionario* db){
  return db->iterator > 0;
}

void freeDbFuncionario(DbFuncionario* db){
  int i;
  
  for(i = 0; i > MAXREG; i++){
    removerFuncionario(db, i);
  }
}