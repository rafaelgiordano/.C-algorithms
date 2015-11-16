// RA408298_AP2-L02_ex01
// Rafael Paschoal Giordano

#include <stdio.h>

int somatorio(int m , int n){
	if (m == n+1){
	   	  return 0;
			 }
				else {
					 return m + somatorio(m+1 , n);
					 }
}
int main(){
	
	int m , n ;
	scanf ("%d %d", &m , &n);//primeiro numero deve ser o menor
	printf("\n%d\n", somatorio(m , n));


	return 0;
}
