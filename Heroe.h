#include <string>
#include <iostream>
#include "Item.h"
#include "Monstruos.h"
using namespace std;

#ifndef HEROE_H
#define HEROE_H

class Heroe
{

  private:
    string nombre; 
    int jefes_derrotados;
    int dinero;
    int condicion;

  public:
    int vida;
    Item *item;
    Heroe();
    Heroe(string, int, Item*, int, int, int);
    string getNombre();
    void setNombre(string);
    int getVida();
    void setVida(int);
    Item *getItem();
    void setItem(Item *);
    int getJefes_derrotados();
    void setJefes_derrotados(int);
    int getDinero();
    void setCondicion(int);
    int getCondicion();
    void setDinero(int);
    void write(ofstream &);
    void read(ifstream &);  
    virtual Monstruos* Ataque(Monstruos*) = 0;
    virtual Monstruos* AtaqueItem(Monstruos*) = 0;
    virtual void Defensa(Monstruos*) = 0;

    ~Heroe();
};
#endif