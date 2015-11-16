// RA408298_AP2-L02_ex20
// Rafael Paschoal Giordano

#include <stdio.h>

int maior(int v[], int n){
	if (n==0){
 	return 0;}
 	else {
	 	 if (v[n] > maior(v,n-1)){//compara valor ate encontrar um maior
	   	 return v[n];}
	   	 else {
	   	 return maior(v, n-1);}
		 }
		 }
int menor(int v[], int n){
	if (n==0){
 	return v;}
 	else {
	 	 if (v[n] < menor(v,n-1)){//compara valor ate encontrar um menor
	   	 return v[n];}
	   	 else {
	   	 return menor(v,n-1);}
		}
		 }
float soma(int v[], int n){
if (n==0) {
	return 0;}
	else {
		return v[n] + soma(v,n-1);}
	}
int prod(int v[], int n){
if (n==0) {
	return 1;}
	else {
		return v[n] * prod(v,n-1);}
	}
int main(){
	int vet[100],i, num;
	float media, somapmedia;
	scanf("%d",&num);//tamanho do vetor
	for (i=1;i<=num;i++){
		scanf("%d",&vet[i]);//leitura vetores
	}
	printf("%d\n",menor(vet,num));
	printf("%d\n",maior(vet,num));
	somapmedia = soma(vet,num);//soma dos elementos
	media = somapmedia / num;// media da soma
	printf("%.0f\n",somapmedia);
	printf("%d\n",prod(vet,num));
	printf("%.3f\n",media);

	return 0;
}
	
	
	
