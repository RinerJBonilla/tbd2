//
// Created by miriam trochez on 05/03/2018.
//

#ifndef TBD2_BLOQUE_H
#define TBD2_BLOQUE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DataFile.h"


class Bloque {
public:
    Bloque(int Numero,char * path);
    Bloque(int Numero,DataFile* ff);
    virtual void escribir();
    virtual void cargar();
    virtual char* toChar();
    virtual void toCharBloque(char* data);
    virtual ~Bloque();
    int numeroBloque;
    int siguiente;
    DataFile* archivo;

};


#endif //TBD2_BLOQUE_H
