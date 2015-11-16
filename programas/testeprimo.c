#include <stdio.h>

int main()
{
	int i,cont=0;
	for(i=1;i<=6857;i++)
	{
		if(6857 % i==0)
		{
			cont++;
			printf("%d\n",i);
		}
		
	}
	if(cont == 2)
	{
		printf("%daeee\n");	
	}
	system("pause");
	return 0;
}
