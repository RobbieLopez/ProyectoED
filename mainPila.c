#include <stdio.h>
#include <stdlib.h>
struct Pila
{
  int dato;
  struct Pila *up;
};
void
insertar (struct Pila *pila, int dato)
{
  struct Pila *nueva = NULL;
  nueva = (struct Pila *) malloc (sizeof (struct Pila));
  nueva = pila;
  if (pila == NULL)

    {
      return;
    }
  nueva->dato = dato;
  nueva->up = pila;
  pila = nueva;
}

void
mostrarPila (struct Pila *pila)
{
  struct Pila *actual = NULL;
  actual = (struct Pila *) malloc (sizeof (struct Pila));
  actual = pila;
  if (pila != NULL)
    {
      while (actual != NULL)
	{
	  actual = actual->up;
	  printf ("%d", actual->dato);
	}
    }
}

int
main ()
{
  struct Pila *pila = NULL;
  insertar (pila, 1);
  insertar (pila, 2);
  insertar (pila, 3);
  insertar (pila, 4);
  insertar (pila, 5);
  mostrarPila (pila);
  return 0;
}
