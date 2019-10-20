#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertar();
void buscar();
void modificar();
void eliminar();
void mostrar();

int main()
{
	int opcion = 0;
	do
	{
		printf("\n 1. Inserta");
		printf("\n 2- Buscar");
		printf("\n 3.-Modificar");
		printf("\n 4.-Eliminar");
		printf("\n 5.- Mostrar");
		printf("\n 6.Salir\n");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				insertar();
				break;
			case 2:
				buscar();
				break;	
			case 3:
				modificar();
				break;
			case 4:
				eliminar();
				break;
			case 5:
				mostrar();	
				break;
			case 6:
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcion != 6);
	return 0;
}

void insertar()
{
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
}

void buscar(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor que desea buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
						
			actual = actual->siguiente;
		}
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La cola no existe\n\n");
	}
}

void modificar(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor del Nodo a Buscar para Modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d" , &actual->dato);
				printf("\n Nodo Modificado con exito\n\n");
				encontrado = 1;
			}
						
			actual = actual->siguiente;
		}
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La cola no existe\n\n");
	}
}

void eliminar(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor del Nodo a Buscar para Eliminar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){		
				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				printf("\n El Nodo eliminado con exito\n\n");
				encontrado = 1;
			}
			anterior = actual;	
			actual = actual->siguiente;
		}
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La cola no existe\n\n");
	}
}

void mostrar(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero != NULL){
		
		while(actual != NULL){
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf("\n La cola no existe\n\n");
	}
}
