// RA408298_AP2-L02_ex06
// Rafael Paschoal Giordano

#include <stdio.h>

int tam(char nome[]){
	if(nome[0] == '\0'){
			return 0;
			}
			else {
				 return 1 + tam(&nome[1]);
				 }
				 }
 int main(){
 	 char n[10001];
 	 int res;
 	 gets(n);
 	 res=tam(n);
 	 printf("\n%d\n", res);

 	 return 0;
	 }
