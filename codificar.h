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

//metodo de codificacion1 char
void Char_to_Binary(char *,char *,long long int);
void Binary_to_Char(char *,char *,long long int);
long long int Longitud_Archivo(char *);
//codificar
void LeerArchivoChar_txt(char *, char*);
void codificacion1(int, char *, long long int);
void EscribirArchivoChar_dat(char *, char *);

//decodificar
void LeerArchivoChar_dat(char *, char *);
void decodificacion1(int, char *, long long int);
void EscribirArchivoChar_txt(char *, char *);


//metodo de codificacion2 string
string Str_to_Binary(string);
string Binary_to_Str(string);
//codificar
string LeerArchivo_txt(string);
string codificacion2(string, int);
string Cambiar_pos(string);
void EscribirArchivo_dat(string,string);
//decodificar
string LeerArchivo_dat(string);
string decodificacion2(string, int);
string cambiar_decof(string);
void EscribirArchivo_txt(string,string);

#endif // CODIFICAR_H
