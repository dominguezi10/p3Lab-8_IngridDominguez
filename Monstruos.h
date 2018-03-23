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
  int getVida();
  void setVida(int);
  int getTipo();
  void setTipo(int);
  int getDefensa();
  void setDefensa(int);
  int getAtaque();
  void setAtaque(int);
  void Vida();
  ~Monstruos();
};
#endif
