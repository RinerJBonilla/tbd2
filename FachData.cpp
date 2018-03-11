//
// Created by miriam trochez on 07/03/2018.
//

#include "FachData.h"

FachData::FachData() {
}

bool FachData::run() {
    getQuery();
    if (words[0] == "exit") {
        std::cout << "\nBye\n";
        return false;
    }
    executeQuery();
    return true;
}

void FachData::getQuery() {
    str = new char[200];
    words.clear();
    subwords.clear();
    cin.getline(str,200);
    split1(str, words);
}

void FachData::executeQuery() {
    if (words[0] == "create") {
        executeCREATE();
        delete[] str;
    }
    if (words[0] == "insert") {
        executeINSERT();
        delete[] str;
    }
    if (words[0] == "delete") {
        executeDELETE();
    }
    if (words[0] == "update") {
        executeUPDATE();
        delete[] str;
    }
    if (words[0] == "select") {
        executeSELECT();
        delete[] str;
    }
    if (words[0] == "set") {
        executeSET();
        delete[] str;
    }

}

void FachData::executeSET() {
    char* plis = new char[words[2].size()+1];
    strcpy(plis,words[2].c_str());
    string sts = "C:/Users/miriam trochez/CLionProjects/TBD2/";
    sts+=plis;
    sts+=".datab";
    char* pathh2 = new char[sts.length()];
    strcpy(pathh2,sts.c_str());
    DataFile* tempi = new DataFile(pathh2);
    if(tempi->isEmpety())
    {
        cout<<"DATABASE NOT FOUND!"<<endl;
        delete tempi;
    } else{
        pathh = new char[sts.length()];
        strcpy(pathh,sts.c_str());
        tablos = new DataBloque(0,pathh);
        tablos->cargar();
        cout<<"DATABASE SET!"<<endl;
    }
    delete plis,pathh2;
    delete tempi;
    sts.clear();

}

void FachData::executeCREATE() {
    if(words[1] == "database")
    {
        char* plis = new char[words[2].size()+1];
        strcpy(plis,words[2].c_str());
        string sts = "C:/Users/miriam trochez/CLionProjects/TBD2/";
        sts+=plis;
        sts+=".datab";
        pathh = new char[sts.length()];
        strcpy(pathh,sts.c_str());
        cout<<pathh<<endl;
        tablos = new DataBloque(0,pathh);
        tablos->siguiente=1;
        tablos->escribir();
        delete plis;
        plis= nullptr;
        sts.clear();
    }
    if(words[1] == "table")
    {
        Table* primera = nullptr;
        int canti=0;
        int lengi=0;
        for(int i=2; i<words.size();i++)
        {
            if(i==2)
            {
                char* temp = new char[words[i].size()];
                strcpy(temp,words[i].c_str());
                primera = new Table(temp);
                primera->primerBloqueCol = tablos->siguiente;
                tablos->siguiente++;
                tablos->cantEntradas++;
                cout<<"table "<<temp<<" created"<<endl;
                delete temp;
                temp= nullptr;
            } else{
                split2(words[i],subwords);

                char* temp1 = new char[20];
                char* temp2 = new char[20];
                cout<<"------"<<endl;
                strcpy(temp1,subwords[0].c_str());
                strcpy(temp2,subwords[1].c_str());
                Column* colonia = new Column();
                cout<<"columna nueva"<<endl;
                strcpy(colonia->name,temp1);
                strcpy(colonia->dataType,temp2);
                colonia->dataLength= std::stoi(subwords[2]);
                cout<<colonia->name<<endl;
                cout<<colonia->dataType<<endl;
                cout<<colonia->dataLength<<endl;
                lengi+=colonia->dataLength;
                primera->campero->push_back(colonia);
                cout<<"column "<<colonia->name<<" created"<<endl;
                canti++;
                subwords.clear();
                delete temp1,temp2;
                delete colonia;
            }
        }
        primera->cantCol=canti;
        primera->regLength=lengi+(canti-1);
        cout<<"cant col: "<<canti<<endl;
        cout<<"leng reg: "<<lengi<<endl;
        tablos->Tablas->push_back(primera);
        ColumnBloque* colu = new ColumnBloque(primera->primerBloqueCol,pathh);
        colu->Columnas = primera->campero;
        colu->cantEntradas=canti;
        tablos->escribir();
        colu->escribir();
        cout<<"cant tablas: "<<tablos->cantEntradas<<endl;
        cout<<"cant tablas: "<<tablos->Tablas->size()<<endl;
        delete colu,primera;
    }
}

void FachData::executeINSERT() {
    if(words[1] == "into")
    {
        char* tempo = new char[words[2].length()];
        strcpy(tempo,words[2].c_str());
        for(std::list<Table*>::iterator it = tablos->Tablas->begin(); it != tablos->Tablas->end(); it++)
        {
            Table* tabTable = *it;
            if (strcmp(tabTable->nomber,tempo) == 0)
            {
                if(tabTable->primerBloqueReg==-1)
                {
                    cout<<"bloque reg antes: "<<tabTable->primerBloqueReg<<endl;
                    tablos->siguiente++;
                    tabTable->primerBloqueReg=tablos->siguiente;
                    tabTable->cantReg++;
                    RowBloque* gg = new RowBloque(tabTable->primerBloqueReg,pathh);
                    char* strr=new char[tabTable->regLength];
                    strcpy(strr,words[3].c_str());
                    gg->Rows->push_back(strr);
                    gg->cantEntradas++;
                    gg->escribir(tabTable->regLength);
                    cout<<"bloque reg despues: "<<tabTable->primerBloqueReg<<endl;
                    tablos->escribir();
                    delete gg;
                    delete strr;
                    strr= nullptr;
                    break;
                }
                else{
                    cout<<"bloque reg antes: "<<tabTable->primerBloqueReg<<endl;
                    RowBloque* gg = new RowBloque(tabTable->primerBloqueReg,pathh);
                    gg->cargar(tabTable->regLength);
                    char* strr=new char[tabTable->regLength];
                    strcpy(strr,words[3].c_str());
                    gg->Rows->push_back(strr);
                    gg->cantEntradas++;
                    gg->escribir(tabTable->regLength);
                    tabTable->cantReg++;
                    tablos->escribir();
                    cout<<"bloque reg despues: "<<tabTable->primerBloqueReg<<endl;
                    delete gg;
                    delete strr;
                    strr= nullptr;
                    break;
                }
            }
            delete tabTable;
        }
        cout<<"ROW INSTERTED"<<endl;
        tablos->escribir();
        delete tempo;
        tempo= nullptr;
    }
}

void FachData::executeDELETE() {
    if(words[1] == "database")
    {
        char* plis = new char[words[2].size()+1];
        strcpy(plis,words[2].c_str());
        string sts = "C:/Users/miriam trochez/CLionProjects/TBD2/";
        sts+=plis;
        sts+=".datab";
        plis = new char[sts.length()];
        strcpy(plis,sts.c_str());
        if( std::remove(plis) != 0 )
            perror( "Error deleting DATABASE" );
        else
            puts( "DATABASE successfully deleted" );
        delete plis;
        sts.clear();
    }
    if(words[1] == "table")
    {
        tablos->cargar();
        char* tempo = new char[words[2].length()];
        strcpy(tempo,words[2].c_str());
        int ip=0;
        for(std::list<Table*>::iterator it = tablos->Tablas->begin(); it != tablos->Tablas->end(); it++)
        {
            Table * tabTemp = *it;
            if (strcmp(tabTemp->nomber,tempo) == 0)
            {
                //Bloque* borr = new Bloque(tabTemp->primerBloqueCol,pathh);
                //borr->escribir();

//                if(tabTemp->primerBloqueReg!=-1)
//                {
//                    borr = new Bloque(tabTemp->primerBloqueReg,pathh);
//                    borr->escribir();
//                }
                //delete borr;
                tablos->Tablas->remove(tabTemp);
                tablos->cantEntradas--;
                cout<<"cant tablas: "<<tablos->Tablas->size()<<endl;
                cout<<"cant entries: "<<tablos->cantEntradas<<endl;
                tablos->escribir();
                cout<<"Table "<<tempo<<" Deleted"<<endl;
                break;
            }
            delete tabTemp;
            ip++;
        }
        cout<<"Table Not Found!"<<endl;
        delete tempo;
    }
}

void FachData::executeUPDATE() {

}

void FachData::executeSELECT() {
    cout<<"cant tablas: "<<tablos->Tablas->size()<<endl;
    cout<<"cant tablas: "<<tablos->cantEntradas<<endl;
    if(words[1] == "tables")
    {
        for(std::list<Table*>::iterator it = tablos->Tablas->begin(); it != tablos->Tablas->end(); it++)
        {
            Table * tabTemp = *it;
            ColumnBloque* colu = new ColumnBloque(tabTemp->primerBloqueCol,pathh);
            colu->cargar();
            tabTemp->campero = colu->Columnas;
            cout<<"TABLE: "<<tabTemp->nomber<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            for(std::list<Column*>::iterator ib = tabTemp->campero->begin(); ib != tabTemp->campero->end(); ib++){
                Column* colTemp = *ib;
                cout<<colTemp->name<<"("<<colTemp->dataType<<")"<<"          "<<"||";
                delete colTemp;
            }
            cout<<"|"<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            if(tabTemp->primerBloqueReg==-1)
            {
                cout<<"-"<<endl;
            } else{
                RowBloque* gg = new RowBloque(tabTemp->primerBloqueReg,pathh);
                gg->cargar(tabTemp->regLength);
                for(std::list<char*>::iterator it = gg->Rows->begin(); it != gg->Rows->end(); it++)
                {
                    char* teb = *it;
                    split2(teb, subwords);
                    for(int i=0; i<subwords.size();i++)
                    {
                        cout<<subwords[i]<<"          "<<"||";
                    }
                    cout<<"|"<<endl;
                    subwords.clear();
                    delete teb;
                }
                delete gg;
            }
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<" "<<endl;
            delete tabTemp,colu;
        }
        cout<<"DATABASE EMPTY"<<endl;
    }
    if(words[1] == "table")
    {
        char* tempo = new char[words[2].length()];
        strcpy(tempo,words[2].c_str());
        for(std::list<Table*>::iterator it = tablos->Tablas->begin(); it != tablos->Tablas->end(); it++)
        {
            Table * tabTemp = *it;
            if (strcmp(tabTemp->nomber,tempo) == 0) {
                ColumnBloque* colu = new ColumnBloque(tabTemp->primerBloqueCol,pathh);
                colu->cargar();
                tabTemp->campero = colu->Columnas;
                cout<<"TABLE: "<<tabTemp->nomber<<endl;
                cout<<"-----------------------------------------------------------------------------"<<endl;
                for(std::list<Column*>::iterator ib = tabTemp->campero->begin(); ib != tabTemp->campero->end(); ib++){
                    Column* colTemp = *ib;
                    cout<<colTemp->name<<"("<<colTemp->dataType<<")"<<"          "<<"||";
                    delete colTemp;
                }
                cout<<"|"<<endl;
                cout<<"-----------------------------------------------------------------------------"<<endl;
                if(tabTemp->primerBloqueReg==-1)
                {
                    cout<<"-"<<endl;
                } else{
                    RowBloque* gg = new RowBloque(tabTemp->primerBloqueReg,pathh);
                    gg->cargar(tabTemp->regLength);
                    for(std::list<char*>::iterator it = gg->Rows->begin(); it != gg->Rows->end(); it++)
                    {
                        char* teb = *it;
                        split2(teb, subwords);
                        for(int i=0; i<subwords.size();i++)
                        {
                            cout<<subwords[i]<<"          "<<"||";
                        }
                        cout<<"|"<<endl;
                        subwords.clear();
                        delete teb;
                    }
                    delete gg;
                }
                cout<<"-----------------------------------------------------------------------------"<<endl;
                cout<<" "<<endl;
                delete colu;

            }
            delete tabTemp;
        }
        delete tempo;
        cout<<"TABLE: "<<tempo<<" NOT FOUND"<<endl;
    }
}

template<class Container>
void FachData::split1(const std::string &str, Container &cont, char delim) {
    delim = ' ';
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

template<class Container>
void FachData::split2(const std::string &str, Container &cont, char delim) {
    delim = ':';
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}
