#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

#ifndef MONSTRUOS_H
#define MONSTRUOS_H

class Monstruos
{
private:
  string nombre;
  int debilidad;
  int tipo;
  int vida;
  int ataque;
  int defensa;

public:
  Monstruos();
  Monstruos(string, int, int);
  string getNombre();
  void setNombre(string);
  int getDebilidad();
  void setDebilidad(int);
  void Vida();
  ~Monstruos();
};
#endif
