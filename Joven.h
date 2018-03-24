#include <string>
#include <iostream>
#include "Heroe.h"

using namespace std;

#ifndef JOVEN_H
#define JOVEN_H

class Joven : public Heroe
{
  public:
    Joven();
    Joven(string, int,  Item*, int, int, int);
    Monstruos *Ataque(Monstruos *);
    void Defensa(Monstruos *);
    Monstruos* AtaqueItem(Monstruos*);
    ~Joven();
};
#endif
