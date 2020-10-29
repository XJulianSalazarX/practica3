#include "archivos.h"

void MenuArchivos()
{
    int opc;
    cout << "\n------------------Menu Archivos------------------\n";
    cout << "Seleccione:\n1.Crear archivo.\n2.ELiminar archivo.\n0.Salir.\n";
    cout << "Seleccione: ";cin >> opc;
    while(opc!=0){
        switch (opc) {
        case 1:{
            CrearArchivos();
        }
            break;
        case 2:{
            EliminarArchivos();
        }
            break;
        default:
            cout << "Opcion no valida.\n";
        }
        cout << "\n------------------Menu Archivos------------------\n";
        cout << "Seleccione:\n1.Crear archivo.\n2.ELiminar archivo.\n0.Salir.\n";
        cout << "Seleccione: ";cin >> opc;
    }
}

void CrearArchivos()
{
    string archivo,texto;
    fstream Escribir;
    cout << "Nombre del archivo: ";cin >> archivo;
    cin.ignore(10000,'\n');
    cout << "Ingrese el texto que va a llevar el archivo:\n";getline(cin,texto);
    Escribir.open(archivo,fstream::out|fstream::binary);
    if(Escribir.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    Escribir<<texto;
    Escribir.close();
    cout << "Archivo creado con exito.\n";
}

void EliminarArchivos()
{
    string archivo;
    cout << "Nombre del archivo: ";cin >> archivo;
    if(ifstream(archivo)){
        remove(archivo.c_str());
        cout << "Archivo eliminado.\n";
    }
    else{
        cout << "El archivo no existe.\n";
        exit(1);
    }
}
