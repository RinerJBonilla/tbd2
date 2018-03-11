//
// Created by miriam trochez on 07/03/2018.
//

#ifndef TBD2_FACHDATA_H
#define TBD2_FACHDATA_H
#include "Bloque.h"
#include "Table.h"
#include "Column.h"
#include "DataFile.h"
#include "DataBloque.h"
#include "ColumnBloque.h"
#include "Row.h"
#include "RowBloque.h"
#include <stdio.h>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

class FachData {
public:
    FachData();
    bool run();
    void getQuery();
    void executeQuery();
    void executeCREATE();
    void executeINSERT();
    void executeDELETE();
    void executeUPDATE();
    void executeSELECT();
    void executeSET();
    char* str;
    char* pathh;
    std::vector<std::string> words;
    std::vector<std::string> subwords;
    DataBloque* tablos;
    template <class Container>
    void split1(const std::string& str, Container& cont, char delim = ' ');
    template <class Container>
    void split2(const std::string& str, Container& cont, char delim = ':');
};


#endif //TBD2_FACHDATA_H
