#include<stdio.h>

int main(int argc, char *argv[]){
	FILE *ptrArchivo;
int datoLeido;
	ptrArchivo=fopen("datos.dat","rb");
	if(ptrArchivo==NULL){
		printf("Error al abrid el archivo\n");
	}else{
		while(!feof(ptrArchivo)){
			fscanf(ptrArchivo,"%d",&datoLeido);
			printf("Dato: %d\n", datoLeido);
		}
		fclose(ptrArchivo);
	}
}
