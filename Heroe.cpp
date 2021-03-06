
#include "Heroe.h"
#include "Item.h"
#include "Monstruos.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
int itemN =1;

Heroe::Heroe(string nombre, int vida, Item* item, int jefes_derrotados, int dinero, int condicion)
{
    this->nombre = nombre;
    this->vida = vida;
    this->item = item;
    this->jefes_derrotados = jefes_derrotados;
    this->dinero = dinero;
    this->condicion = condicion;
}

////
void Heroe::write(ofstream &out){
    int size = nombre.size();
    //nombre
    out.write(reinterpret_cast<char *>(&size), sizeof(int));
    out.write(nombre.data(), size);
    //vida
    out.write(reinterpret_cast<char *>(&vida), sizeof(int));
    
    ///jefes_derrotados
    out.write(reinterpret_cast<char *>(&jefes_derrotados), sizeof(int));

    // dinero
    out.write(reinterpret_cast<char *>(&dinero), sizeof(int));

    //condicion
    out.write(reinterpret_cast<char *>(&condicion), sizeof(int));
    
    //item
    itemN;
    if(item->getNombre() == "Bumeran"){
        itemN = 1;
    }else if(item->getNombre() == "ArcoYFlecha"){
        itemN = 2;
    }else if(item->getNombre() == "Bombas"){
        itemN = 3;
    }
    out.write(reinterpret_cast<char *>(&itemN), sizeof(int));
}


void Heroe:: read(ifstream& in){
    int size;

    //buffer de nombre
    in.read(reinterpret_cast<char*>(&size), sizeof(int));
    char nameBuffer[size];
    in.read(nameBuffer, size);
    nombre = nameBuffer;

    //buffer de vida
    in.read(reinterpret_cast<char*>(&vida), sizeof(int));
    //buffer de jefe
    in.read(reinterpret_cast<char*>(&jefes_derrotados), sizeof(int));

    //dinero
    in.read(reinterpret_cast<char*>(&dinero), sizeof(int));

    //condicion
    in.read(reinterpret_cast<char*>(&condicion), sizeof(int));
    
    //item
    in.read(reinterpret_cast<char*>(&itemN), sizeof(int));
    Item* itemTraido;
    if(itemN == 1){
        itemTraido = new Bumeran(5, "Bumeran", "rojo");
    }else  if(itemN ==2){
        itemTraido = new ArcoYFlechas(4, "ArcoYFlecha", "azul");
    }else  if(itemN ==3){
        itemTraido = new Bombas(10, 4, "Bombas", "verde");
    }
    setItem(itemTraido);
}

////




Heroe::Heroe()
{
}

string Heroe::getNombre()
{
    return nombre;
}

void Heroe::setNombre(string nombre)
{

    this->nombre = nombre;
}

int Heroe::getVida()
{
    return vida;
}

void Heroe::setVida(int vida)
{

    this->vida = vida;
}

int Heroe::getCondicion()
{
    return condicion;
}

void Heroe::setCondicion(int condicion)
{

    this->condicion = condicion;
}

Item*  Heroe::getItem()
{
    return item;
}

void Heroe::setItem(Item* item)
{

    this->item = item;
}

int Heroe::getJefes_derrotados()
{
    return jefes_derrotados;
}

void Heroe::setJefes_derrotados(int jefes_derrotados)
{

    this->jefes_derrotados = jefes_derrotados;
}

int Heroe::getDinero()
{
    return dinero;
}

void Heroe::setDinero(int dinero)
{

    this->dinero = dinero;
}

Heroe::~Heroe()
{
}