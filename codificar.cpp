#include "codificar.h"

//menu ejercicio de codificar
void principal()
{
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
void Metodo2str()
{
    int opc = 0;
    string archivo,texto;
    int semilla;
    cout <<"Ingrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
    cout <<"Seleccione -> ";cin>>opc;
    while(opc!=0){
        switch (opc) {

        case 1:{
            //codificar
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo de texto a codificar ej(archivo.txt)." << endl;
            cout << "Nombre: ";getline(cin,archivo);
            cout << "Ingrese la semilla de codificacion -> ";cin >> semilla;
            texto = LeerArchivo_txt(archivo);
            texto = codificacion2(texto,semilla);
            cin.ignore(10000,'\n');
            cout << "Ingrse nombre del archivo .dat a guardar archivo codificado ej(codificado.dat)" << endl;
            cout << "Nombre: ";getline(cin,archivo);
            EscribirArchivo_dat(archivo,texto);
        }
            break;
        case 2:{
            //decodificar
            cin.ignore(10000,'\n');
            cout << "Ingrese el nombre del archivo a decodificar (el archivo debe existir y ser .dat ej codificado.dat)\n";
            cout << "Nombre: ";getline(cin,archivo);
            cout << "Ingrese la semilla de decodificacion -> ";cin >> semilla;
            texto = LeerArchivo_dat(archivo);
            texto = decodificacion2(texto,semilla);
            cout << texto;
        }
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << endl;
        cout <<"Ingrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
        cout <<"Seleccione -> ";cin>>opc;
    }
}

string LeerArchivo_txt(string archivo)
{
    //leer archivo
    string texto="",linea = "";
    fstream lectura;
    lectura.open(archivo,fstream::in);
    if(lectura.fail())
        throw '1';
    while(lectura.good()){
        getline(lectura,linea);
        texto.append(linea);
        texto.append("\n");
    }
    lectura.close();
    texto.pop_back();
    texto = Str_to_Binary(texto);

    return texto;
}

string Str_to_Binary(string texto)
{
    //string a binario
    string binario;
    for(unsigned long long int i=0; i<texto.length(); i++){
        for(int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}

string codificacion2(string texto, int semilla)
{
    //metodo de codificacion 2
    string parte,codificado;
    if(semilla < int(texto.length()))  {
        for(unsigned long long int i=0;i<texto.length();i+=semilla){
            if(i+semilla<texto.length())
                parte = texto.substr(i,semilla);
            else
                parte = texto.substr(i);
            codificado.append(Cambiar_pos(parte));
            parte.clear();
        }
    }
    else
        codificado.append(Cambiar_pos(texto));
    return codificado;
}

string Cambiar_pos(string binario)
{
    string binarioCodif;
    binarioCodif += binario[binario.length()-1];
    for(int i=0; i<int(binario.length())-1; i++){
        binarioCodif += binario[i];
    }
    return binarioCodif;
}


void EscribirArchivo_dat(string archivo,string texto)
{
    fstream escribir;
    escribir.open(archivo,fstream::out|fstream::binary);
    if(escribir.fail())
        throw '2';
    escribir<<texto;
    escribir.close();
}



string LeerArchivo_dat(string archivo)
{
    //leer archivo
    string texto="",linea = "";
    fstream lectura;
    lectura.open(archivo,fstream::in);
    if(lectura.fail())
        throw '1';
    while(lectura.good()){
        getline(lectura,linea);
        texto.append(linea);
        texto.append("\n");
    }
    lectura.close();
    texto.pop_back();
    return texto;

}

string decodificacion2(string texto, int semilla)
{
    //metodo de decodificacion 2
    string parte,decodificado;
    if(semilla < int(texto.length()))  {
        for(unsigned long long int i=0;i<texto.length();i+=semilla){
            if(i+semilla<texto.length())
                parte = texto.substr(i,semilla);
            else
                parte = texto.substr(i);
            decodificado.append(cambiar_decof(parte));

            parte.clear();
        }
    }
    else
        decodificado.append(cambiar_decof(texto));

    return decodificado;
}

string cambiar_decof(string binario)
{
    string binario_decof;
    binario_decof += binario[1];
    for(int i=2; i<int(binario.length()); i++){
        binario_decof += binario[i];
    }
    binario_decof += binario[0];
    return binario_decof;
}
