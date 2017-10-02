#include <stdio.h>
int main(){
	int pp=0;
	int pl=0;
	printf("Para:\nPiedra=1 Papel=2 Tijera=3");
	printf("\n\nJugador uno: ");
	scanf("%d",&pp);
	printf("Jugador dos: ");
	scanf("%d",&pl);
	if(pp<=3&&pp>=1&&pl<=3&&pl>=1){
		if(pp<pl){
			if(pp==1&&pl==3){printf("Gana el jugador 1");
			}else{printf("Gana el jugador 2");
			}
		}
		if(pl<pp){
			if(pl==1&&pp==3){printf("Gana el jugador 2");
			}else{printf("Gana el jugador 1");
			}
		}
		if(pp==pl){
			printf("Empate");
		}
		}else{printf("Los valores ingresados son incorrectos");
		}
	}
