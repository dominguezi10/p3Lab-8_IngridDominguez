#include "Joven.h"
#include "Monstruos.h"
#include <iostream>
#include <string>

using namespace std;
Joven::Joven(string nombre, int vida, Item* item, int jefes_derrotados, int dinero) : Heroe(nombre, vida ,item, jefes_derrotados, dinero)
{
}

Joven::Joven()
{
}

Monstruos *Joven::Ataque(Monstruos * monstruo){
    if (monstruo->getTipo() == 1){
        monstruo->setVida(monstruo->getVida() - 4 + monstruo->getDefensa());
    }
    if (monstruo->getTipo() == 2){
        monstruo->setVida(monstruo->getVida() - 4 + monstruo->getDefensa());
    }
    if (monstruo->getTipo() == 3){
        monstruo->setVida(monstruo->getVida() - 4 + monstruo->getDefensa());
    }
}

Monstruos *Joven::Defensa(Monstruos* monstruo){
    if (monstruo->getTipo() == 1){
        vida = vida - monstruo->getAtaque();
    }
    if (monstruo->getTipo() == 2){
        monstruo->setVida(monstruo->getVida() - 4 + monstruo->getDefensa());
    }
    if (monstruo->getTipo() == 3){
        monstruo->setVida(monstruo->getVida() - 4 + monstruo->getDefensa());
    }
}

Monstruos *Joven::AtaqueItem(Monstruos* monstruo) {
    /*if(dynamcic_cast){

    }*/
}

Joven::~Joven(){


}