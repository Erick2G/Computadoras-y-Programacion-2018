#include <stdio.h>
int fnDimension(int n, int m, int g, int f){
	for(g=1;g<=m;g=g+1){
		for(f=1;f<=n;f=f+1){
			printf("x ");
		}printf("\n");
	}return 0;
}
int main(int argc, char *argv[]){
	int r=0;
	int b=0;
	int k=0;
	int k2=0;
	int h=0;
	printf("Cuadro de x\n Altura: ");
	scanf("%d",&r);
	printf("Largo:");
	scanf("%d",&b);
	h=fnDimension(b,r,k,k2);
	printf("%s",h);
	return 0;
}
