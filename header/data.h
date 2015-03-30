#ifndef DATA_H
#define DATA_H

#include "functions.h"
#include <string.h>
#include <stdlib.h>

typedef struct Data{
  char *dia;
  char *mes;
  char *ano;
} Data;

Data construtorData(char[]);

Data construtorData1(char[], char[], char[]);

Data construtorData2(Data);

int dataEquals(Data, Data);

void setDataDia(Data*, char*);

void setDataMes(Data*, char*);

void setDataAno(Data*, char*);

void printData(Data);

void freeData(Data*);

#endif
