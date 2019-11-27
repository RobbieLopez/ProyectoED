#include "mercadito.h"
int main(){
  struct Lista *Lista = NULL;
  printf("Tu mercadito\n");
  int opc=0;
  int n=0;
  int c=0;
  int numer_eliminar=0;
  do {
    mostrarmenu();
    printf("1.-Ingresar nuevo producto\n");
    printf("2.-Mostrar Productos\n");
    printf("3.-Borrar\n");
    printf("4.-Total\n");
    printf("5.-salir\n");
    printf("opcion a escoger:");
    scanf("%d",&opc);
    switch (opc) {
      case 1:
      printf("1.-Ingresar el numero del producto: ");
      scanf("%d",&n);
      printf("1.-Cantidad: ");
      scanf("%d",&c);
      system("clear");
        //precio es 5$
        //insertar(Producto,Cantidad,Precio);
        if((n==16)||(n==17)||(n==28)||(n==34)){
          Lista = insertar(n,c,5,Lista);
        }
        //precio es 8$
        else if((n==40)||(n==21)){
          Lista = insertar(n,c,8,Lista);
        }
        //precio es 10$
        else if((n==10)||(n==11)||(n==14)||(n==15)||(n==19)||(n==20)||(n==23)||(n==22)||(n==27)
        ||(n==39)||(n==38)||(n==33)||(n==32)||(n==31)||(n==35)||(n==36)||(n==37)||(n==12)){
          Lista = insertar(n,c,10,Lista);
        }
        //precio es 15$
        else if((n==6)||(n==18)){
          Lista = insertar(n,c,15,Lista);
        }
        //precio es 20$
        else if((n==1)||(n==2)||(n==3)||(n==4)||(n==5)||(n==9)){
          Lista = insertar(n,c,20,Lista);
        }
        //precio es 22$
        else if((n==7)||(n==8)||(n==29)){
          Lista = insertar(n,c,22,Lista);
        }
        //precio es 25$
        else if((n==30)||(n==13)){
          Lista = insertar(n,c,25,Lista);
        }
        //precio es 80$
        else if((n==24)||(n==25)||(n==26)){
          Lista = insertar(n,c,80,Lista);
        }
        else{
          printf("No existe ese Producto\n");
          break;
        }
        system("clear");
      break;
      case 2:
        mostrar(Lista);
      break;
      case 3:
        printf("Numero de la lista a eliminar:");
        scanf("%d",&numer_eliminar);
        system("clear");
        Lista=borrar(Lista,numer_eliminar);
      break;
      case 4:
        system("clear");
        total(Lista);
      break;
      default:
        system("clear");
        printf("opcion no valida\n");
      break;
    }
  } while(opc!=5);
    return 0;
}
