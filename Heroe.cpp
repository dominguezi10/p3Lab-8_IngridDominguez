
#include "Heroe.h"
#include "Item.h"
#include "Monstruos.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

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
    out.write(reinterpret_cast<char *>(&size), sizeof(int));
    
    ///jefes_derrotados
    out.write(reinterpret_cast<char *>(&size), sizeof(int));

    // dinero
    out.write(reinterpret_cast<char *>(&size), sizeof(int));

    //condicion
    out.write(reinterpret_cast<char *>(&size), sizeof(int));
    
    //item
    int itemN;
    if(item->getNombre() == "Bumeran"){
        itemN = 1;
    }else if(item->getNombre() == "ArcoYFlecha"){
        itemN = 2;
    }else if(item->getNombre() == "Bombas"){
        itemN = 3;
    }
    out.write(reinterpret_cast<char *>(&itemN), sizeof(int));
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