cmake_minimum_required(VERSION 3.8)
project(TBD2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DataFile.cpp DataFile.h Bloque.cpp Bloque.h Row.cpp Row.h Column.cpp Column.h Table.cpp Table.h DataBloque.cpp DataBloque.h ColumnBloque.cpp ColumnBloque.h RowBloque.cpp RowBloque.h FachData.cpp FachData.h)
add_executable(TBD2 ${SOURCE_FILES})