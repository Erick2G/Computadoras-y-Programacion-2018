float fniva(float cantidad){
	#define valor .16
	float sub=0.0;
	sub=cantidad/1.16;
	printf("Subtotal: %.3f\nIva: %.2f\nTotal: %.2f",sub,valor,cantidad);
}
int fnDimension(int n, int m){
	int g=0;
	int f=0;
	for(g=1;g<=m;g=g+1){
		for(f=1;f<=n;f=f+1){
			printf("x ");
		}printf("\n");
	}return 0;
}
