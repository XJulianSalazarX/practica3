#include "codificar.h"

//menu ejercicio de codificar
void principal()
{
    try{
        int opc=0;
        cout<<"\n----------Seleccion de metodo----------\n";
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
            cout<<"----------Seleccion de metodo----------\n";
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
void Metodo1Char()
{

    int opc=0,semilla=0;
    long long int longitud;
    char *archivo=NULL,*texto=NULL,*binario=NULL;
    cout <<"\nIngrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
    cout <<"Seleccione -> ";cin>>opc;
    while(opc!=0){
        switch (opc){
        case 1:{
            cout << "Ingrese el numero de caractres del archivo.txt -> ";cin >> longitud;
            archivo = new char[longitud+1];
            fflush(stdin);   
            cout << "Ingrese nombre del archivo de texto a codificar ej(archivo.txt)." << endl;
            cout << "Nombre: ";gets(archivo);
            cout << "Ingrese la semilla de codificacion -> ";cin >> semilla;
            archivo[longitud] = '\0';
            //longitud del archivo
            longitud = Longitud_Archivo(archivo);
            //inicio de las variables
            texto = new char[longitud+1];
            binario = new char[longitud*8+1];
            binario[longitud*8] = '\0';
            //guarda en texto lo que se encuntra en el archivo
            LeerArchivoChar_txt(archivo,texto);
            texto[longitud] = '\0';
            //pasa de caracteres a binario
            Char_to_Binary(texto,binario,longitud);
            binario[longitud*8] = '\0';
            //codifica binario
            codificacion1(semilla,binario,longitud);
            binario[longitud*8] = '\0';
            //pasa de binario a caracteres
            Binary_to_Char(binario,texto,longitud);
            texto[longitud] = '\0';

            delete [] archivo;
            cout << "Ingrese el numero de caractres donde guardar el archivo codificado .dat -> ";cin >> longitud;
            archivo = new char[longitud+1];
            fflush(stdin);
            cout << "Ingrese nombre del archivo .dat donde guardar el archivo codificado ej(codificado.dat)" << endl;
            cout << "Nombre: ";gets(archivo);
            archivo[longitud] = '\0';
            //guarda en el .dat lo que hay en texto
            EscribirArchivoChar_dat(archivo,texto);

            delete [] texto;
            delete [] binario;
            delete [] archivo;
        }
            break;
        case 2:{
            cout << "Ingrese el numero de caractres del archivo .dat a decodificar -> ";cin >> longitud;
            archivo = new char[longitud+1];
            fflush(stdin);
            cout << "Ingrese el nombre del archivo a decodificar (el archivo debe existir y ser .dat ej codificado.dat)\n";
            cout << "Nombre: ";gets(archivo);
            cout << "Ingrese la semilla de decodificacion -> ";cin >> semilla;
            archivo[longitud] = '\0';
            //longitud del archivo
            longitud = Longitud_Archivo(archivo);
            //inicio de las variables
            texto = new char[longitud+1];
            binario = new char[longitud*8+1];
            binario[longitud*8] = '\0';
            //guarda en texto lo que se encuntra en el archivo
            LeerArchivoChar_dat(archivo,texto);
            texto[longitud] = '\0';
            //pasa de caracteres a binario
            Char_to_Binary(texto,binario,longitud);
            binario[longitud*8] = '\0';
            //decodifica binario
            decodificacion1(semilla,binario,longitud);
            binario[longitud*8] = '\0';
            //pasa de binario a caracteres
            Binary_to_Char(binario,texto,longitud);
            texto[longitud] = '\0';

            delete [] archivo;
            cout << "Ingrese el numero de caractres del archivo .txt donde gardar el archivo decodificado -> ";cin >> longitud;
            archivo = new char[longitud+1];
            fflush(stdin);
            cout << "Ingrese nombre del archivo .dat donde guardar el archivo decodificado ej(prueba.txt)" << endl;
            cout << "Nombre: ";gets(archivo);
            archivo[longitud] = '\0';
            //guarda en el .dat lo que hay en texto
            EscribirArchivoChar_dat(archivo,texto);

            delete [] binario;
            delete [] texto;
            delete [] archivo;
        }
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout <<"\nIngrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
        cout <<"Seleccione -> ";cin>>opc;
    }
}

//metodo 2 string
void Metodo2str()
{
    int opc = 0,semilla=0;
    string archivo,texto;
    cout <<"\nIngrese:\n1.Para codificar archivo.\n2.Para decodificar archivo.\n0.Salir.\n";
    cout <<"Seleccione -> ";cin>>opc;
    while(opc!=0){
        switch (opc){

        case 1:{
            //codificar
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo de texto a codificar ej(archivo.txt)." << endl;
            cout << "Nombre: ";getline(cin,archivo);
            cout << "Ingrese la semilla de codificacion -> ";cin >> semilla;
            texto = LeerArchivo_txt(archivo);
            texto = Str_to_Binary(texto);
            texto = codificacion2(texto,semilla);
            texto = Binary_to_Str(texto);
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo .dat donde guardar el archivo codificado ej(codificado.dat)" << endl;
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
            texto = Str_to_Binary(texto);
            texto = decodificacion2(texto,semilla);
            texto = Binary_to_Str(texto);
            cin.ignore(10000,'\n');
            cout << "Ingrese nombre del archivo donde guardar el archivo decodificado ej(prueba.txt)" << endl;
            cout << "Nombre: ";getline(cin,archivo);
            EscribirArchivo_txt(archivo,texto);
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

string Binary_to_Str(string binario)
{
//    int exp=0, num=0;
//    string texto;
//    for(long long int i=0; i<int(binario.size());i++){
//        for(int j=7;j>=0;j--){
//            num+=(int(binario[j+8*i])-48)*pow(2,exp);
//            exp++;
//        }
//        texto += num;
//        num=0;
//        exp=0;
//    }
    string caracter,texto;
    for(int i=0; i<int(binario.length());i+=8){
        caracter = binario.substr(i,8);
        caracter = stoi(caracter, nullptr, 2);
        texto.append(caracter);
    }
    return texto;
}

void EscribirArchivo_txt(string archivo,string texto)
{
    fstream escribir;
    escribir.open(archivo,fstream::out);
    if(escribir.fail())
        throw '2';
    escribir<<texto;
    escribir.close();
}

//metodo1 char
long long int Longitud_Archivo(char *archivo)
{

    long long int longitud=0;
    fstream lectura;
    lectura.open(archivo, fstream::in);
    if(lectura.fail())
        throw '2';
    while(lectura.good()){
       lectura.get();
       longitud ++;
    }
    lectura.close();
    longitud --;
    return longitud;
}

void LeerArchivoChar_txt(char *archivo, char *texto)
{
    int pos=0;
    fstream lectura;
    lectura.open(archivo,fstream::in);
    if(lectura.fail())
        throw '1';
    while(lectura.good()){
        texto[pos] =lectura.get();
        pos ++;
    }
    lectura.close();
}

void Char_to_Binary(char *texto,char *binario,long long int longitud)
{

    long long int pos = 0;
    for(long long int i=0; i<longitud; i++){
        for(int j=0;j<8;j++){
            binario[pos]=((((texto[i]<<j)&(0x80))/128)+48);
            pos ++;
        }
    }
}

void Binary_to_Char(char *binario, char *texto, long long int longitud)
{
    int exp=0, num=0;
    for(int i=0; i<longitud;i++){
        for(int j=7;j>=0;j--){
            num+=(int(binario[j+8*i])-48)*pow(2,exp);
            exp++;
        }
        texto[i]=num;
        num=0;
        exp=0;
    }
}

void EscribirArchivoChar_dat(char *archivo, char *texto)
{
    fstream escribir;
    escribir.open(archivo,fstream::out|fstream::binary);
    if(escribir.fail())
        throw '2';
    escribir<<texto;
    escribir.close();
}

void LeerArchivoChar_dat(char *archivo, char *texto)
{
    int pos=0;
    fstream lectura;
    lectura.open(archivo,fstream::in);
    if(lectura.fail())
        throw '1';
    while(lectura.good()){
        texto[pos] =lectura.get();
        pos ++;
    }
    lectura.close();
}

void EscribirArchivoChar_txt(char *archivo, char *texto)
{
    fstream escribir;
    escribir.open(archivo,fstream::out);
    if(escribir.fail())
        throw '2';
    escribir<<texto;
    escribir.close();
}

void codificacion1(int semilla, char *bin,long long int longitud)
{
    char *bincod;
    bincod = new char[longitud*8+1];
    bincod[longitud*8] = '\0';

    long long int pos=0;

    for(int i=0; i<semilla;i++){
        if(pos==longitud*8) break;

        if(bin[i]==49){
            bincod[pos] = '0';
            pos ++;
        }

        else{
            bincod[pos]='1';
            pos ++;
        }
    }

    long long int j=0;
    int cont0=0,cont1=0;

    while (j+semilla<longitud*8){
        int con=0;

        for(int k=0;k<semilla;k++,j++){
            if(bin[j]==48) cont0++;
            else if(bin[j]==49) cont1++;
        }

        if(cont0>cont1){
            for(int num=0;num<semilla;j++,num++){

                if(pos==longitud*8) break;
                if(con==1){
                    if(bin[j]==49){
                        bincod[pos] = '0';
                        pos ++;
                    }
                    else{
                        bincod[pos] = '1';
                        pos ++;
                    }
                    con = 0;
                }
                else{
                    bincod[pos] = bin[j];
                    pos ++;
                    con=con+1;
                }
            }
            j=j-semilla;
        }

        else if(cont0<cont1){
            for(int num=0;num<semilla ;j++,num++){
                if(pos==longitud*8) break;

                if(con==2){
                    if(bin[j]==49){
                        bincod[pos] = '0';
                        pos ++;
                    }
                    else{
                        bincod[pos] = '1';
                        pos ++;
                    }
                    con = 0;
                }
                else{
                    bincod[pos] = bin[j];
                    pos ++;
                }
            }
            j = j-semilla;
        }

        else{
            for (int num=0;num<semilla ;j++,num++ ){
                if(pos==longitud*8) break;
                if(bin[j]==49){
                    bincod[pos] = '0';
                    pos ++;
                }
                else{
                    bincod[pos] = '1';
                    pos ++;
                }
            }
            j = j-semilla;
        }
        cont0 = 0;
        cont1 = 0;
    }
    bincod[longitud*8] = '\0';
    strcpy(bin,bincod);

    delete [] bincod;
}

void decodificacion1(int semilla, char *bin, long long longitud)
{
    char *bincod;
    bincod = new char[longitud*8+1];
    bincod[longitud*8] = '\0';

    long long int pos=0;

    for(int i=0; i<semilla;i++){
        if(pos==longitud*8) break;

        if(bin[i]==49){
            bincod[pos] = '0';
            pos ++;
        }
        else{
            bincod[pos]='1';
            pos ++;
        }
    }

    long long int j=0;
    int cont0=0,cont1=0;

    while (j+semilla<longitud*8){
        int con=0;

        for(int k=0;k<semilla;k++,j++){
            if(bincod[j]==48) cont0++;
            else if(bincod[j]==49) cont1++;
        }
        if(cont0==cont1){

            for (int num=0;num<semilla ;j++,num++ ){
                if(pos==longitud*8) break;

                if(bin[j]==49){
                    bincod[pos] = '0';
                    pos ++;
                }
                else{
                    bincod[pos] = '1';
                    pos ++;
                }
            }
            j = j-semilla;
        }
        else if(cont0>cont1){
            for(int num=0;num<semilla;j++,num++){

                if(pos==longitud*8) break;
                if(con==1){
                    if(bin[j]==49){
                        bincod[pos] = '0';
                        pos ++;
                    }
                    else{
                        bincod[pos] = '1';
                        pos ++;
                    }
                    con = 0;
                }
                else{
                    bincod[pos] = bin[j];
                    pos ++;
                    con=con+1;
                }
            }
            j=j-semilla;
        }
        else if(cont0<cont1){
            for(int num=0;num<semilla ;j++,num++){
                if(pos==longitud*8) break;

                if(con==2){
                    if(bin[j]==49){
                        bincod[pos] = '0';
                        pos ++;
                    }
                    else{
                        bincod[pos] = '1';
                        pos ++;
                    }
                    con = 0;
                }
                else{
                    bincod[pos] = bin[j];
                    pos ++;
                }
            }
            j = j-semilla;
        }

        cont0=0;
        cont1=0;
    }
    bincod[longitud*8] = '\0';
    strcpy(bin,bincod);

    delete [] bincod;
}
