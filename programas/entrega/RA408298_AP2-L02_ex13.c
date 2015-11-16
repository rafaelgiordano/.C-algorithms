// RA408298_AP2-L02_ex13
// Rafael Paschoal Giordano

#include <stdio.h>

int fib(int n){
	if(n==0){
	return 0;}
	else {
	  	if (n==2||(n==1)){
		   return 1;}
		   else {
		      return fib(n-1) + fib(n-2);}
			  }
	}
			  
int main(){
	int num,i;
	scanf ("%d", &num);
		printf("%d \n", fib(num));

		return 0;
		}
		
			  

