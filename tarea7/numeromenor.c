#include <stdio.h>
int main (){
	int num1=0;
	int num2=0;
	int num3=0;
	printf("Dame el primer numero");
	scanf("%d",&num1);
	printf("Dame el segundo numero");
	scanf("%d",&num2);
	printf("Dame el tercer numero");
	scanf("%d",&num3);
	if(num1>0&&num2>0&&num3>0&&num1!=num2&&num1!=num3&&num2!=num3){
		if(num1<num2&&num1<num3){
			printf("%d"" Es el menor",num1);
		}
		if(num2<num1&&num2<num3){
			printf("%d"" Es el menor");
		}
		if(num3<num2&&num3<num1){
			printf("%d"" Es el menor");
		}
	}else{printf("Los numeros deben ser mayores que 0 y diferentes entre si");
	}
}
