#include "cajero.h"


void inicio()
{
    try {
        int opc;
        cout<<"Preisione:\n1. Para ingresar como administrador.\n2. para ingresar como usuario.\n0.Para salir.\n";
        cout<<"Selecione una opcion: ";cin>>opc;
        while(opc!=0){
            switch (opc) {
            case 1:{
            }
                break;
            case 2:{

                }
                break;
            default:
                cout<<"Opcion no valida.\n";
            }
        }
    } catch (char c) {
        if(c=='1')
            cout<<"Error al abrir el archivo de lectura.\n";
        else if(c=='2')
            cout<<"Error al abrir el archivo de escritura.\n";
    }
}
