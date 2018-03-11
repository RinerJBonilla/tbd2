//
// Created by miriam trochez on 06/03/2018.
//

#ifndef TBD2_DATABLOQUE_H
#define TBD2_DATABLOQUE_H
#include "Bloque.h"
#include "Table.h"
#include "DataFile.h"
#include <stdio.h>
#include <list>


class DataBloque : public Bloque {
public:
    DataBloque(int num, char * path);
    DataBloque(int num,int tam, DataFile* ff);
    std::list<Table*> *Tablas;
    int cantEntradas;
    void escribir() override;
    void cargar() override;
    char* toChar();
    void toCharBloque(char* data);
    virtual ~DataBloque();

};


#endif //TBD2_DATABLOQUE_H
