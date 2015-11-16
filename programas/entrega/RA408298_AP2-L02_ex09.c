// RA408298_AP2-L02_ex09
// Rafael Paschoal Giordano

#include <stdio.h>
#include <string.h>

char inv(char nome[], int i){
	if(i == 0){
			return 0;
			}
			else {
				 printf("%c", nome[i-1]);
				 return inv(nome, i-1);
				 }
				 }
int main(){
	char n[101];//tamanho do vetor nao fornecido , para maiores alterar
	int i;
	gets(n);
	i = strlen(n);
	inv(n, i);
	printf("\n");
	return 0;
}
