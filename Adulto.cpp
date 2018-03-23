#include "Adulto.h"
#include "Heroe.h"
#include <iostream>
#include <string>
#include "Item.h"
#include "Monstruos.h"
using namespace std;

Adulto::Adulto(string nombre, int vida, Item* item, int jefes_derrotados, int dinero) : Heroe(nombre, vida, item, jefes_derrotados, dinero)
{
}

Adulto::Adulto()
{
}

Monstruos *Adulto::Ataque(Monstruos* monstruo){

}

Monstruos *Adulto::Defensa(Monstruos* monstruo){

}

Monstruos *Adulto::AtaqueItem(Monstruos* monstruo) {

}

Adulto::~Adulto()
{
}