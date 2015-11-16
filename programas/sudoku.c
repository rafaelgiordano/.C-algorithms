#include <stdio.h>

void verifica(int ii, int jj,ma[][]);
int linha(int ma[][], int i , int j);

int main() 
{
	int matriz[9][9],j,i;
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d ",&matriz[i][j]);
		}
	}
	verifica(matriz);
	/*for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(matriz[i][j]==0)
			{
				verifica(i,j,matriz);
			}
		}
	}
*/
	system("pause");
	return 0;
}
/*Verifica numero a numero se eh zero*/
void verifica(int ma[][])
{
	int m , k;
	for (m=0;m<9;m++)
	{
		for(k=0;k<9;k++)
		{
			if(ma[m][k] == 0)
			{
				linha(ma[m][k],i,j);
			}
		}
	}
}
int linha(int ma[][], int i, int j)
{
	for(j=0;j<9;j++)
	{
		
	
