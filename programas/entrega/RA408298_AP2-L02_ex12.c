// RA408298_AP2-L02_ex12
// Rafael Paschoal Giordano

#include <stdio.h>

int prod(int num1, int num2){
	if (num2 == 0) {
	   	 return 0;}
	   	 else{
		 	  return num1 + prod (num1, num2-1);
			  }
			  }
 int main() {
 	 int n1, n2;
 	 scanf("%d %d", &n1, &n2);
 	 printf("%d\n", prod(n1,n2));

 	 return 0;
	 }
	 
