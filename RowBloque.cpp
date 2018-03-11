//
// Created by miriam trochez on 06/03/2018.
//

#include "RowBloque.h"

RowBloque::RowBloque(int num, char *path) : Bloque(num, path) {
    Rows = new std::list<char*>;
    cantEntradas=0;
}

RowBloque::RowBloque(int num, int tam, DataFile *ff) : Bloque(num,ff){
    Rows = new std::list<char*>;
    cantEntradas=0;
}

void RowBloque::escribir(int lig) {
    char* data = this->toChar(lig);
    int pos=numeroBloque*4096;
    archivo->escbrir(data,pos,4096);
}

void RowBloque::cargar(int lig) {
    int pos = numeroBloque*4096;
    char* data = archivo->leer(pos, 4096);
    this->toCharBloque(lig,data);
}

char *RowBloque::toChar(int lig) {
    int pos=0;
    char* data= new char[4096];
    data = Bloque::toChar();
    pos+=8;
    memcpy(&data[pos], &cantEntradas, 4);
    pos+=4;
    for(std::list<char*>::iterator it = Rows->begin(); it != Rows->end(); it++)
    {
        char* tabTemp = *it;
        char* dati= new char[lig];
        dati = tabTemp;
        memcpy(&data[pos],dati,lig);
        pos+=lig;
    }
    return data;
}

void RowBloque::toCharBloque(int lig, char *data) {
    int pos=0;
    Bloque::toCharBloque(data);
    pos+=8;
    memcpy(&cantEntradas, &data[pos],4);
    pos+=4;
    for(int dd=0; dd<this->cantEntradas;dd++)
    {
        char* t= new char[lig];
        memcpy(t,&data[pos],lig);
        this->Rows->push_back(t);
        pos+=lig;
    }
}

RowBloque::~RowBloque() {

}
