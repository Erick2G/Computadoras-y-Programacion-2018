#include <stdio.h>
int main(){
	int iva=0;
	int cdd=0;
	printf("IVA (En Mexico): 16 percent\nIngrese una cantidad:");
	scanf("%d",&cdd);
	iva=cdd*16/116;
	printf("\nSubtotal: %d\nIVA de la cantidad: %d\nTotal:%d",cdd-iva,iva,cdd);
}
