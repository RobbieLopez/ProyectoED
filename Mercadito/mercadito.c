#include "mercadito.h"
struct Lista *insertar (int n,int c, int dato,struct Lista* Lista){
  struct NodoProducto *NodoProducto=NULL;
  struct Lista *nuevo_lis=NULL;
  nuevo_lis=(struct Lista*)malloc(sizeof(struct Lista));
  if(Lista==NULL){
    NodoProducto=insertardatos(n,c,dato,NodoProducto);
    nuevo_lis->informacion=NodoProducto;
    Lista=nuevo_lis;
    Lista->abajo=NULL;
    return Lista;
  }
  struct Lista *tmp=NULL;
  tmp=Lista;
  while ((tmp->abajo!=NULL)&&(tmp->informacion->dato!=n)){
    tmp=tmp->abajo;
  }
  if(tmp->informacion->dato==n){
      tmp->informacion->derecha->dato=tmp->informacion->derecha->dato+c;
      return Lista;
  }
  else{
    NodoProducto=insertardatos(n,c,dato,NodoProducto);
      tmp->abajo=nuevo_lis;
      nuevo_lis->arriba=tmp;
      nuevo_lis->informacion=NodoProducto;
      return Lista;
  }
}

struct Lista *borrar(struct Lista*Lista ,int numer_eliminar){
  int contador=1;
  struct Lista*tmp=NULL;
  tmp=Lista;
  if(Lista==NULL){
    printf("Lista esta vacia\n");
    return Lista;
  }
    while((tmp!=NULL)&&(contador!=numer_eliminar)){
        contador++;
        tmp=tmp->abajo;
      }
  if(tmp==NULL){
    printf("El No. a eliminar no se encuentra en la lista\n");
    return Lista;
  }
  else if((tmp==Lista)&&(tmp->abajo==NULL)){
    printf("Se borro toda la lista\n");
    free(tmp);
    Lista=NULL;
    return Lista;
  }
  else if((tmp==Lista)&&(tmp->abajo!=NULL)){
    Lista=Lista->abajo;
    free(tmp);
    return Lista;
  }
  else if((tmp!=Lista)&&(tmp->abajo==NULL)){
    tmp->arriba->abajo=NULL;
    free(tmp);
    return Lista;
  }
  else{
    tmp->arriba->abajo=tmp->abajo;
    tmp->abajo->arriba=tmp->arriba;
  }
  return Lista;
}

struct Lista *total(struct Lista* Lista){
  int total=0;
  int contador_pro=0;
  int contidad_pro=0;
  if(Lista==NULL){
    printf("No. de productos:%d\n",contador_pro);
    printf("cantidad de producto:%d\n",contidad_pro);
    printf("Total es: %d\n",total);
    return Lista;
  }
  struct Lista *tmp_tot=NULL;
  tmp_tot=Lista;
  while (tmp_tot!=NULL){
      contador_pro++;
      contidad_pro=tmp_tot->informacion->derecha->dato+contidad_pro;
      total=(tmp_tot->informacion->derecha->dato*tmp_tot->informacion->derecha->derecha->dato)+total;
      tmp_tot=tmp_tot->abajo;
  }
  printf("No. de productos:%d\n",contador_pro);
  printf("cantidad de producto:%d\n",contidad_pro);
  printf("Total es: %d\n",total);
  return Lista;
}
struct NodoProducto *insertardatos(int n,int c, int dato,struct NodoProducto* NodoProducto){
  for(int i=0;i<3;i++){
    struct NodoProducto *nuevo=NULL;
    nuevo=(struct NodoProducto*)malloc(sizeof(struct NodoProducto));
    if(i==0){
      nuevo->dato=n;
      NodoProducto=nuevo;
    }
    else if(i==1){
      nuevo->dato=c;
      NodoProducto->derecha=nuevo;
      nuevo->izquierda=NodoProducto;
    }
    else if(i==2){
      nuevo->dato=dato;
      NodoProducto->derecha->derecha=nuevo;
      nuevo->izquierda=NodoProducto->derecha;
    }
  }
  return NodoProducto;
}

struct Lista *mostrar(struct Lista* Lista){
  system("clear");
  if(Lista==NULL){
    printf("Lista vacia no hay datos a mostrar\n");
  }
  int contador=1;
  struct Lista *tmp_bus=NULL;
  tmp_bus=Lista;
    printf("-----------------------------\n");
    printf("|No.|No.Prod|Cantidad|precio|\n");
  while(tmp_bus!=NULL){
    printf("|%d  |  %d   |   %d   |  %d  |\n",contador,tmp_bus->informacion->dato,tmp_bus->informacion->derecha->dato,tmp_bus->informacion->derecha->derecha->dato);
    contador++;
    tmp_bus=tmp_bus->abajo;
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
