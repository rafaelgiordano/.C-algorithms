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
	printf ("\nCONNECT 4\n");
	do//do-while do Menu Principal, só sai se o usuário digitar 1 para Jogar o Connect 4
	{
		printf ("\nMENU PRINCIPAL\n\n");
		printf ("(1) - Jogar o Connect 4\n");
		printf ("(2) - Instrucoes\n");
		printf ("Sua opcao: ");
		scanf ("%d", &op);
		while (op < 1 || op > 2)//tratamento de erro caso seja digitada uma opção inválida
		{
			printf ("Opcao invalida! Digite uma opcao de 1 a 2: ");
			scanf ("%d", &op);
		}
		if (op == 2)//instruções do programa
		{
			printf ("\n\nINTRUCOES GERAIS SOBRE O JOGO:");
			printf ("\n\nCOMO JOGAR\nEscolha a opcao (1) do Menu Principal - Jogar o Connect 4.\n\n");
			printf ("COMO ESCOLHER O TAMANHO DO TABULEIRO\nEscolha a opcao (1) do Menu Principal - Jogar o Connect 4. No Menu de Opcao de Jogo, escolha entre as 4 opcoes disponiveis.\n\n");
			printf ("COMO ESCOLHER ONDE COLOCAR A FICHA\nDigite o numero da coluna onde voce deseja colocar a ficha.\n\n");
			printf ("COMO SAIR DO JOGO\nPara sair do jogo voce pode:\n");
			printf ("\t1. Encher todas as colunas de fichas.\n");
			printf ("\t2. Digitar o numero 100 quando for digitar o numero da coluna.\n\n");
		}
	}while (op != 1);
	printf ("\nMENU DE OPCAO DE JOGO:\n\n");
	printf ("(1) - Tabuleiro no formato 7 x 6\n");
	printf ("(2) - Tabuleiro no formato 8 x 7\n");
	printf ("(3) - Tabuleiro no formato 9 x 7\n");
	printf ("(4) - Tabuleiro no formato 10 x 7\n");
	printf ("Sua opcao de jogo: ");
	scanf ("%d", &op);
	while (op < 1 || op > 4)//tratamento de erro caso seja digitada uma opção inválida
	{
		printf ("Opcao invalida! Digite uma opcao de 1 a 4: ");
		scanf ("%d", &op);
	}
	switch (op)
	//bloco switch para escolher qual será o tamanho do tabuleiro
	//a variável k recebe o tamanho máximo das linhas
	//a variável n recebe o tamanho máximo das colunas
	{
		case 1:
			printf ("Voce escolheu a opcao de jogo com 7 linhas e 6 colunas\n");
			k = 7;
			n = 6;
		break;
		case 2:
			printf ("Voce escolheu a opcao de jogo com 8 linhas e 7 colunas\n");
			k = 8;
			n = 7;
		break;
		case 3:
			printf ("Voce escolheu a opcao de jogo com 9 linhas e 7 colunas\n");
			k = 9;
			n = 7;
		break;
		case 4:
			printf ("Voce escolheu a opcao de jogo com 10 linhas e 7 colunas\n");
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
    //o tabuleiro é mostrado como uma grande tabela, onde o tamanho de cada quadrado é de 4, sendo o último 4 + 1.
    //por essa razão, as fórmulas abaixo são k * 4 + 1 e n * 4 + 1.
    //as linhas 0, 4, 8, 12, ... são as linhas cheias de tracejados. Por essa razão temos i % 4.
    //na linha i % 4, as colunas 0, 4, 8, ... devem ter um espaço ao invés do traço. Por essa razão temos j % 4.
    //nas linhas 2, 6, 10, ... e nas colunas 2, 6, 10, ... temos o centro do quadrado. É neste momento
    //que deve ser impresso na tela a ficha, caso ela exista, ou um espaço, caso ela não exista.
    //na hora de imprimir a ficha, usamos printf ("%c", 254), que imprime na tela um pequeno quadrado preenchido (utilização da tabela ASCII).
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
    do//do-while principal, garante a continuação do programa até o tabuleiro estar completamente preenchido ou o usuário digitar 100
    {
		a = 0; 
		cont = 0;
	  	printf ("\nDigite a coluna desejada (de 1 a %d). Caso queira sair do jogo, digite 100\n", n);
	  	scanf ("%d", &p);
	  	while ((p < 1 || p > n) && p != 100)
	  	//tratamento de erro caso a coluna digitada não exista, sendo diferenete de 100
	  	{
		 	  printf ("\nColuna inexistente! Digite um numero de 1 a %d.\nCaso queira sair do jogo, digite 100\n", n);
		 	  scanf ("%d", &p);
        }
        if (p != 100)//usuário deseja continuar jogando
        {
        	for (i = k - 1; i >= 0; i--)
        	//for que verifica se há fichas na coluna, da última linha até a primeira (se necessário)
        	{
		 		if (m[i][p -1] == 0)
		 		{
					m[i][p -1] = 1;
					i = -1;//como já achou um espaço vago, não há necessidade de continuar no for
				}
				else
				{
					cont++;
				}
			}
			if (cont == k)//significa que a coluna está cheia
			{
				a = -1;
				printf ("\nA coluna %d esta cheia.\n", p);
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
		}
	}while ((a == -1) && (p != 100));
	system("pause");
	return 0;
}
