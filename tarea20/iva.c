#include <stdio.h>
#include "Iva.h"
int main(){
	float c=0.0;
	float result=0.0;
	printf("Ingrese una cantidad:");
	scanf("%f",&c);
	result=fnIva(c);
	printf("\n",result);
}
