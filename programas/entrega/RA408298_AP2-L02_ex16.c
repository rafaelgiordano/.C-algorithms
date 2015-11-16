// RA408298_AP2-L02_ex16
// Rafael Paschoal Giordano

#include <stdio.h>

int maior(int v[], int n){
	if (n==0){
 	return 0;}
 	else {
	 	 if (v[n] > maior(v,n-1)){
	   	 return v[n];}
	   	 else {
	   	 return maior(v, n-1);}
		 }
		 }
int main() {
	int num, i, vet[100];//tamanho vetor nao definido no enunciado
	scanf("%d", &num);// leitura tamanho do vetor
	for (i=1;i<=num;i++){
		scanf("%d",&vet[i]);//leitura valores do vetor
		}
	printf("%d\n", maior(vet,num));

	return 0;
}
	
