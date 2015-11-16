// Rafael Paschoal Giordano - RA:408298

#include <stdio.h>

int mdc(int x , int y);

int main(){
	int x[1000000], y[1000000],//vetores para armazenar todas as entradas
	i=0,cont;//contadores para as entradas
	scanf("%d %d", &x[i], &y[i]);//le o primeiro digito

	while(x[i]!=0 && y[i]!=0)//loop que le enquanto entradas diferentes de zero
	{
	i++;
	scanf("%d %d", &x[i], &y[i]);//leitura nao importa ordem 
	}
	cont=i;
	for(i=0;i<cont;i++)//loop que chama a funcao e imprime o resultado
	{
	printf("%d\n", mdc(x[i],y[i]));//chamada da funcao ja imprimindo
	}
	return 0;
}
/*Funcao que faz o algoritmo de EUCLIDES , se a divisao de um numero pelo o outro for exata ele retorna o menor deles,
senao ele continua em recursao e nas tentativas seguintes ele testa o numero menor com o resto da divisao do maior pelo menor testado previamente*/

int mdc (int x, int y)
{
	if (x % y == 0)//se o resto de um pelo outro for zero , ele retorna o menor
	{
		if (y <= x)
		{
 	   		return y;//retorna o menor valor , neste caso y
		} 
		else
		{
 	   		return x;//retorna o menor valor , neste caso x
		}
	}
	else 
	{
		if(x > y)//retorna para testar na funcao se x eh maior
		{
			return mdc ( y, ( x % y ) );//com esta chamada
		}
		else
		{
	   	   	return mdc( x ,( y % x ) );//ou com esta se y for maior
		}
	}
}	  
