float fniva(float cantidad){
	#define valor .16
	float sub=0.0;
	sub=cantidad/1.16;
	printf("Subtotal: %.3f\nIva: %.2f\nTotal: %.2f",sub,valor,cantidad);
}
