//
// Created by miriam trochez on 06/03/2018.
//

#include "DataBloque.h"

DataBloque::DataBloque(int num, char * path) : Bloque(num, path)
{
    Tablas = new std::list<Table*>;
    cantEntradas=0;
}

DataBloque::DataBloque(int num, int tam, DataFile* ff) : Bloque(num,ff)
{
    Tablas = new std::list<Table*>;
    cantEntradas=0;
}
void DataBloque::escribir()
{
    char* data = this->toChar();
    int pos=numeroBloque*4096;
    archivo->escbrir(data,pos,4096);
}

void DataBloque::cargar()
{
    int pos = numeroBloque*4096;
    char* data = archivo->leer(pos,4096);
    this->toCharBloque(data);
}

char* DataBloque::toChar()
{
    int pos=0;
    char* data= new char[4096];
    data = Bloque::toChar();
    pos+=8;
    memcpy(&data[pos], &cantEntradas, 4);
    pos+=4;
    for(std::list<Table*>::iterator it = Tablas->begin(); it != Tablas->end(); it++)
    {
        Table * tabTemp = *it;
        char* dati= new char[40];
        dati = tabTemp->toChar();
        memcpy(&data[pos],dati,40);
        pos+=40;
    }
    return data;


}

void DataBloque::toCharBloque(char* data)
{
    int pos=0;
    Bloque::toCharBloque(data);
    pos+=8;
    memcpy(&cantEntradas, &data[pos],4);
    pos+=4;
    for(int dd=0; dd<this->cantEntradas;dd++)
    {
        Table* t= new Table();
        t->chatToTabla(&data[pos]);
        this->Tablas->push_back(t);
        pos+=40;
    }

}

DataBloque::~DataBloque()
{

}
