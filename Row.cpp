//
// Created by miriam trochez on 05/03/2018.
//

#include "Row.h"

Row::Row() {
    datal;
}

Row::Row(int lig,char *datas) {
    datal = new char[lig];
    strcpy(datal,datas);
}

char *Row::toChar(int lig) {
    char *datos;
    datos= new char[lig];
    int pos = 0;
    memcpy(datos, datal,lig);
    pos+=lig;
}

void Row::chatToRow(int lig,char *datos) {
    int pos = 0;
    memcpy(datal,datos,lig);
    pos+=lig;
}
