#include <stdio.h>
int main(){
	int ast=0;
	int cnt=0;
	printf("Ingresa un numero entero\n");
	scanf("%d",&ast);
	for(cnt=1;cnt<=ast;cnt=cnt+1){
		printf("* ");
	}
}
