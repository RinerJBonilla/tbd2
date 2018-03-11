//
// Created by miriam trochez on 05/03/2018.
//

#ifndef TBD2_TABLE_H
#define TBD2_TABLE_H
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#include "column.h"
#include "row.h"

using namespace std;

class Column;
class Row;

class Table {
public:
    Table();
    Table(char* nam);
    char* toChar();
    void chatToTabla(char* datos);
    char nomber[20];
    int primerBloqueCol;
    int cantCol;
    int primerBloqueReg;
    int cantReg;
    int regLength;
    std::list<Column*>*campero;
    std::list<char*> *Rowes;
};


#endif //TBD2_TABLE_H
