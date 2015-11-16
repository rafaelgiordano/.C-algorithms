// RA408298_AP2-L02_ex19
// Rafael Paschoal Giordano

#include <stdio.h>

float soma(float n){
	if (n==1){
		return 2;}
		else{
		return (1+(n*n))/n + soma(n-1);}
	}
int main(){
	float num;
	scanf("%f",&num);
	printf("%.3f\n", soma(num));

	return 0;
}
