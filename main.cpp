#include <iostream>
#include <vector>


#include  "Heroe.h"
#include  "Adulto.h"
#include  "Joven.h"
#include  "Bumeran.h"
#include  "ArcoYFlechas.h"
#include  "Bombas.h" 
#include "Item.h"
#include  "Monstruos.h"

//  o u i
Heroe* jugador;
Heroe* crearJugador();
vector<Monstruos*> mosntruos;
int menu();
void crearMonstruo();
void cambiarItem();
void listar();
void jugar();

int main(){
    cout<< "Bienvenido!"<< endl ;
    
    jugador = crearJugador();
    cout<< "Creado Jugador "<< jugador->getNombre() <<endl;

    int opcion = 0;
    while (jugador->getVida() > 0 && opcion != 8){
        opcion = menu();

          //  cout << "s   aaa  " <<opcion ;
        switch (opcion){
        case 1:{
            jugar();
            break;
        }
        case 2:{
            cout<< "Vidas:  "<< jugador->getVida()  <<endl ;
            cout<< "Dinero:  "<< jugador->getDinero()  <<endl ;
            cout<< "Jefes Derrotados:  "<< jugador->getJefes_derrotados()  <<endl <<endl;
            break;
        }
        case 3:{
            crearMonstruo();
            break;
        }
        case 4:{
            cambiarItem();
            break;
        }
        case 5:{
            break;
        }
        case 6:{
            break;
        }
        case 7:{
            listar();
            break;
        }
        case 8:{
            jugador->setVida(0);
            break;
        }
        }
    }



    return 0;
}

void crearMonstruo(){
    string nombre;
    cout <<"ingresa el nombre del Mounstro: "<< endl;
    cin >> nombre;

    int tipo;
    cout<< "Tipo  de Mounstro: "<< endl << "1.-Jefes"<< endl<< "2.-Semijefes"<< endl << "3.-Comunes"<< endl;
    cin>> tipo;

    int debilidad;
    cout<< "Tipo  de debilidad: "<< endl << "1.-Bomeran "<< endl<< "2.-Arco y Flecha"<< endl << "3.-Bomba"<< endl;
    cin>> debilidad;

    Monstruos* mosntruo = new Monstruos(nombre, tipo, debilidad);
    mosntruos.push_back(mosntruo);
    cout<< "Existen " << mosntruos.size() << endl;
}

void jugar(){
    while(jugador->getVida()>0){
        int opcion;
        
        cout<< "Jugador Ataque: "<< endl ;
        cout<< "1- Nomal "<< endl<< "2.- Con Item "<< endl;
        cout<< "ingresa opcion: "<< endl ;
        cin>> opcion;

        for(int i=0; i<mosntruos.size(); i++){
            cout<< (1+i)<< "- "<< mosntruos[i]->getNombre()<< endl;
        }

     
        int opcionM = -99;
        while(opcion< 0|| opcion>mosntruos.size()){
            cout <<"ingresa la posicion del Mounstro a pelear: "<< endl;
            cin >> opcionM;
        }

        Monstruos* mosntruoP;
        mosntruoP = mosntruos[opcionM-1];

        if(opcion == 1){
            mosntruoP = jugador->Ataque(mosntruoP);
        }
        if(opcion == 2){
            mosntruoP = jugador->AtaqueItem(mosntruoP);
        }

        cout <<"Turno del mosntruo: "<< endl;
        cout <<"Mosntruo atacand..... "<< endl;
        jugador->Defensa(mosntruoP);
        

        
    }
}

void listar(){
    int opcion =-100;

    for(int i=0; i<mosntruos.size(); i++){
        cout<< (1+i)<< "- "<< mosntruos[i]->getNombre()<< endl;
    }

    while(opcion< 0|| opcion>mosntruos.size()){
        cout <<"ingresa la posicion del Mounstro a eliminar: "<< endl;
        cin >> opcion;
    }

    delete mosntruos[opcion-1];
    mosntruos[opcion-1] = NULL;
    mosntruos[opcion-1] = new Monstruos("Fue Eliminado", 1, 1);
    cout <<"el Mounstro Fue Eliminado "<< endl << endl;
}


int menu(){
    int opcion = -100;
    while(opcion<1 || opcion >8){
        cout << "Ingresa tu opcion: "<< endl;
        cout << "1- Pelear con Monstruo" << endl;
        cout << "2- Ver Estado" << endl;
        cout << "3- Crear Monstruo" << endl;
        cout << "4- Cambiar Item" << endl;
        cout << "5- Tienda" << endl;
        cout << "6- Guardar Partida" << endl;
        cout << "7- Eliminar Monstruos" << endl;
        cout << "8- Salir" << endl;
        cin >> opcion;
        if (mosntruos.size() < 1 && (opcion == 1 || opcion == 5 || opcion == 6 || opcion == 7))
        {
            cout << "Debe crear Monstruos Primero!. " << endl;
            opcion = 0;
        }
        cout << endl;
    }
    return opcion;
}

Heroe* crearJugador(){
    string nombre;
    cout <<"ingresa el nombre del jugador"<< endl;
    cin >> nombre;

    int tipo;
    cout<< "Tipo  de Item: "<< endl << "1.-Bomeran "<< endl<< "2.-Arco y Flecha"<< endl << "3.-Bomba"<< endl;
    cin>> tipo;

    Item* item;
    if(tipo == 1){
        item = new Bumeran(5, "Bumeran", "rojo");
    }else  if(tipo ==2){
        item = new ArcoYFlechas(4, "ArcoYFlecha", "azul");
    }else  if(tipo ==3){
        item = new Bombas(10, 4, "Bombas", "verde");
    }

    Heroe* jugador = new Joven(nombre, 12, item, 0,0);
    return jugador;
}

void cambiarItem(){
    int tipo;
    cout<< "Tipo  de Item Nuevo: "<< endl << "1.-Bomeran "<< endl<< "2.-Arco y Flecha"<< endl << "3.-Bomba"<< endl;
    cin>> tipo;

    Item* item;
    if(tipo == 1){
        item = new Bumeran(5, "Bumeran", "rojo");
    }else  if(tipo ==2){
        item = new ArcoYFlechas(4, "ArcoYFlecha", "azul");
    }else  if(tipo ==3){
        item = new Bombas(10, 4, "Bombas", "verde");
    }

    jugador->setItem(item);
    cout<< "Item Nuevo asignado"<< endl<< endl;
}
