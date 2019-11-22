#include <stdio.h>
#include <stdlib.h>

struct Lista{
  struct info *arr;
  struct Lista *abajo;
  struct Lista *arriba;
};

struct info{
  int dato;
  struct info *derecha;
  struct info *izquierda;
};

struct Lista *insertar(int,int,int,struct Lista*);
struct info *insertardatos(int,int,int,struct info*);
//insertar(Producto,Cantidad,Precio);
struct Lista *mostrar(struct Lista*);
void mostrarmenu();

int main(){
  struct Lista *Lista = NULL;
  printf("Tu mercadito\n");
  int opc=0;
  int n=0;
  int c=0;
  do {
    mostrarmenu();
    printf("1.-Ingresar nuevo producto\n");
    printf("2.-Mostrar Productos\n");
    printf("3.-salir\n");
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
        ||(n==39)||(n==38)||(n==33)||(n==32)||(n==31)||(n==35)||(n==36)||(n==37)){
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
      system("clear");
      break;
      case 2:
        mostrar(Lista);
      break;
    }
  } while(opc!=3);
  //mostrar(Lista);
    return 0;
}

struct Lista *insertar(int n,int c, int dato,struct Lista* Lista){
  struct info *listadeproductos=NULL;
  struct Lista *nuevaLista=NULL;
  nuevaLista=(struct Lista*)malloc(sizeof(struct Lista));
  listadeproductos=insertardatos(n,c,dato,info);
  if(Lista==NULL){
    nuevaLista->arr=listadeproductos;
    Lista=nuevaLista;
    Lista->abajo=NULL;
    return Lista;
  }
  else{
      struct Lista *tmp=NULL;
      tmp=Lista;
      while (tmp->abajo!=NULL){
        tmp=tmp->abajo;
      }
      tmp->abajo=nuevaLista;
      nuevaLista->arriba=tmp;
      nuevaLista->arr=listadeproductos;
      return Lista;
  }
}

struct info *insertardatos(int n,int c, int dato,struct info* info){
  for(int i=0;i<3;i++){
    struct info *nuevo=NULL;
    nuevo=(struct info*)malloc(sizeof(struct info));
    if(i==0){
      nuevo->dato=n;
      info=nuevo;
    }
    else if(i==1){
      nuevo->dato=c;
      info->derecha=nuevo;
      nuevo->izquierda=info;
    }
    else if(i==2){
      nuevo->dato=dato;
      info->derecha->derecha=nuevo;
      nuevo->izquierda=info->derecha;
    }
  }
  return info;
}

struct Lista *mostrar(struct Lista* Lista){
  system("clear");
  int contador=1;
  struct Lista *aux_bus=NULL;
  aux_bus=Lista;
    printf("-----------------------------\n");
    printf("|No.|No.Prod|Cantidad|precio|\n");
  while(aux_bus!=NULL){
    printf("|%d  |  %d   |   %d   |  %d  |\n",contador,aux_bus->arr->dato,aux_bus->arr->derecha->dato,aux_bus->arr->derecha->derecha->dato);
    contador++;
    aux_bus=aux_bus->abajo;
  }
    printf("-----------------------------\n");
  return Lista;
}

void mostrarmenu(){
  printf("---------------------------------------------------------------------------------\n");
  printf("| 1) Maiz                       $20 |21)Papel Higienico                     $8  |\n");
  printf("| 2) Frijol                     $20 |22)Detergente en polvo                 $10 |\n");
  printf("| 3) Arroz                      $20 |23)Crema dental                        $10 |\n");
  printf("| 4) Azucar                     $20 |24)Carne de res                        $80 |\n");
  printf("| 5) Harina de maiz enriquecida $20 |25)Carne de puerco                     $80 |\n");
  printf("| 6) Aceite Vegetal Comestible  $15 |26)Carne de pollo                      $80 |\n");
  printf("| 7) Atun                       $22 |27)Tostadas                            $10 |\n");
  printf("| 8) Sardina                    $22 |28)Pan de caja y de dulce              $5  |\n");
  printf("| 9) Lehe fluida                $20 |29)Huevo fresco                        $22 |\n");
  printf("|10) Chile envasados            $10 |30)Pescado seco                        $25 |\n");
  printf("|11) Cafe soluble               $10 |31)Agua purificada                     $10 |\n");
  printf("|12) Sal de mesa                $10 |32)Golosina de amaranto, cacahuate,etc $10 |\n");
  printf("|13) Avena                      $25 |33)Pure de tomate envasado             $10 |\n");
  printf("|14) Pasta para sopa            $10 |34)Frutas deshidratadas                $5  |\n");
  printf("|15) Harina de trigo            $10 |35)Jamaica y tamarindo naturales       $10 |\n");
  printf("|16) Chocolate                  $5  |36)Concentrados para bebidas           $10 |\n");
  printf("|17) Galletas marias            $5  |37)Gelatina                            $10 |\n");
  printf("|18) Lentejas                   $15 |38)Garbanzos,chicharos y soya          $10 |\n");
  printf("|19) Jabon de lavanderia        $10 |39)Cuadro basico de frutas y verduras  $10 |\n");
  printf("|20) Jabon de tocador           $10 |40)Pilas                               $8  |\n");
  printf("--------------------------------------------------------------------------------\n");
}

