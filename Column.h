//
// Created by miriam trochez on 05/03/2018.
//

#ifndef TBD2_COLUMN_H
#define TBD2_COLUMN_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <stdio.h>
#include <string.h>

using namespace std;

class Column {
public:
    Column();
    Column(char*, char*, int);
    char* getName();
    char* getDataType();
    int getDataLength();
    char* toChar();
    void chatToColumn(char* datos);
    char name[20];
    char dataType[20];
    int dataLength;

};


#endif //TBD2_COLUMN_H
