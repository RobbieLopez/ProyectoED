#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
  int dato;
  struct Lista *siguiente;
  struct Lista *anterior;
} Lista;

Lista *primero = NULL;
Lista *ultimo = NULL;

void
insertar ()
{
  Lista *nuevo = (Lista *) malloc (sizeof (Lista));
  printf (" \nIngrese el nuevo dato de la Lista\n");
  scanf ("%d", &nuevo->dato);

  if (primero == NULL)
    {
      primero = nuevo;
      primero->siguiente = NULL;
      primero->anterior = NULL;
      ultimo = primero;
    }
  else
    {
      ultimo->siguiente = nuevo;
      nuevo->siguiente = NULL;
      nuevo->anterior = ultimo;
      ultimo = nuevo;
    }

}


void
mostrarListaAB ()
{
  Lista *actual = (Lista *) malloc (sizeof (Lista));
  actual = primero;
  if (primero != NULL)
    {
      while (actual != NULL)
	{
	  printf ("\n %d", actual->dato);
	  actual = actual->siguiente;
	}
    }
  else
    {
      printf ("\n La lista esta vacia \n\n");
    }
}


void
mostrarListaBA ()
{
  Lista *actual = (Lista *) malloc (sizeof (Lista));
  actual = ultimo;
  if (primero != NULL)
    {
      while (actual != NULL)
	{
	  printf ("\n %d", actual->dato);
	  actual = actual->anterior;
	}
    }
  else
    {
      printf ("\n");
    }
}

void
eliminar ()
{
  Lista *actual = (Lista *) malloc (sizeof (Lista));
  actual = primero;
  Lista *antes = (Lista *) malloc (sizeof (Lista));
  antes = NULL;
  int DatoB = 0, DatoE = 0;
  printf (" Ingrese el dato a eliminar: ");
  scanf ("%d", &DatoB);

  if (primero != NULL)
    {
      while (actual != NULL && DatoE != 1)
	{

	  if (actual->dato == DatoB)
	    {

	      if (actual == primero)
		{
		  primero = primero->siguiente;
		  primero->anterior = NULL;
		}
	      else if (actual == ultimo)
		{
		  antes->siguiente = NULL;
		  ultimo = antes;
		}
	      else
		{
		  antes->siguiente = actual->siguiente;
		  actual->siguiente->anterior = antes;
		}
	      printf ("\n");

	      DatoE = 1;
	    }
	  antes = actual;
	  actual = actual->siguiente;
	}
      if (DatoE == 0)
	{
	  printf ("\n");
	}
      else
	{
	  free (antes);
	}
    }
  else
    {
      printf ("\n");
    }
}

int
main ()
{
  int op;
  do
    {
      printf ("1.- Agregar datos\n");
      printf ("2.- Mostrar Lista\n");
      printf ("3.- Mostrar Lista invertida\n");
      printf ("4.- Eliminar Dato\n");
      printf ("E.- Salir\n");
      scanf ("%d", &op);

      switch (op)
	{
	case 1:
	  {
	    insertar ();
	  }
	  break;
	case 2:
	  {
	    mostrarListaAB ();
	  }
	  break;
	case 3:
	  {
	    mostrarListaBA ();
	  }
	  break;
	case 4:
	  {
	    eliminar ();
	  }
	  break;
	}
    }
  while (op != 'E');
  return 0;
}
