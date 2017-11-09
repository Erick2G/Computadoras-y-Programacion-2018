#include <stdio.h>
#include "iva.h"
int main(int argc, char *argv[]){
	int r=0;
	int b=0;
	int h=0;
	printf("Cuadro de x\n  Altura: ");
	scanf("%d",&r);
	printf("  Largo:");
	scanf("%d",&b);
	h=fnDimension(b,r);
	printf("%s",h);
	
	float c=0.0;
	float result=0.0;
	printf("\nIngrese una cantidad:");
	scanf("%f",&c);
	result=fniva(c);
	printf("\n",result);
}
//https://www.tutorialspoint.com/cplusplus/cpp_null_pointers.htm
