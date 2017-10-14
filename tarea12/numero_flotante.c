#include <stdio.h>
int main(){
	int ent=0;
	float sec=0;
	float ter=0;
	printf("Ingrese 3 numeros:\n Numero entero: ");
	scanf("%d",&ent);
	printf(" Ingrese un numero con decimal: ");
	scanf("%f",&sec);
	printf(" Inseta otro numero con decimal: ");
	scanf("%f",&ter);
	printf("\n De los siguientes numeros: %d   %f   %f\n\n",ent,sec,ter);
	if(ent>sec&&ent>ter){
		if(sec==ter){printf("  %d es el mayor\n  %f y %f son iguales",ent,sec,ter);
		}else{printf("  %d es el mayor\n",ent);
		}
		if(sec<ter){printf("  %f es el menor",sec);
	}
		if(ter<sec){printf("  %f es el menor",ter);
		}
	}
	if(sec>ent&&sec>ter){
		if(ent==ter){printf("  %f es el mayor\n  %d y %f son iguales",sec,ent,ter);
		}else{printf("  %f es el mayor\n",sec);
		}
		if(ent<ter){printf("  %d es el menor",ent);
		}
		if(ter<ent){printf("  %f es el menor",ter);
		}
		
	}
	if(ter>ent&&ter>sec){
		if(ent==sec){printf("  %f es el mayor\n  %d y %f son iguales",ter,ent,sec);
		}else{printf("  %f es el mayor\n",ter);
		}
		if(ent<sec){printf("  %d es el menor",ent);
		}
		if(sec<ent){printf("  %f es el menor",sec);
		}
	}
	if(ent==sec&&sec==ter){printf("Los 3 numeros son iguales");
	}
	if(ent<sec&&sec==ter){printf("  %f y %f son iguales\n  %d es menor que los otros dos numeros",sec,ter,ent);
	}
	if(sec<ent&&ent==ter){printf("  %d y %f son iguales\n  %f es menor que los otros dos numeros",ent,ter,sec);
	}
	if(ter<ent&&ent==sec){printf("  %d y %f son iguales\n  %f es menor que los otros dos numeros",ent,sec,ter);
	}
}
