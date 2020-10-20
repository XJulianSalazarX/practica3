#include "codificar.h"
//menu ejercicio de codificar
void principal(){
    try{
        int opc=0;
        cout << "Ingrese:\n1.Usar metodo1 (char).\n2.Usar metodo2 (string).\n0.Salir.\n";
        cout << "Eliga una opcion -> ";cin >> opc;
        while (opc != 0){
            switch (opc) {
            case 1:{
                Metodo1Char();
            }
                break;
            case 2:{
                Metodo2str();
            }
                break;
            default:
                cout << "Opcion no valida" << endl;
            }
            cout << endl;
            cout << "Ingrese:\n1.Usar metodo1 (char).\n2.Usar metodo2 (string).\n0.Salir.\n";
            cout << "Eliga una opcion -> ";cin >> opc;
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

//metodo1 char
void Metodo1Char(){

}

//metodo 2 string
void Metodo2str(){
    string archivo,codificar;
    cin.ignore(10000,'\n');
    cout << "Ingrese nombre del archivo de texto a codificar ej(codificar.txt)." << endl;
    cout << "Nombre: ";getline(cin,archivo);
    codificar = LeerArchivo_txt(archivo);
    cout << endl;
}



string LeerArchivo_txt(string archivo)
{
    string texto="",linea = "";
    ifstream lectura;
    lectura.open(archivo.c_str());
    if(lectura.fail())
        throw '1';
    while(lectura.good()){
        getline(lectura,linea);
        texto += linea;
        texto += "\n";
    }
    texto = Str_to_Binary(texto);

    return texto;
}

string Str_to_Binary(string texto)
{
    string binario;
    for(unsigned long long int i=0; i<texto.length(); i++){
        for(int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}
