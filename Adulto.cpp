#include "Adulto.h"
#include "Heroe.h"
#include <iostream>
#include <string>
#include "Item.h"
#include "Monstruos.h"
using namespace std;

Adulto::Adulto(string nombre, int vida, Item* item, int jefes_derrotados, int dinero,
int condicion) : Heroe(nombre, vida, item, jefes_derrotados, dinero, condicion)
{
}

Adulto::Adulto()
{
}


Monstruos *Adulto::Ataque(Monstruos * monstruo){
    monstruo->setVida(monstruo->getVida() - 4 + monstruo->getDefensa());
    return monstruo;
}

void Adulto::Defensa(Monstruos* monstruo){
    vida = vida - monstruo->getAtaque() +2;
}

Monstruos *Adulto::AtaqueItem(Monstruos* monstruo) {
    if (item->getNombre() == "Bumeran"){
        monstruo->setVida(monstruo->getVida() - 5 + monstruo->getDefensa());
    }

    if (item->getNombre() == "ArcoYFlecha"){
        monstruo->setVida(monstruo->getVida() - 4 );
    }

    if (item->getNombre() == "Bombas"){
        monstruo->setVida(monstruo->getVida() - 10 + monstruo->getDefensa());
        vida = vida-4;
    }
}

Adulto::~Adulto()
{
}