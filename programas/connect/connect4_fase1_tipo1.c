//GIULIANNO RAPHAEL SBRUGNERA RA: 408093
//RAFAEL PASCHOAL GIORDANO RA: 408298
//CONNECT 4 - FASE 1
//opções de jogo:
//(1) - 7 x 6
//(2) - 8 x 7
//(3) - 9 x 7
//(4) - 10 x 7
#include <stdio.h>

int main ()
{
 	int m[10][7],//matriz utilizada
 		x, //contador
		i,//contador
		j,//contador
		k,//quantidade de linhas da matriz
		n,//quantidade de colunas da matriz
		cont,//contador
		a,//variável de controle
		op,//opção de jogo
		p;//posição que vai colocar a ficha
	char resp;
	printf ("\n\t\t\tMENU DE OPCAO DE JOGO:\n\n");
	printf ("(1) - Tabuleiro no formato 7 x 6\n");
	printf ("(2) - Tabuleiro no formato 8 x 7\n");
	printf ("(3) - Tabuleiro no formato 9 x 7\n");
	printf ("(4) - Tabuleiro no formato 10 x 7\n");
	printf ("Sua opcao de jogo: ");
	scanf ("%d", &op);
	switch (op)
	{
		case 1:
			k = 7;
			n = 6;
		break;
		case 2:
			k = 8;
			n = 7;
		break;
		case 3:
			k = 9;
			n = 7;
		break;
		case 4:
			k = 10;
			n = 7;
		break;
	}	
    for (x = 1; x <= n; x++)
    {
		printf("#%d\t", x);
	}
	printf("\n\n");
	for (i = 0; i < k; i++)
    {
	 	for (j = 0; j < n; j++)
	 	{
		 	m[i][j] = 0;
 			printf ("%d\t", m[i][j]);
		}
		printf ("\n\n");
    }
    do
    {
		a = 0; 
		cont = 0;
	  	printf ("digite a coluna: ");
	  	scanf ("%d", &p);
	  	while (p < 1 || p > n)
	  	{
		 	  printf ("coluna inexistente. digite um numero de 1 a %d: ", n);
		 	  scanf ("%d", &p);
        }
        for (i = k - 1; i >= 0; i--)
        {
		 	if (m[i][p -1] == 0)
		 	{
				m[i][p -1] = 1;
				i = -1;
			}
			else
			{
				cont++;
			}
		}
		if (cont == k)//coluna cheia
		{
			a = -1;
			printf ("A coluna %d esta cheia.\n\n", p);
		} 
		else
		{
			for (x = 1; x <= n; x++)
        	{
			printf("#%d\t",x);
			}
			printf("\n\n");
			for (i = 0; i < k; i++)
    		{
	 			for (j = 0; j < n; j++)
	 			{
 					printf ("%d\t", m[i][j]);
 					if (m[i][j] == 0)//tem pelo menos um espaço ainda
 					{
						a = -1;
					}
				}
				printf ("\n\n");
    		}
		}
		printf ("\ndeseja continuar jogando? (S/N)\n");
    	fflush(stdin);
    	scanf ("%c", &resp);
	}while ((a == -1) && (resp != 'N' && resp != 'n'));
	return 0;
}
			
 		
