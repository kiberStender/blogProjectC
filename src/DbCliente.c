#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lib nova para adicionar algumas funcionalidades legais*/
#include <ctype.h>
#include "../header/cliente.h"
#include "../header/DbCliente.h"
#include "../header/functions.h"

DbCliente construtorDbCliente(){
  DbCliente db;
  int i;
  
  for(i = 0; i < MAXREG; i++){
    db.db[i] = NULL;
  }

  db.iterator = 0;

  return db;
}

void adicionarCliente(DbCliente* db, Cliente* c){
  db->db[db->iterator] = c;
  db->iterator++;
}

void removerCliente(DbCliente* db, int pos){
  freeCliente(db->db[pos]);
  db->db[pos] = NULL;
  db->iterator--;
}

void setDbClienteCliente(DbCliente* db, Cliente* c, int pos){
  Cliente* c0 = db->db[pos];
  db->db[pos] = construtorCliente(
    c->nome, c->sobrenome, c->rg, c->cpf, c->dataNasc, c->end
  );
  
  if(c0 != db->db[pos]){
    freeCliente(c0);
  }
  c0 = NULL;
}

Cliente* getDbClienteCliente(DbCliente* db, int pos){  
  return db->db[pos];
}

int buscaCliente(DbCliente* db, char rg[]){
  int i;
  
  for(i = 0; i < MAXREG; i++){
    Cliente* c = getDbClienteCliente(db, i);
    
    if(strncmp(c->rg, rg, strlen(c->rg)) == 0){
      return i;
    }
  }
  return -1;
}

int existeCliente(DbCliente* db, Cliente c){
  int i;

  for(i = 0; i < MAXREG; i++){
    Cliente* c1 = getDbClienteCliente(db, i);
    
    if(c1 != NULL){
      return equalsCliente(*c1, c);
    }
  }
  return 0;
}

int estaCheioCliente(DbCliente* db){
  return db->iterator >= MAXREG;
  //igual if(db->iterator >= MAXREG){ return 1;} else {return 0;}
}

int temEspacoCliente(DbCliente* db){
  return db->iterator > 0;
  //igual if(db->iterator > 0){ return 1;} else {return 0;}
}

void freeDbCliente(DbCliente* db){
  int i;
  
  for(i = 0; i > MAXREG; i++){
    removerCliente(db, i);
  }
}
