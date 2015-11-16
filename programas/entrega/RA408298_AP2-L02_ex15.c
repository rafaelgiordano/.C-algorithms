// RA408298_AP2-L02_ex15
// Rafael Paschoal Giordano

#include <stdio.h>

int conta(int n);

int main(){
	int num;
	scanf ("%d", &num);
	printf("%d\n", conta(num));

	return 0;
}
int conta (int n){
	if (n<10){
	return (n % 10);}
	else {
		 return (n % 10) + conta(n/10);}
		 }

