#include <iostream>
#include <fstream>
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
#include "FachData.h"

using namespace std;
template <class Container>
void split2(const std::string& str, Container& cont, char delim = ':')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

int main() {


    FachData* lol = new FachData();
    while(lol->run()){};


//    char* pat = "C:/Users/miriam trochez/CLionProjects/TBD2/test.datab";
//
//    std::vector<std::string> words;
//
//    RowBloque* gg = new RowBloque(0,pat);
//
//
//    gg->cargar(66);
//    cout<<gg->Rows->size()<<endl;
//    cout<<gg->cantEntradas<<endl;
//    for(std::list<char*>::iterator it = gg->Rows->begin(); it != gg->Rows->end(); it++)
//    {
//        char* teb = *it;
//        cout<<teb<<endl;
//        split2(teb, words);
//        std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
//        cout<<"--------------"<<endl;
//        words.clear();
//    }
//
//    char* str=new char[66];
//    cin.getline(str,200);
//    gg->Rows->push_back(str);
//    gg->cantEntradas++;
//    gg->escribir(66);


    return 0;
}

