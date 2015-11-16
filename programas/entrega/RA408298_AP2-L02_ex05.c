// RA408298_AP2-L02_ex05
// Rafael Paschoal Giordano

#include <stdio.h>

int dig (int num){
	int i ;
	if (num < 10){
	   	  return 1;}
	   	  else{
		  	   return 1 + dig(num/10);}
}
int main(){
	int n ;
	scanf ("%d", &n);
	printf ("\n%d\n", dig(n));

	return 0;
}
