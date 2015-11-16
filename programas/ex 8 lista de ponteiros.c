//ex 8 lista de ponteiros

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	int RA;
	float nota;
}aluno;

int main()
{
	aluno *a,*p;
	int i, n;
	scanf("%d",&n);
	a = (aluno *) malloc(n * sizeof(aluno));
	if( a == NULL)
	{
		printf("memoria nao alocada\n");
		exit(1);
	}
	p=a;
	for (i=0; i< n; i++)
	{
		scanf("%d", &p->RA);
		scanf("%f", &p->nota);
		p++;
	}
	p=a;
	for( i=0; i<n ; i++)
	{
		if((p->nota < 6) && (p->nota >= 5))
		{
			printf("o aluno %d ficou de SAC com %.2f\n", p->RA, p->nota);
		}
		p++;
	}
	free(a);
	system("pause");
	return 0;
}
