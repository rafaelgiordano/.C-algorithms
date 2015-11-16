//GIULIANNO RAPHAEL SBRUGNERA RA: 408093
//RAFAEL PASCHOAL GIORDANO RA: 408298
//Algoritmos e Programação II
//CONNECT 4 - FASE 1
//opções de jogo:
//(1) - 7 linhas x 6 colunas
//(2) - 8 linhas x 7 colunas
//(3) - 9 linhas x 7 colunas
//(4) - 10 linhas x 7 colunas
#include <stdio.h>

int main ()
{
	int m[10][7],//matriz utilizada
 		x = 0, //contador
		i = 0,//contador
		j = 0,//contador
		w = 0,//contador
		z = 0,//contador
		cont = 0,//contador
		a,//variável de controle
		op,//opção de jogo
		k,//quantidade de linhas da matriz
		n,//quantidade de colunas da matriz
		p;//posição que vai colocar a ficha
	char resp;//resposta do usuário sobre continuar o jogo
	printf ("\n\t\t\tMENU DE OPCAO DE JOGO:\n\n");
	printf ("(1) - Tabuleiro no formato 7 x 6\n");
	printf ("(2) - Tabuleiro no formato 8 x 7\n");
	printf ("(3) - Tabuleiro no formato 9 x 7\n");
	printf ("(4) - Tabuleiro no formato 10 x 7\n");
	printf ("Sua opcao de jogo: ");
	scanf ("%d", &op);
	while (op < 1 || op > 4)
	//tratamento de erro caso seja digitada uma opção inválida
	{
		printf ("Opcao invalida! Digite uma opcao de 1 a 4: ");
		scanf ("%d", &op);
	}
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
	printf ("\n  ");
    for (x = 1; x <= n; x++)//for que imprime na tela a numeração das colunas
    {
		printf("#%d  ", x);
	}
	printf("\n\n");
	for (i = 0; i < k; i++)//for que zera a matriz
    {
	 	for (j = 0; j < n; j++)
	 	{
		 	m[i][j] = 0;
		}
    }
    for (i = 0; i < k * 4 + 1; i++)//for que vai de linha a linha 
	{
		if (i % 4 == 0)//significa que é a linha que possui espaço---espaço
		{
			for(j = 0; j < n * 4 + 1; j++)//for que imprime as linhas
			{
				if (j % 4 == 0)//signica que deve haver um espaço
				{
					printf (" ");
				}
				else
				{
					printf ("-");
				}
			}
			printf ("\n");
		}
		else//são as linhas de dentro do quadrado, formadas por |espaçoespaçoespaço|
		{
			for(j = 0; j < n * 4 + 1; j++)//for que imprime as linhas
			{
				if (j % 4 == 0)//signica que deve haver um |
				{
					printf ("|");
				}
				else
				{
					if (((j + 2) % 4 == 0) && ((i + 2) % 4 == 0))//centro do quadrado
					{
						if (m[w][z] == 1)
						{
							printf ("%c", 254);
						}
						else
						{
							printf (" ");
						}
						z++;//z representa as n colunas
						if (z >= n)
						{
							w++;//m representa as k linhas
							z = 0;
						}
					}
					else
					{
						printf (" ");
					}
				}
			}
			printf ("\n");
		}
	}
    do
    {
		a = 0; 
		cont = 0;
	  	printf ("\nDigite a coluna: ");
	  	scanf ("%d", &p);
	  	while (p < 1 || p > n)
	  	//tratamento de erro caso a coluna digitada não exista
	  	{
		 	  printf ("\nColuna inexistente. Digite um numero de 1 a %d: ", n);
		 	  scanf ("%d", &p);
        }
        for (i = k - 1; i >= 0; i--)
        //for que verifica se há fichas na coluna, da última linha até a primeira (se necessário)
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
		if (cont == k)//significa que a coluna está cheia
		{
			a = -1;
			printf ("\nA coluna %d esta cheia.\n\n", p);
		} 
		else
		{
			printf ("\n  ");
    		for (x = 1; x <= n; x++)//for que imprime na tela a numeração das colunas
    		{
				printf("#%d  ", x);
			}
			printf("\n\n");
			for (i = 0; i < k; i++)
    		{
	 			for (j = 0; j < n; j++)
	 			{
 					if (m[i][j] == 0)//tem pelo menos um espaço ainda
 					{
						a = -1;//garante a continuação do programa
					}
				}
    		}
    		w = 0;
    		z = 0;
    		for (i = 0; i < k * 4 + 1; i++)//for que vai de linha a linha 
			{
				if (i % 4 == 0)//significa que é a linha que possui espaço---espaço
				{
					for(j = 0; j < n * 4 + 1; j++)//for que imprime as linhas
					{
						if (j % 4 == 0)//signica que deve haver um espaço
						{
							printf (" ");
						}
						else
						{
							printf ("-");
						}
					}
					printf ("\n");
				}
				else//são as linhas de dentro do quadrado, formadas por |espaçoespaçoespaço|
				{
					for(j = 0; j < n * 4 + 1; j++)//for que imprime as linhas
					{
						if (j % 4 == 0)//signica que deve haver um |
						{
							printf ("|");
						}
						else
						{
							if (((j + 2) % 4 == 0) && ((i + 2) % 4 == 0))//centro do quadrado
							{
								if (m[w][z] == 1)
								{
									printf ("%c", 254);
								}
								else
								{
									printf (" ");
								}
								z++;//z representa as n colunas	
								if (z >= n)
								{
									w++;//m representa as k linhas
									z = 0;
								}
							}
							else
							{
								printf (" ");
							}
						}
					}
					printf ("\n");
				}
			}
		}
		printf ("\nDeseja continuar jogando?\n(S) - SIM\n(N) - NAO\n");
    	fflush(stdin);
    	scanf ("%c", &resp);
	}while ((a == -1) && (resp != 'N' && resp != 'n'));
	return 0;
}
