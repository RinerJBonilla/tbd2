//
// Created by miriam trochez on 06/03/2018.
//

#include "ColumnBloque.h"

ColumnBloque::ColumnBloque(int num, char * path) : Bloque(num, path)
{
    Columnas = new std::list<Column*>;
    cantEntradas=0;
}

ColumnBloque::ColumnBloque(int num, int tam, DataFile* ff) : Bloque(num,ff)
{
    Columnas = new std::list<Column*>;
    cantEntradas=0;
}
void ColumnBloque::escribir()
{
    char* data = this->toChar();
    int pos=numeroBloque*4096;
    archivo->escbrir(data,pos,4096);
}

void ColumnBloque::cargar()
{
    int pos = numeroBloque*4096;
    char* data = archivo->leer(pos, 4096);
    this->toCharBloque(data);
}

char* ColumnBloque::toChar()
{
    int pos=0;
    char* data= new char[4096];
    data = Bloque::toChar();
    pos+=8;
    memcpy(&data[pos], &cantEntradas, 4);
    pos+=4;
    for(std::list<Column*>::iterator it = Columnas->begin(); it != Columnas->end(); it++)
    {
        Column * tabTemp = *it;
        char* dati= new char[44];
        dati = tabTemp->toChar();
        memcpy(&data[pos],dati,44);
        pos+=44;
    }
    return data;


}

void ColumnBloque::toCharBloque(char* data)
{
    int pos=0;
    Bloque::toCharBloque(data);
    pos+=8;
    memcpy(&cantEntradas, &data[pos],4);
    pos+=4;
    for(int dd=0; dd<this->cantEntradas;dd++)
    {
        Column* t= new Column();
        t->chatToColumn(&data[pos]);
        this->Columnas->push_back(t);
        pos+=44;
    }

}

ColumnBloque::~ColumnBloque()
{

}
