#include <stdio.h>
int main (){
	int n=0;
	printf("Inserte un numero del 1 al 7\n");
	scanf("%d",&n);
	printf("\n");
	printf("Dia: ");
	switch(n){
		case 1:
			printf("Domingo");
			break;
		case 2:
			printf("Lunes");
			break;
		case 3:
			printf("Martes");
			break;
		case 4:
			printf("Miercoles");
			break;
		case 5:
			printf("Jueves");
			break;
		case 6:
			printf("Viernes");
			break;
		case 7:
			printf("Sabado");
			break;
	}
}
