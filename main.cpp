#include "cajero.h"
#include "archivos.h"
/*
 Integrantes:
    -Diego Zuluaga.
    -Julian Salazar.
 */
int main()
{
    int opc=0;
    cout << "----------------Seccion principal----------------\n";
    cout<<"Ingrese:\n1.Usar metodos de codificacion y decodificacion.\n2.Usar cajero.\n3.Crear\\Eliminar archivo.\n0. Para salir.\n";
    cout<<"Selecione una opcion: ";cin>>opc;
    while (opc!=0) {
        switch (opc) {
        case 1:{
            principal();
        }
            break;
        case 2:{
            inicio();
        }
            break;
        case 3:{
            MenuArchivos();
        }
            break;
        default:
            cout<<"Opcion no valida.\n";
        }
        cout << endl;
        cout << "----------------Seccion principal----------------\n";
        cout<<"Ingrese:\n1.Usar metodos de codificacion y decodificacion.\n2.Usar cajero.\n0.Salir.\n";
        cout<<"Selecione una opcion -> ";cin>>opc;
    }
    return 0;
}
