#include<stdio.h>
#include<string.h>
struct alumnos{
	int edad;
	char nombre[60];
	char genero;
	char carrera[25];
	char nCuenta[10];
};
typedef struct alumnos ALUMNO;
int main(int argc, char *argv[]){
	ALUMNO var1;
	 printf("Introduce la edad: ");
	 scanf("%d",&var1.edad);
	 
	 printf("Introduce el nombre: ");
	 fflush(stdin);//limpia el buffer de teclado
	 gets(var1.nombre);
	 
	 printf("Edad: %d  Nombre: %s", var1.edad, var1.nombre);
	 
	 return 0;
}
