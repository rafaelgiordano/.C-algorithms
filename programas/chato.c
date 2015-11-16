// AP1_L03_ex36_RafaelGiordano
// RA: 408298
// precisou de fflush para pegar as entradas
#include <stdio.h>

int main() {
	
	char res;
	printf("Mamifero? s ou S para sim, outros = nao\n");//s ou S para sim , outras entradas serao nao
		fflush(stdin);
	scanf("%c",&res);

		if ((res == 's') || (res == 'S')){
			printf("quadrupede? s ou S para sim, outros = nao\n");
			scanf("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S')){
			printf("carnivoro? s ou S para sim, outros = nao\n");
			scanf("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S')){
			printf("leao\n");}
			else { printf("cavalo\n");}
									}		
		else {	
			printf("bipede? s ou S para sim, outros = nao\n");
			scanf("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S'))		{
			printf("onivoro? s ou S para sim, outros = nao\n");
			scanf("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S')){
			printf("homem\n");				}
			else {printf("macaco\n");}
													}
		 	else
				{
			printf("voador? s ou S para sim, outros = nao\n");
			scanf ("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S')){
			printf("morcego\n");			}
			else {printf("baleia\n");}
				}
			}
										}
	  									else {
		printf("Ave? s ou S para sim, outros = nao\n");
		scanf("%c",&res);
		fflush(stdin);
		if ((res == 's') || (res == 'S')){
			printf("Nao Voadora? s ou S para sim, outros = nao\n");
			scanf("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S')){
			printf("Tropical? s ou S para sim, outros = nao\n");
			scanf ("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S')){
				printf("Avestruz\n");}
				else {printf("Pinguim\n");}
											}
			else {
			printf("Nadadora? s ou S para sim, outros = nao\n");
			scanf("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S')){
				printf("Pato\n");}
				else {printf("aguia\n");}
										}}
										else {
			printf("Reptil com casco? s ou S para sim, outros = nao\n");
			scanf("%c",&res);
			fflush(stdin);
		if ((res == 's') || (res == 'S')){
				printf("tartaruga\n");}
			else {
				printf("Carnivoro? s ou S para sim, outros = nao\n");
				scanf("%c",&res);
				fflush(stdin);
		if ((res == 's') || (res == 'S')){
				printf("Crocodilo\n");}
				else {printf("cabra\n");}
				}
											}
												}
		system("pause");
		return 0;
	}
			
