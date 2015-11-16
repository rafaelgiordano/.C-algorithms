// RA408298_AP2-L02_ex07
// Rafael Paschoal Giordano

#include <stdio.h>


int fat(int n1){//faz uma vez para cada fatorial
	if (n1==0) {
	   		return 1;
			   }
	   		else{
 			return n1 * fat(n1-1);
			}
			}

int main(){
	int dividendo, div1, div2, n, k, divisor,res;
	scanf ("%d %d", &n , &k);// le primeiro o numero de cima N , depois o K
	dividendo= fat(n);
	div1= fat(k);
	div2= fat(n-k);
	divisor= div1 * div2;
	res= dividendo / divisor;
	printf("\n%d\n", res);
	system("pause");
	return 0;
}
