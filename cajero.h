#ifndef CAJERO_H
#define CAJERO_H
#include "codificar.h"

//menu del cajero
void inicio();
void administrador();
void usuario();

//como administrador
bool ClaveAdmin();
void NuevoUsuario();
void VerInfoUsuarios();
void RegistrarUsuario();


//como usuario


string CodificarInfo(string);
string DecodificarInfo(string);
bool ComprobarCedula(string);

#endif // CAJERO_H
