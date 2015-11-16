#include <stdio.h>
#include <stdlib.h>

#define TAM 5

//prototipos das funcoes

int insereinicio(int *v, int ele);

int busca (int *v,int i);

int removeInicio( int *v, int *elem);

int main()
{
	int *v,i=0;
	scanf("%d",&n);
	
	v = (int *)malloc(TAM * sizeof(int));
	while(i<n)
	{
		insereinicio(&v,i);
		i++;
	}	

	system("pause");
	return 0;
}

int insereinicio(int *v, int ele)
{
	int i;
	for (i=ele;i>0;i--)
	{
		v[i]=v[i-1];
	}
	scanf("%d",&v[0]);
}

int busca( int *v, int *elem)
{
	
}

int removeInicio(int *v , int *elem)
{
	
