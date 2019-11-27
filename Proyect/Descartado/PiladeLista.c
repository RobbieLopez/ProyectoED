#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int precio;
	char derivado[20];
	struct Lista *siguiente;
}Lista;

typedef struct
{
	char producto[20];
	Lista *lista;
}pila;

Lista *crearLista(int precio,char derivado[]){
	Lista *aux=(Lista*)malloc(sizeof(Lista));
	aux->precio=precio;
	strcpy(aux->derivado,derivado);
	aux->siguiente=NULL;
	return aux;
}

Lista *agregarInicio(Lista *lista, Lista *nuevaLista)
{
	if(lista==NULL){
	lista=nuevaLista;	
	}
	else{
		nuevaLista->siguiente=lista;
		lista=nuevaLista;
	}
	return lista;
}
int ingresarprecio(pila adl[],int tamano){
	int precio;
	char producto[20];
	char derivado[20];
	char salir='s';
	int validos=0;
	while(salir=='s'&&validos<tamano)
	{
		printf("Ingrese el producto\n");
		fflush(stdin);
		scanf("%s",&producto);
		printf("\nIngrese precio");
		scanf("%d",&precio);
		printf("\nIngrese derivado");
		fflush(stdin);
		scanf("%s",&derivado);
		validos=alta(adl,producto,derivado,precio,validos);
		printf("\n Si deseas continuar presiona s");
		salir=getch(salir);
	}
	return validos;
}



int alta(pila adl[],char producto[],char derivado[],int precio, int validos){
	Lista * aux=crearLista(precio,derivado);
	int pos=buscarPosProducto(adl,producto,validos);
	if(pos==-1)
	{
		validos=agregarProducto(adl,producto,validos);
		pos=validos-1;
	}
	adl[pos].lista=agregarInicio(adl[pos].lista,aux);
	return validos;
}

int buscarPosProducto(pila adl[],char producto[],int validos){
	int rta=-1;
	int i=0;
	while((i<validos)&&(rta==-1))
	{
		if(strcmp(adl[i].producto,producto)==0)
		{
			rta=i;
		}
		i++;
		}	
	return rta;
} 
int agregarProducto(pila adl[],char producto[],int validos)
{
	strcpy(adl[validos].producto,producto);
	adl[validos].lista=inicLista();
	validos++;
	return validos;
}


int main() {
	pila adl[20];
	char producto[20];
	int validos=ingresarprecio(adl,20);
	printf("\n\nIngrese el producto que desea mostrar\n");
	fflush(stdin);
	scanf("%s",&producto);
	int pos=buscarPosProducto(adl,producto,validos);
		
	return 0;
}
