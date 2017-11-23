#include<stdio.h>

int main(int argc, char *argv[]){
	int dato;
	FILE *ptrArchivo;
	ptrArchivo=fopen("datos.dat","wb");
	
	if(ptrArchivo==NULL){
		printf("Error al abrir el archivo \n");
	}else{
		printf("Dame el dato a guardar al archivo:");
		scanf("%d",&dato);
		
		//se guarda en archivo
		fprintf(ptrArchivo,"%d\n",dato);
		fprintf(ptrArchivo,"%d\n",++dato);
		fprintf(ptrArchivo,"%d\n\n",++dato);
		
		fclose(ptrArchivo); //se cierra el archivo
	}
}
