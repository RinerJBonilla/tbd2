//
// Created by miriam trochez on 05/03/2018.
//

#ifndef TBD2_DATAFILE_H
#define TBD2_DATAFILE_H
#include <stdio.h>
#include <io.h>


class DataFile {
public:
    DataFile();
    DataFile(char * path);
    void abrir();
    void cerrar();
    void escbrir(char* data, int pos, int longitud);
    char* leer(int pos, int longitud);
    int longituder();
    char* pathy;
    FILE* dFile;
    bool isEmpety();
    virtual ~DataFile();

protected:

private:

};


#endif //TBD2_DATAFILE_H
