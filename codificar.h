#ifndef CODIFICAR_H
#define CODIFICAR_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <math.h>
#include <exception>

using namespace std;
//menu ejercicio de codificación
void principal();
void Metodo1Char();
void Metodo2str();

//metodo de codificacion2 string
//codificar
string LeerArchivo_txt(string);
string Str_to_Binary(string);
string codificacion2(string, int);
string Cambiar_pos(string);
void EscribirArchivo_dat(string,string);
//decodificar
string LeerArchivo_dat(string);
string decodificacion2(string, int);
string cambiar_decof(string);
string Binary_to_Str(string);
void EscribirArchivo_txt(string,string);

#endif // CODIFICAR_H
