#include <stdio.h>
#include <stdlib.h>

int conversion()
{
	char texto[50];
	int i,s;
	printf( "Introduzca su nombre: " );
	scanf( "%[^\n]", texto );
   for (i = 0; texto[i] != '\0'; i++)
   {
      printf("'%c'\ == %3d\n", texto[i], texto[i]);
	  s += texto[i];
   }
		
   return s-1;
}
int main(){
	
	printf("%d",conversion());
	return 0;
}
