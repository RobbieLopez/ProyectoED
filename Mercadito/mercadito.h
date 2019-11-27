#ifndef __MERCADITO_H__
#define __MERCADITO_H__
#include <stdio.h>
#include <stdlib.h>

struct Lista{
  struct NodoProducto *informacion;
  struct Lista *abajo;
  struct Lista *arriba;
};

struct NodoProducto{
  int dato;
  struct NodoProducto *derecha;
  struct NodoProducto *izquierda;
};

struct Lista *insertar(int,int,int,struct Lista*);
struct NodoProducto *insertardatos(int,int,int,struct NodoProducto*);
//insertar(Producto,Cantidad,Precio);
struct Lista *mostrar(struct Lista*);
struct Lista *total(struct Lista*);
struct Lista *borrar(struct Lista*,int);
void mostrarmenu();

#endif
