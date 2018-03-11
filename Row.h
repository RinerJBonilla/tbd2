//
// Created by miriam trochez on 05/03/2018.
//

#ifndef TBD2_ROW_H
#define TBD2_ROW_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

class Row {
public:
    Row();
    Row(int lig,char* datas);
    char* toChar(int lig);
    void chatToRow(int lig,char* datos);
    char* datal;

};


#endif //TBD2_ROW_H
