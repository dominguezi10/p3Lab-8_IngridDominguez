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


int main(){
    cout<< "Bienvenido!"<< endl ;
    
    jugador = crearJugador();
    cout<< "Creado Jugador "<< jugador->getNombre() <<endl;

    int opcion = 0;
    while (jugador->getVida() > 0 && opcion != 7){
        opcion = menu();

          //  cout << "s   aaa  " <<opcion ;
        switch (opcion){
        case 1:{
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
            break;
        }
        case 5:{
            break;
        }
        case 6:{
            break;
        }
        case 7:{
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


int menu(){
    int opcion = -100;
    while(opcion<1 || opcion >7){
        cout << "Ingresa tu opcion: "<< endl;
        cout << "1- Pelear con Monstruo" << endl;
        cout << "2- Ver Estado" << endl;
        cout << "3- Crear Monstruo" << endl;
        cout << "4- Cambiar Item" << endl;
        cout << "5- Tienda" << endl;
        cout << "6- Guardar Partida" << endl;
        cout << "7- Salir" << endl;
        cin >> opcion;
        if (mosntruos.size() < 1 && (opcion == 1 || opcion == 5 || opcion == 6))
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
        item = new ArcoYFlechas(4, "Arco y Flecha", "azul");
    }else  if(tipo ==3){
        item = new Bombas(10, 4, "Bombas", "verde");
    }

    Heroe* jugador = new Joven(nombre, 12, item, 0,0);
    return jugador;
}