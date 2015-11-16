// RA408298_AP2-L02_ex10
// Rafael Paschoal Giordano

#include <stdio.h>

int pbin(int v[], int t, int finalizador, int numpesq){
	int cont;
	if (((t/2)< 0) || ((t/2)==finalizador)){
		return 0;}
		else {
	if (numpesq == v[t/2]){
		return 1;}
		else {
			if (v[t/2] > numpesq){
				return pbin(v, t-t/2, finalizador, numpesq);}
				else { 
					if (v[t/2] < numpesq){
				return pbin(v, t+t/2,finalizador, numpesq);}
					}
			}
			}	
				
}
int main() {
	int vet[100], i , tam,pesq, res=0;//tamanho do vetor definido para maximo 100
	scanf("%d", &tam);//numero de elementos do vetor, nao definido no enunciado
	for (i=0;i<tam;i++){
		scanf ("%d", &vet[i]);//elementos do vetor
				}
	scanf("%d", &pesq);// numero procurado
	res = pbin(vet, tam ,tam, pesq);
	if (res == 1){
		printf("O numero %d foi encontrado no vetor.\n", pesq);
	} else{
	printf("O numero %d nao foi encontrado no vetor.\n", pesq);}
	system("pause");
	return 0;
}
