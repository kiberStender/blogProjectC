/* 
 * File:   Data.h
 * Author: sirkleber
 *
 * Created on March 6, 2015, 5:49 AM
 */

#ifndef DATA_H
#define	DATA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct Data {
        char* dia;
        char* mes;
        char* ano;
    } Data;
    
    Data* construtorData(char*);
    
    Data* construtorData1(char*, char*, char*);
    
    Data* construtorData2(Data*);
    
    void freeData(Data**);
    
    int dataEquals(Data*, Data*);
    
    void setDataDia(Data**, char*);
    
    void setDataMes(Data**, char*);
    
    void setDataAno(Data**, char*);
    
    void printData(Data*);

#ifdef	__cplusplus
}
#endif

#endif	/* DATA_H */

