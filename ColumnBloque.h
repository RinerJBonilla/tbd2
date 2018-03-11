//
// Created by miriam trochez on 06/03/2018.
//

#ifndef TBD2_COLUMNBLOQUE_H
#define TBD2_COLUMNBLOQUE_H
#include "Bloque.h"
#include "Column.h"
#include "DataFile.h"
#include <stdio.h>
#include <list>


class ColumnBloque : public Bloque {
public:
    ColumnBloque(int num, char * path);
    ColumnBloque(int num,int tam, DataFile* ff);
    std::list<Column*> *Columnas;
    int cantEntradas;
    void escribir() override;
    void cargar() override;
    char* toChar();
    void toCharBloque(char* data);
    virtual ~ColumnBloque();

};


#endif //TBD2_COLUMNBLOQUE_H
