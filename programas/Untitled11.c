/* -----------------------------------------------------
   Algoritmos e Programacao II
   Trabalho 5 - Sudoku
   Descricao: este programa resolve um jogo de sudoku, 
   			  usando recursao.
   Entradas.: uma grade de sudoku com espacos em branco.
   Saidas...: sudoku resolvido, ou a mensagem 'nao tem
              solucao' caso o sudoku seja impossivel.
   Autores..: Giulianno Raphael Sbrugnera RA: 408093
   			  Rafael Paschoal Giordano    RA: 408298
   ----------------------------------------------------- */

/* bibliotecas do sistema */
#include <stdio.h>

void verifica(int t[9][9]);

void resolve(int t[9][9], int i, int j);

void imprime(int t[9][9]);

void le(int t[9][9]);

int main()
{
	int sudoku[9][9],	//matriz que recebe os numeros do sudoku
		i, 				//contador
		j,				//contador
		teste = 0;		//flag
	/* chamada da funcao que le a matriz do jogo*/
	le(sudoku);

	/* chamada da funcao que procura os espacos em branco na matriz */
	verifica(sudoku);
	
	/* loop que verifica se o sudoku tem solucao */
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(sudoku[i][j] == 0)
			{
				teste = 1;
			}
		}
	}

	//if(teste == 0)
	//{
		imprime(sudoku);
	//}
	//else
	//{
	//	printf("nao tem solucao\n");
	//}

	system("pause");
	return 0;
}
/* Funcao VERIFICA passa toda a matriz procurando por zeros, se o numero for 0 ele chama a funcao resolve*/

void verifica(int t[9][9])
{
	int i , j;
	
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(t[i][j] == 0)
			{
				resolve(t, i , j);
			}	
		}
	}

}

/* Funcao resolve verifica as possibilidades do numero passado da verifica,quando houver apenas uma possibilidade ele preenche 
a posicao com o numero adequado*/
void resolve(int t[9][9], int i , int j)
{
	int num[10],k ,l,m,cont=0;//vetor para verificacao dos numeros possiveis e contadores dos loops
	
	/*loop que zera o vetor antes de comecar a verificar*/

	for(k = 1; k <= 9; k++)
	{
		num[k] = 0;
	}

	/*percorre a linha e a coluna da posicao e se o numero for diferente de 0 ele preenche o vetor do numero com o mesmo*/
	for(l = 0; l < 9; l++)
	{
		/*preenche o vetor que nao eh zero*/
		if(t[i][l] != 0)
		{
			num[t[i][l]] = t[i][l];
		}
	
		if(t[l][j] != 0)
		{
			num[t[l][j]] = t[l][j];
		}
	}
	/*percorre a coluna 3 por 3 da posicao preenchendo o vetor com os numeros diferentes de 0*/
	for(l =(3*(i/3)); l <= (2+(3*(i/3))); l++)
	{
		for(m = (3*(j/3)); m <= (2+(3*(j/3))); m++)
		{
			if(t[l][m] != 0)
			{
				num[t[l][m]] = t[l][m];
			}
		}
	}
	/*loop que verifica quantas posicoes do vetor nao foi preenchida*/
	for(l = 1;l <= 9; l++)
	{
		/*significa que o vetor da posicao ele nao foi encontrado nas buscas e este eh uma possibilidade*/
		if (num[l] == 0)
		{
			cont++;
		}
	}
	/*se o cont for 1 , significa que para aquela posicao ha apenas uma possibilidade de numero e este sera preenchido*/
	if(cont == 1)
	{
		for(l = 1; l <= 9; l++)
		{
			if (num[l] == 0)
			{
				t[i][j]=l;
			}
		}
		/*se o contador for 1 , significa que a posicao da matriz principal foi preenchida entao ele volta a funcao verifica do comeco , 
		pois se este nao for preenchido ele passara para o proximo numero do loop do verifica e continuara para frente, quando preenche um , 
		este volta a verificar desde o comeco pois numeros ja verificados talvez possam agora ser preenchidos*/
	verifica(t);
	}

}
	/*Funcao que imprime a matriz no final caso seja sudoku*/
void imprime(int t[9][9])
{
	int i , j;

	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			printf("%d", t[i][j]);
			/*if para nao imprimir espaco apos o ultimo elemento da linha da matriz*/
			if(j != 8)
			{	
				printf(" ");
			}
		}
	printf("\n");
	}
	
}

void le(int t[9][9])
{
	int i , j;
	/* loop que le a matriz */
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			scanf("%d", &t[i][j]);
		}
	}
}
