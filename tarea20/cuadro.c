#include <stdio.h>
int fnDimension(int n, int m){
	int g=0;
	int f=0;
	for(g=1;g<=m;g=g+1){
		for(f=1;f<=n;f=f+1){
			printf("x ");
		}printf("\n");
	}return 0;
}
////https://www.tutorialspoint.com/cplusplus/cpp_null_pointers.htm
int main(int argc, char *argv[]){
	int r=0;
	int b=0;
	int h=0;
	printf("Cuadro de x\n  Altura: ");
	scanf("%d",&r);
	printf("  Largo:");
	scanf("%d",&b);8
	h=fnDimension(b,r);
	printf("%s",h);
	return 0;
}
