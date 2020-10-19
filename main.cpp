#include "cajero.h"

int main()
{
    int opc=0;
    while (opc!=0) {
    cout<<"Ingrese:\n1. para usar metodos de codificacion y decodificacion.\n2.Para usar cajero.\n0. Para salir.\n";
    cout<<"Selecione una opcion: ";cin>>opc;
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
    }
    return 0;
}
