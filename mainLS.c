#include <stdio.h>
#include <stdlib.h>




typedef struct Lista
{
  int dato;
  struct Lista *siguiente;
} Lista;

Lista *primero = NULL;
Lista *ultimo = NULL;

void
insertarLista ()
{
  Lista *nuevo = (Lista *) malloc (sizeof (Lista));
  printf (" Ingrese el dato que tendra el nuevo nodo de la lista: ");
  scanf ("%d", &nuevo->dato);
  if (primero == NULL)
    {
      primero = nuevo;
      primero->siguiente = NULL;
      ultimo = nuevo;
    }
  else
    {
      ultimo->siguiente = nuevo;
      nuevo->siguiente = NULL;
      ultimo = nuevo;
    }
}

void
mostrarLista ()
{
  Lista *actual = (Lista *) malloc (sizeof (Lista));
  actual = primero;
  if (primero != NULL)
    {
      while (actual != NULL)
	{
	  printf ("\n %d\n ", actual->dato);
	  actual = actual->siguiente;
	}
    }
  else
    {
      printf ("\n");
    }
}

void
eliminarDato ()
{
  Lista *actual = (Lista *) malloc (sizeof (Lista));
  actual = primero;
  Lista *anterior = (Lista *) malloc (sizeof (Lista));
  anterior = NULL;
  int datoB = 0, datoE = 0;
  printf (" Ingrese el dato de la lista para eliminar: ");
  scanf ("%d", &datoB);
  if (primero != NULL)
    {
      while (actual != NULL && datoE != 1)
	{

	  if (actual->dato == datoB)
	    {
	      if (actual == primero)
		{
		  primero = primero->siguiente;
		}
	      else if (actual == ultimo)
		{
		  anterior->siguiente = NULL;
		  ultimo = anterior;
		}
	      else
		{
		  anterior->siguiente = actual->siguiente;
		}
	      printf ("\n");
	      datoE = 1;
	    }
	  anterior = actual;
	  actual = actual->siguiente;
	}
      if (datoE == 0)
	{
	  printf ("\n");
	}
      else
	{
	  free (anterior);
	}

    }
  else
    {
      printf ("\n");
    }
}

int op;
int
main ()
{
  do
    {
      printf ("1.- Agregar datos\n");
      printf ("2.- Mostrar Lista\n");
      printf ("3.- Eliminar Dato\n");
      printf ("E.- Salir\n");
      scanf ("%d", &op);

      switch (op)
	{
	case 1:
	  {
	    insertarLista ();
	  }
	  break;
	case 2:
	  {
	    mostrarLista ();
	  }
	  break;
	case 3:
	  {
	    eliminarDato ();
	  }
	  break;
	}
    }
  while (op != 'E');


  return 0;
}
