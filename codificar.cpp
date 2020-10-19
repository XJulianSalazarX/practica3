#include "codificar.h"

void principal(){
    try{
        int opc=0;
        cout << "Ingrese:\n1.Para usar string.\n2.Para usar char.\n0. pasar salir.\n";
        cout << "Eliga una opcion -> ";cin >> opc;
        while (opc != 0){
            switch (opc) {
            case 1:{
                Str();
            }
                break;
            case 2:{
                Char();
            }
                break;
            default:
                cout << "Opcion no valida" << endl;
            }
        }
    }catch (char c) {
        if(c=='1')
            cout<<"error al abrir el archivo de lectura \n";
        else if(c=='2')
            cout<<"error al abrir el archivo de escritura \n";
    }catch(exception ex){
        cout <<ex.what()<<endl;
    }


}

void Str(){
    int opc=0;
    while(opc!=0){
        cout << "Ingrese:\n1.Usar el metodo 1.\n2.Usar el metodo 2.\n0.Salir.\n";
        cout << "Eliga una opcion ->";cin >> opc;
        switch (opc) {
        case 1:{
            Metodo1str();
        }
            break;

        case 2:{
            Metodo2str();
        }
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    }
}

void Char(){
    int opc=0;
    while(opc!=0){
        cout << "Ingrese:\n1.Usar el metodo 1.\n2.Usar el metodo 2.\n0.Salir.\n";
        cout << "Eliga una opcion ->";cin >> opc;
        switch (opc) {
        case 1:{
            Metodo1Char();
        }
            break;

        case 2:{
            Metodo2Char();
        }
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    }
}

void Metodo1str(){

}

void Metodo2str(){

}

void Metodo1Char(){

}

void Metodo2Char(){

}
