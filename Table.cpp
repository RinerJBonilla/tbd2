//
// Created by miriam trochez on 05/03/2018.
//

#include "Table.h"

Table::Table(){
    nomber;
    primerBloqueCol=0;
    cantCol=0;
    primerBloqueReg=-1;
    cantReg=0;
    regLength=0;
    campero = new std::list<Column*>;
}

Table::Table(char* nam){
    strcpy(nomber, nam);
    primerBloqueCol=0;
    cantCol=0;
    primerBloqueReg=-1;
    cantReg=0;
    regLength=0;
    campero = new std::list<Column*>;
}


char* Table:: toChar()
{
    char *datos;
    datos= new char[40];
    int pos = 0;
    memcpy(&datos[pos], nomber,20);
    pos+=20;
    memcpy(&datos[pos], &primerBloqueCol, sizeof(int));
    pos+=4;
    memcpy(&datos[pos], &cantCol, sizeof(int));
    pos+=4;
    memcpy(&datos[pos], &primerBloqueReg, sizeof(int));
    pos+=4;
    memcpy(&datos[pos], &cantReg, sizeof(int));
    pos+=4;
    memcpy(&datos[pos], &regLength, sizeof(int));
    pos+=4;
    return datos;
}

void Table:: chatToTabla(char* datos)
{
    int pos = 0;
    memcpy(nomber,&datos[pos],20);
    pos+=20;
    memcpy(&primerBloqueCol,&datos[pos], sizeof(int));
    pos+=4;
    memcpy(&cantCol,&datos[pos], sizeof(int));
    pos+=4;
    memcpy(&primerBloqueReg,&datos[pos], sizeof(int));
    pos+=4;
    memcpy(&cantReg,&datos[pos], sizeof(int));
    pos+=4;
    memcpy(&regLength,&datos[pos], sizeof(int));
    pos+=4;
}

