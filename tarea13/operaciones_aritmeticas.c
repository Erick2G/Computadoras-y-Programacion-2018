#include <stdio.h>
int main(){
	int comand=0;
	int nn=0;
	int nm=0;
	printf("Seleccione una opcion e ingrese los datos que se piden:\n   Suma: 1  Resta: 2  Salir del programa: 3\n");	
	do{
		printf("\nOpcion: ");
		scanf("%d",&comand);
		if(comand<=3&&comand>=1){
		    if(comand!=3){
			printf("  Primer numero: ");
			scanf("%d",&nn);
			printf("  Segundo numero: ");
			scanf("%d",&nm);
			if(comand==1){printf("  %d+%d= %d\n",nn,nm,nn+nm);
			}else{printf("  %d-%d=%d\n",nn,nm,nn-nm);	
		}
		}
		}else{printf("  La opcion es incorrecta\n");
		}
		
	}while(comand!=3);
	printf("Fin del programa");
}
