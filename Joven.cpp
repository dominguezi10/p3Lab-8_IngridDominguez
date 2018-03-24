#include "Joven.h"
#include "Monstruos.h"
#include <iostream>
#include <string>

using namespace std;
Joven::Joven(string nombre, int vida, Item* item, int jefes_derrotados, int dinero,
int condicion) : Heroe(nombre, vida ,item, jefes_derrotados, dinero,condicion)
{
}

Joven::Joven()
{
}

Monstruos *Joven::Ataque(Monstruos * monstruo){
    monstruo->setVida(monstruo->getVida() - 4 + monstruo->getDefensa());
    return monstruo;
}

void Joven::Defensa(Monstruos* monstruo){
    vida = vida - monstruo->getAtaque() +2;
}

Monstruos *Joven::AtaqueItem(Monstruos* monstruo) {
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

Joven::~Joven(){


}