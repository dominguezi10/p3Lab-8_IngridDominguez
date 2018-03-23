#include <string>
#include <iostream>
#include "Heroe.h"
#include "Item.h"

using namespace std;

#ifndef Adulto_H
#define Adulto_H

class Adulto : public Heroe
{
  public: 
    Adulto();
    Adulto(string, int, Item*, int, int);
    Monstruos *Ataque(Monstruos *);
    void Defensa(Monstruos*);
    Monstruos* AtaqueItem(Monstruos*); 
    ~Adulto();
};
#endif