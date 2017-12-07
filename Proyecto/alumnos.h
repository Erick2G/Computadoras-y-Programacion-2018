
#define MAX 200
#ifndef alumnos_h
#define alumnos_h
struct alumnos
{
    int edad;
    char nombre[120];
    char genero;
    char carrera[50];
    char nCuenta[10];
    float promedio;
};
typedef struct alumnos ALUMNO;
int indiceAlArreglo=0; // esta variable global se usarÂ· para almacenar el indice del ultimo alumno ingresado al arreglo.
ALUMNO listaAlumnos[MAX]; // declaraciÃ›n de un arreglo de alumnos de 200 elementos


/**  Funcion insertarAlumno
 *
 * Descripción:
 *   Funcion para insertar al arreglo un nuevo alumno,
 * Entrada:
 *     la función  recibe un alumno "al" de entrada.
 * LÛgica interna:
 *     Verifica que el indice este en el rango adecuado, entre 0 y MAX.
 *     de cumplirse ingresa el alumno al arreglo e incrementa el indice general
 * Valor de retorno:
 *     No regresa nada.
 */
void insertarAlumno(ALUMNO al){
    if (indiceAlArreglo >= 0 && indiceAlArreglo < MAX) { // verificamos que inidice este en los rangos correctos
        listaAlumnos[indiceAlArreglo]=al;
        indiceAlArreglo++;
    }else{
        printf("El indice apunta fuera del arreglo, favor de revisar la lógica");
    }
}

/** Funcion nuevoAlumno
 * DescripciÛn:
 *   Funcion para capturar los datos desde teclado de un nuevo alumno,
 * Entrada:
 *     la funciÛn no recibe ningun parámetro de entrada.
 * Lógica interna:
 *     Crea una variable temporal del tipo alumno y se obtienen los datos desde el teclado.
 *     TambÌen se agrega el alumno al arreglo
 * Valor de retorno:
 *     Regreza la variable temporal de tipo ALUMNO con los datos llenos.
 */
ALUMNO nuevoAlumno(){
    ALUMNO tmp;
    printf("Introduce la edad:");
    scanf("%d",&tmp.edad);
    printf("Introduce el genero [M o F]:");
    scanf(" %c",&tmp.genero);   // El espacio antes del %c es para que ignore espacios en blanco
    printf("Introduce el nombre:");
    scanf("%*c%[^\n]",tmp.nombre);
    printf("Introduce Carrera:");
    scanf("%*c%[^\n]",tmp.carrera);
    printf("Introduce numero de cuenta:");
    scanf("%*c%[^\n]",tmp.nCuenta);
    printf("Introduce tu promedio:");
    scanf("%f",&tmp.promedio);
    /*
     * Aqui agregamos al alumno al arreglo e incrementamos el Ìndice para que apunte al siguiente elementos
     */
    insertarAlumno(tmp);
    return tmp;
}
/** funcion imprimeAlumno
 * DescripciÛn:
 *   Funcion para imprimir en pantalla los datos de un solo alumno,
 * Entrada:
 *     la funciÛn  recibe la variable alumno a ser impresa.
 * LÛgica interna:
 *     SÛlo imprime cada uno de los campos
 * Valor de retorno:
 *     No regresa nada
 */
void imprimeAlumno(ALUMNO al){
    printf("\tNombre:%s\n",al.nombre);
    printf("\tEdad:%d\n",al.edad);
    printf("\tGenero:%c\n",al.genero);
    printf("\tCarrera:%s\n",al.carrera);
    printf("\tNumero de Cuenta:%s\n",al.nCuenta);
    printf("\tPromedio:%.2f\n",al.promedio);
    printf("+---------------------------------+\n\n");
}


/** funcion imprimirLista
 * DescripciÛn:
 *   Funcion para imprimir en pantalla TODOS los datos del arreglo.
 * Entrada:
 *     la funciÛn NO recibe parametros de entrada.
 * LÛgica interna:
 *     en un for recorre el arreglo hasta el indiceAlArreglo que es el que almacena el tope actual
 * Valor de retorno:
 *     No regresa nada
 */
void imprimirLista(){
    int j=0;
    for (j = 0; j < indiceAlArreglo; j++) {
        printf("+--------- # de lista: %d ---------+*\n",j+1);
        imprimeAlumno(listaAlumnos[j]);
    }
}



int menu(){
    int opcion=0;
    printf("\n----------- Menú para la aplicacion de BD para alumnos ---------\n");
    printf("(1) Crear lista.\n");
    printf("(2) Guardar a archivo.\n");
    printf("(3) Leer desde archivo.\n");
    printf("(4) Mostrar lista.\n");
    printf("(5) Agregar alumno. \n");
    printf("(6) Obtener promedio de alumnos.\n");
    printf("(7) Buscar alumno por nombre. \n");
    printf("(8) Buscar alumno por edad. \n");
    printf("(9) Eliminar alumno. \n");
    printf("(10) Modificar datos \n");
    printf("(11) Uso futuro \n");
    printf("(12) Uso futuro \n");
    printf("(0) SALIR\n");
    printf("\n\nElige una opcion:");
    scanf("%d",&opcion);

    return opcion;
}



/**
Manejo de archivos
*/

/*
 Funcion para grabar un ARREGLO DE REGISTROS
 en el archivo Evaluaciones.dat
 */
void grabarRegistros(ALUMNO r[], int tam){
    FILE *ptrF;

    if((ptrF=fopen("Evaluaciones.dat","w"))==NULL){
        printf("el archivo no se puede abrir\n");
    }else{
        fwrite(r,sizeof(ALUMNO),tam,ptrF);
    }

    fclose(ptrF);
}

/*
 Funcion para LEER  REGISTROs
 en el archivo Evaluaciones.dat
 */
void leerRegistros(int tam){

    FILE *ptrF;

    if((ptrF=fopen("Evaluaciones.dat","rb"))==NULL){
        printf("el archivo no se puede abrir\n");
    }
    else{
        //for /*(int i=0;i<tam;i++)*/
        fread(listaAlumnos,sizeof(ALUMNO),tam,ptrF);
    }

    fclose(ptrF);
}

/**
 *
 * Regresa el numero de registros almacenados en el archivo
 *
 */
int registrosEnArchivo(){
    FILE *ptrF;
    int cont=0;
    ALUMNO  basura;
    if((ptrF=fopen("Evaluaciones.dat","rb"))==NULL){
        printf("el archivo no se puede abrir\n");
    }
    else{
        while(!feof(ptrF)){
            if (fread(&basura,sizeof(ALUMNO),1,ptrF))
                cont++;
        }

    }
    fclose(ptrF);
    return cont;
}
#endif /* alumnos_h */

/* 6- Obtener promedio de alumnos*/
float PromedioAlum(){
	float a=0;
	int cont=0;

	for(cont=0;cont<=indiceAlArreglo;cont++){
		a+=listaAlumnos[cont].promedio;
	}
	a=a/indiceAlArreglo;
	return a;
}

/* 7- Buscar alumno por nombre*/
void Buscar(){
	char busco[120];
	int conta=0;
	printf("Nombre del alumno: ");
	scanf("%*c%[^\n]",&busco);
	for(conta=0;conta<=indiceAlArreglo;conta++){
		if(strcmp(busco,listaAlumnos[conta].nombre)==0){
			printf("+--------- # de lista: %d ---------+*\n",conta+1);
			imprimeAlumno(listaAlumnos[conta]);
		}
	}
}

/*8-Buscar alumno por edad*/
void BuscarEdad(){
	int anios=0;
	int conta=0;
	printf("Edad del alumno: ");
	scanf("%d",&anios);
	for(conta=0;conta<=indiceAlArreglo;conta++){
		if(anios==listaAlumnos[conta].edad){
			printf("+--------- # de lista: %d ---------+*\n",conta+1);
			imprimeAlumno(listaAlumnos[conta]);
		}
	}
}
/*9-Eliminar alumno*/
void EliminarAlumno(){
	int cnt=0;
	int cnta=0;
	printf("\nNumero de lista del alumno a eliminar: ");
	scanf("%d",&cnta);
	cnta=cnta-1;
	for(cnt=cnta;cnt<indiceAlArreglo;cnt++){
		listaAlumnos[cnt]=listaAlumnos[cnt+1];
	}
		indiceAlArreglo--;
}

// Modificar2.0 
void Modificar2(){
	int nlista=0;
	char amodificar[20];
	printf("Numero de lista que desea modificar: ");
	scanf("%d",&nlista);
	nlista--;
	
//Variables para cada opcion
	char varedad[]={'e','d','a','d'};
	char vargenero[]={'g','e','n','e','r','o'};
	char varnombre[]={'n','o','m','b','r','e'};
	char varcarrera[]={'c','a','r','r','e','r','a'};
	char varncuenta[]={'c','u','e','n','t','a'};
	char ppromedio[]={'p','r','o','m'};
  
	printf("Que dato desea modificar?\n| edad\t|\tnombre\t|\tcuenta |\n genero\t|\tcarrera\t|\tprom   |\n\n");
	scanf("%*c%[^\n]",&amodificar);
	
    ALUMNO datos;
    if(strcmp(amodificar,varedad)==0){
    	printf("Introduce la edad:");
        scanf("%d",&datos.edad);
        listaAlumnos[nlista].edad=datos.edad;
	}
	if(strcmp(amodificar,vargenero)==0){
		printf("Introduce el genero [M o F]:");
        scanf(" %c",&datos.genero);
        listaAlumnos[nlista].genero=datos.genero;
	}
    if(strcmp(amodificar,varnombre)==0){
    	printf("Introduce el nombre:");
        scanf("%s",datos.nombre);
        strcpy(listaAlumnos[nlista].nombre,datos.nombre);
	}   
   if(strcmp(amodificar,varcarrera)==0){
   	    printf("Introduce Carrera:");
        scanf("%*c%[^\n]",datos.carrera);
        strcpy(listaAlumnos[nlista].carrera,datos.carrera);
   }
   if(strcmp(amodificar,varncuenta)==0){
   	    printf("Introduce numero de cuenta:");
        scanf("%*c%[^\n]",datos.nCuenta);
        strcpy(listaAlumnos[nlista].nCuenta,datos.nCuenta);
   }
   if(strcmp(amodificar,ppromedio)==0){
   	printf("Introduce el promedio: ");
   	scanf("%f",&datos.promedio);
   	listaAlumnos[nlista].promedio=datos.promedio;
   }
}


	

/* 11-Alumnos aprobados y reprobados reprobados*/
void Aprobados(){
	float calif=0;
	int cont=0;
	for(cont=0;cont<indiceAlArreglo;cont++){
		if(listaAlumnos[cont].promedio>=6){
			printf("+--------- # de lista: %d ---------+*\n",cont+1);
			imprimeAlumno(listaAlumnos[cont]);
		}
	}
}

/* 12-Alumnos reprobados*/
void Reprobados(){
	float cal=0;
	int co=0;
	for(co=0;co<indiceAlArreglo;co++){
		if(listaAlumnos[co].promedio<=5){
			printf("+--------- # de lista: %d ---------+*\n",co+1);
			imprimeAlumno(listaAlumnos[co]);
		}
	}
}

/*10-Modificar datos
Con Switch :( */
void Modificar(){
	int nlista=0;
	int amodificar=0;
	printf("Numero de lista que desea modificar: ");
	scanf("%d",&nlista);
	nlista--;
	printf("Qué dato desea modificar?");
	scanf("%d",&amodificar);
		
    ALUMNO datos;
	switch(amodificar){
		case 1:
			printf("Introduce la edad:");
            scanf("%d",&datos.edad);
            listaAlumnos[nlista].edad=datos.edad;
        break;
		case 2:
		    printf("Introduce el genero [M o F]:");
            scanf(" %c",&datos.genero);
            listaAlumnos[nlista].genero=datos.genero;
		break;
		case 3:
			printf("Introduce el nombre:");
            scanf("%s",datos.nombre);
			strcpy(listaAlumnos[nlista].nombre,datos.nombre);
        break;
		case 4:
		    printf("Introduce Carrera:");
            scanf("%*c%[^\n]",datos.carrera);
			listaAlumnos[nlista].carrera[50]=datos.carrera[50]; 
		break;
		case 5:
			printf("Introduce numero de cuenta:");
            scanf("%*c%[^\n]",datos.nCuenta);
            listaAlumnos[nlista].nCuenta[10]=datos.nCuenta[10];
        break;
		case 6:
		    printf("Introduce tu promedio:");
            scanf("%f",&datos.promedio);
            listaAlumnos[nlista].promedio=datos.promedio;
        break;    
	}
}

