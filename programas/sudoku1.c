#include <stdio.h>

void verifica(int t[9][9]);

void resolve(int t[9][9], int i, int j , int valor);

int main()
{
	int tab[9][9], i, j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
		scanf("%d",tab[i][j]);
		}
	}
	verifica(tab);
	
return 0;
}

void verifica(int t[9][9])
{
	int i , j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(t[i][j]==0)
			{
			resolve(t, i , j,1);
			}	
		}
	}

}

void resolve(int t[9][9], int i , int j,int valor)
{
	int k ,l,m;
	for(k=valor;k<=9;k++)
	{
	t[i][j]=k;
	for(l=0;l<9;l++)
	{
		if(t[i][l]==t[i][j])
		{
		return resolve(t,i,j,k+1);
		}
	}
	for(l=0;l<9;l++)
	{
		if(t[l][j]==t[i][j])
		{
		return resolve(t,i,j,k+1);
		}
	}
	}
	
}
