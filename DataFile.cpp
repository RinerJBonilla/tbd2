//
// Created by miriam trochez on 05/03/2018.
//

#include "DataFile.h"

DataFile::DataFile()
{
    pathy=0;
}

DataFile::~DataFile()
{
    //dtor
}
DataFile::DataFile(char* path)
{
    this->pathy = path;
    if( (_access( pathy, 0 )) == -1 )
    {
        dFile=fopen(pathy,"wb+");
        cerrar();
    }
}

void DataFile::abrir()
{
    dFile = fopen(pathy,"rb+");
}

void DataFile::cerrar()
{
    fclose(dFile);
}

void DataFile::escbrir(char* data, int pos, int longitud)
{
    abrir();
    fseek(dFile,pos,SEEK_SET);
    fwrite(data,1,longitud,dFile);
    cerrar();
}

char* DataFile::leer(int pos, int longitud)
{
    char* buffer = new char[longitud];
    abrir();
    fseek(dFile,pos,SEEK_SET);
    fread(buffer,1,longitud,dFile);
    return buffer;
}

int DataFile::longituder()
{
    abrir();
    fseek(dFile, 0, SEEK_END);
    long longitud = ftell(dFile);
    return longitud;
}

bool DataFile::isEmpety() {
    abrir();
    fseek(dFile,0,SEEK_END);
    return ftell(dFile)>0 ? false:true;
}
