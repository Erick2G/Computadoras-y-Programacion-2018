
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "alumnos.h"

int main(int argc, const char * argv[]) {
	char guardar[3]; // opcion para guardar antes de salir
    int opcion=0;  // opcion del menu seleccionada
    int cantidad=0; // para usar en el case 1, cantidad de alumnos a crear
    int j=0; // uso general de los for
    printf("Programa de alumnos!\n");
    do {
        opcion=menu();
        //system("clear"); // clear en *NIX clr en windows
        //Aqui va la logica principal
        switch (opcion) {
            case 1:
                 printf("\nCrear una nueva lista de alumnos\n\n");
                 printf("øCuantos alumnos quieres crear?:");
                 scanf("%d",&cantidad);
                 for(j=0;j<cantidad;j++){
                   printf("\nCapturando datos del alumno %d\n",j+1);
                   nuevoAlumno();
                 }
                break;
            case 2:
                printf("\nGuardar lista al archivo\n\n");
                grabarRegistros(listaAlumnos,indiceAlArreglo);
                break;
            case 3:
                printf("\nLeer la lista desde el archivo\n\n");
                indiceAlArreglo=registrosEnArchivo();
                leerRegistros(indiceAlArreglo);
                break;
            case 4:
                printf("\nMostrar todos los datos de la lista\n\n");
                imprimirLista();
                break;
            case 5:
                printf("\nAgregar alumno\n\n");
                nuevoAlumno();
                break;
            case 6:
                printf("\nEl promedio de los alumnos es %f \n\n",PromedioAlum());
                break;
            case 7:
                printf("\nBuscando por nombre\n\n");
                Buscar();
                break;
            case 8:
                printf("\nBuscando por edad\n\n");
                BuscarEdad();
                break;
            case 9:
                printf("\nEliminar Alumno\n\n");
                EliminarAlumno();
                break;
            case 10:
            	fflush(stdin);
                printf("\nModificar datos\n\n");
                Modificar2();
                break;
                case 11:
                printf("\nAlumnos aprobados\n\n");
                Aprobados();
                break;
                case 12:
                printf("\nReprobados\n\n");
                Reprobados();
                break;
            case 0:
			    printf("\nGuardar antes de salir?\n\n\tSi | No\n\n");
			    break;
            default:
                printf("\nOpcion no valida\n\n");
                break;
        }

    } while (opcion != 0);
    scanf("%*c%[^\n]",&guardar);
    char rsi[]={'s','i'};
    char rno[]={'n','o'};
    if(strcmp(guardar,rsi)==0){
    	grabarRegistros(listaAlumnos,indiceAlArreglo);
	}
    return 0;
}
