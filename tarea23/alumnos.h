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

ALUMNO nuevoAlumno(){
	ALUMNO tmp;
	printf("Introduce la edad:");
	scanf("%d",&tmp.edad);
	
	printf("Introduce el nombre: ");
	fflush(stdin);//limpia el buffer de teclado
	gets(tmp.nombre);
	
	printf("Introduce el genero: ");
	scanf("%c",&tmp.genero);
	
	printf("Introduce la carrera: ");
	fflush(stdin);//limpia el buffer de teclado
	gets(tmp.carrera);
	
	printf("Introduce el numero de cuenta: ");
	fflush(stdin);//limpia el buffer de teclado
	gets(tmp.nCuenta);
	
	return tmp;
}

void imprimeAlumno(ALUMNO al){
	printf("**************************\n");
	printf("Nombre: %s\n",al.nombre);
	printf("Edad: %d\n",al.edad);
	printf("Genero: %c\n",al.genero);
	printf("Carrera: %s\n",al.carrera);
	printf("Numero de cuneta: %s\n",al.nCuenta);
}
