//
// Created by miriam trochez on 05/03/2018.
//

#include "Bloque.h"

Bloque::Bloque(int Numero,char * path)
{
    archivo = new DataFile(path);
    numeroBloque=Numero;
    siguiente=-1;
}

Bloque::Bloque(int Numero,DataFile* ff)
{
    siguiente=-1;
    numeroBloque=Numero;
    archivo= ff;
}

Bloque::~Bloque()
{
    //dtor
}
void Bloque::escribir()
{
    char* data = this->toChar();
    int pos=numeroBloque*4096;
    archivo->escbrir(data,pos,4096);
}

void Bloque::cargar()
{
    int pos = numeroBloque*4096;
    char* data = archivo->leer(pos, 4096);
    toCharBloque(data);
}
char* Bloque::toChar()
{
    char* data= new char[4096];
    int pos=0;
    memcpy(&data[pos], &numeroBloque, 4);
    pos+=4;
    memcpy(&data[pos],&siguiente,4);
    pos+=4;
    return data;
}
void Bloque::toCharBloque(char* data)
{
    int pos=0;
    memcpy(&numeroBloque, &data[pos],4);
    pos+=4;
    memcpy(&siguiente, &data[pos],4);
    pos+=4;
}
