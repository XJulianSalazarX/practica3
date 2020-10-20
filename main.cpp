#include "cajero.h"

int main()
{
    int opc=0;
    cout<<"Ingrese:\n1.Usar metodos de codificacion y decodificacion.\n2.Usar cajero.\n0. Para salir.\n";
    cout<<"Selecione una opcion: ";cin>>opc;
    while (opc!=0) {
        switch (opc) {
        case 1:{
            principal();
        }
            break;
        case 2:{

        }
        case 0:
            break;
        default:
            cout<<"Opcion no valida.\n";
        }
        cout << endl;
        cout<<"Ingrese:\n1. para usar metodos de codificacion y decodificacion.\n2.Para usar cajero.\n0. Para salir.\n";
        cout<<"Selecione una opcion: ";cin>>opc;
    }
    return 0;
}
