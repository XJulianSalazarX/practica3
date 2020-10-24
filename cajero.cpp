#include "cajero.h"


void inicio()
{

    int opc;
    cout << "\n-----------------Menu  Principal-----------------\n";
    cout<<"Preisione:\n1. Para ingresar como administrador.\n2. para ingresar como usuario.\n0.Para salir.\n";
    cout<<"Selecione una opcion: ";cin>>opc;
    while(opc!=0){
        switch (opc) {
        case 1:{
            if(ClaveAdmin())
                administrador();
            else
                cout << "clave incorrecta." << endl;

        }
            break;
        case 2:{

        }
            break;
        default:
            cout<<"Opcion no valida.\n";
        }
        cout << "\n-----------------Menu  Principal-----------------\n";
        cout<<"Preisione:\n1. Para ingresar como administrador.\n2. para ingresar como usuario.\n0.Para salir.\n";
        cout<<"Selecione una opcion: ";cin>>opc;
    }
}


void administrador()
{
    int opc=0;
    cout << "\n---------------Menu  Administrador---------------\n";
    cout<<"Preisione:\n1.Ver informacion de usuarios.\n2.Registrar nuevo usurio.\n3.Eliminar Usuario.\n0.Salir.\n";
    cout<<"Selecione una opcion: ";cin>>opc;
    while(opc!=0){
        switch (opc) {
        case 1:{
            VerInfoUsuarios();
        }
            break;
        case 2:{
            RegistrarUsuario();

        }
            break;
        case 3:{

        }
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << "\n---------------Menu  Administrador---------------\n";
        cout<<"Preisione:\n1.Ver informacion de usuarios.\n2.Registrar nuevo usurio.\n3.Eliminar Usuario.\n0.Salir.\n";
        cout<<"Selecione una opcion: ";cin>>opc;
    }
}

void usuario()
{

}

string CodificarInfo(string archivo)
{

}

string DecodificarInfo(string archivo)
{
    string info;
    info = LeerArchivo(archivo);
    info = Str_to_Binary(info);
    info = decodificacion2(info,4);
    info = Binary_to_Str(info);

    return info;
}

bool ClaveAdmin()
{
    int pos=0;
    string clave,clave_admin;
    cin.ignore(10000,'\n');
    cout << "Ingrese la clave de administrador: ";getline(cin,clave);
    clave_admin = DecodificarInfo("sudo.dat");
    pos = clave_admin.find('\r');
    clave_admin = clave_admin.substr(0,pos);
    if(clave_admin==clave)
        return true;
    else
        return false;
}


void VerInfoUsuarios()
{
    string usuarios;
    int pos = 0;
    usuarios = DecodificarInfo("sudo.dat");
    pos = usuarios.find('\n');
   usuarios = usuarios.substr(pos+1);
   for(int num=1;pos!=-1;num++){
       string cedula,clave,saldo;
       pos = usuarios.find(':');
       cedula = usuarios.substr(0,pos);
       pos = usuarios.find(':',pos+1);
       clave = usuarios.substr(0,pos);
       clave = clave.substr(cedula.size()+1);
       pos = usuarios.find('\r');
       saldo = usuarios.substr(0,pos);
       saldo = saldo.substr(cedula.size()+clave.size()+2);
       cout << "-------Usuario" <<  num <<"-------\n";
       cout << "Cedula: " << cedula << endl;
       cout << "Clave: " << clave << endl;
       cout << "Saldo: " << saldo << "COP\n" << endl;
       pos = usuarios.find('\n');
       usuarios = usuarios.substr(pos+1);
   }
}

void RegistrarUsuario()
{
    string info,cedula,clave,saldo;
    int pos = 0;
    long long dinero = 0;
    info = DecodificarInfo("sudo.dat");
    cin.ignore(10000,'\n');
    cout << "Ingrese la cedula del nuevo usuario: ";getline(cin,cedula);
    if(!ComprobarCedula(cedula)){
        cin.ignore(10000,'\n');
        cout << "Ingrese la nueva clave del usuario: ";getline(cin, clave);
        cout << "Ingerese el dinero inicial del usuario, debe ser mayor a 500000 COP.\n";
        cout << "Dinero inicial: ";cin >> dinero;
    }




}

bool ComprobarCedula(string cedula)
{
    string info, cedula_c;
    int pos = 0;
    info = DecodificarInfo("sudo.dat");
    pos = info.find('\n');
    info = info.substr(pos+1);
    while(pos!= 1){
        pos = info.find(":");
        cedula_c = info.substr(0,pos);
        if(cedula_c == cedula)
            return true;
        pos = info.find('\n');
        info = info.substr(pos+1);
    }
    return false;
}
