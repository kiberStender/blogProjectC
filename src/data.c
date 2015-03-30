#include "../header/data.h"
#include "../header/functions.h"
#include <string.h>
#include <stdlib.h>

Data construtorData(char data[]){  
  char dia[2], mes[2], ano[4];
  int i, j = 0;
  int d = 0, m = 0, a = 0;
  
  for(i = 0; i < 10; ++i){
    
    if(data[i] == '/' || data[i] == '-'){
      j = j + 1;
    } else {
      switch(j){
        case 0: 
          dia[d] = data[i];
          d++;
          break;
        case 1:
          mes[m] = data[i];
          m++;
          break;
        case 2:
          ano[a] = data[i];
          a++;
          break;          
      }
    }
  }
  
  return construtorData1(dia, mes, ano);
}

Data construtorData1(char dia[], char mes[], char ano[]){
  Data dt;
  
  dt.dia = (char*) calloc(2, sizeof(char));
  strncpy(dt.dia, dia, 2);
  
  dt.mes = (char*) calloc(2, sizeof(char));
  strncpy(dt.mes, mes, 2);
  
  dt.ano = (char*) calloc(4, sizeof(char));
  strncpy(dt.ano, ano, 4);
  
  return dt;
}

Data construtorData2(Data d){
  return construtorData1(d.dia, d.mes, d.ano);
}

int dataEquals(Data a, Data b){
  if(strncmp(a.dia, b.dia, 2) != 0){
    return 0;
  } else if (strncmp(a.mes, b.mes, 2) != 0){
    return 0;
  } else if (strncmp(a.ano, b.ano, 4) != 0){
    return 0;
  } else {
    return 1;
  }
}

void setDataDia(Data* d, char* dia){
  free(d->dia);
  d->dia = (char*) calloc(strlen(dia), sizeof(char));
  strcpy(d->dia, dia);
}

void setDataMes(Data* d, char* mes){
  free(d->mes);
  d->mes = (char*) calloc(strlen(mes), sizeof(char));
  strcpy(d->mes, mes);
}

void setDataAno(Data* d, char* ano){
  free(d->ano);
  d->ano = (char*) calloc(strlen(ano), sizeof(char));
  strcpy(d->ano, ano);
}

void printData(Data d){
  printf("%s/%s/%s", d.dia, d.mes, d.ano);
}

void freeData(Data* d){
  free(d->dia);
  d->dia = NULL;
  
  free(d->mes);
  d->mes = NULL;
  
  free(d->ano);
  d->ano = NULL;
}