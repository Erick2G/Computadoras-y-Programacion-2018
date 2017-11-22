#include<stdio.h>
#include<string.h>
#include"alumnos.h"

int main(int argc, char *argv[]){
	ALUMNO var1;
	var1=nuevoAlumno();
	imprimeAlumno(var1);
	return 0;
}
