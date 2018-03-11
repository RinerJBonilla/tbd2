//
// Created by miriam trochez on 06/03/2018.
//

#ifndef TBD2_ROWBLOQUE_H
#define TBD2_ROWBLOQUE_H
#include "Bloque.h"
#include "Row.h"
#include "DataFile.h"
#include <stdio.h>
#include <list>


class RowBloque : public Bloque {
public:
    RowBloque(int num, char * path);
    RowBloque(int num,int tam, DataFile* ff);
    std::list<char*> *Rows;
    int cantEntradas;
    void escribir(int lig);
    void cargar(int lig);
    char* toChar(int lig);
    void toCharBloque(int lig, char* data);
    virtual ~RowBloque();
};


#endif //TBD2_ROWBLOQUE_H
