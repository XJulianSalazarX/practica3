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
void EliminarUsuario();


//como usuario


void CodificarInfo(string);
string DecodificarInfo(string);
bool ComprobarCedula(string);
bool SoloNumeros(string);

#endif // CAJERO_H
