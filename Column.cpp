//
// Created by miriam trochez on 05/03/2018.
//

#include "Column.h"

Column::Column() {
    name;
    dataType;
    dataLength=0;
}

Column::Column(char* nam, char* dataTyp, int dataLength){

    strcpy(name, nam);
    this->dataLength = dataLength;
    strcpy(dataType, dataTyp);
}

char* Column::getName(){
    return name;
}

char* Column::getDataType(){
    return dataType;
}

int Column::getDataLength(){
    return dataLength;
}

char* Column:: toChar()
{
    char *datos;
    datos= new char[44];
    int pos = 0;
    memcpy(&datos[pos], name,20);
    pos+=20;
    memcpy(&datos[pos],dataType,20);
    pos+=20;
    memcpy(&datos[pos], &dataLength, sizeof(int));
    pos+=4;
    return datos;
}
void Column::chatToColumn(char *datos)
{
    int pos = 0;
    memcpy(name,&datos[pos],20);
    pos+=20;
    memcpy(dataType,&datos[pos],20);
    pos+=20;
    memcpy(&dataLength,&datos[pos], sizeof(int));
    pos+=4;
}