// RA408298_AP2-L02_ex08
// Rafael Paschoal Giordano

#include <stdio.h>

int cont (char c[], char s){
	if (c[0] == '\0'){
	   		 return 0;}
      else {	
	  	   if (c[0]== s){
	  		  return 1+ cont(&c[1],s);}
	  		  else{
			  	   return cont(&c[1],s);}
			  }
			  }
int main() {
	char nome[101], letra;//tamanho nao fornecido no enunciado
	gets(nome);//le o string ate enter pressionado
	scanf ("%c", &letra);
	printf("%d\n", cont(nome,letra));

	return 0;
}
