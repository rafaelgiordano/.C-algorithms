// RA408298_AP2-L02_ex02
// Rafael Paschoal Giordano

#include <stdio.h>
#define MAX 100 //se for maior eh mais simples mudar

int soma(int vet[] , int n){

	if (n == 0){
	   	  return 0;
		  }
		  else {

		  	   return vet[n] + soma(vet , n-1);
			   }
			   }
 int main(){
 	 int v[MAX], j, num;
 	 scanf ("%d", &num); //quantidade de vetores
 	 for (j=1; j <= num; j++){
	 scanf("%d", &v[j]);

	 }
	 printf("\n%d\n", soma(v,num));

	 return 0;
	 }
	 
