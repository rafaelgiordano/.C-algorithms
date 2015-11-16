//Rafael Paschoal Giordano - RA:408298
//trab6-RafaelGiordano.c

#include <stdio.h>
#include <string.h>

typedef struct {
int idade;
char sexo;
char nome[10];
} pessoa;

// esta função lê os dados de uma pessoa e armazena no endereço para o qual p aponta
void le_dados (pessoa *p)
{
	
	scanf("%d ",&p->idade);
	
	scanf("%c ",&p->sexo);
	
	scanf("%s",&p->nome);
}

// uma função para organizar as pessoas de maneira que seja possível identificar as afinidades. Nesta função você deve usar ponteiros, mas o protótipo fica livre e deve ser implementado de acordo com a sua necessidade

int main()
{
	pessoa p[100],m[100],f[100],aux;
	int num, i,j,casais,contM=0,contF=0;
	scanf("%d",&num);
	for (i = 0 ; i < num ; i++)
	{
		le_dados (&p[i]);
		if (p[i].sexo == 'M'|| p[i].sexo == 'm')
		{
			m[contM]=p[i];
			contM++;
		}
		else 
		{
			f[contF] = p[i];
			contF++;
		}
	}
	if(contF > contM)
	{
		casais = contM;
	}
	else
	{
		 casais = contF;
	}
	for(i = 0;i < contM ; i++)
	{
		for(j = 0; j < contM-1; j++)
		{
			if(m[j].idade < m[j+1].idade)
			{
				aux = m[j];
				m[j] = m[j + 1];
				m[j + 1] = aux;
			}
		}
	}
	for(i = 0; i < contF ; i++)
	{
		for(j = 0; j < contF-1; j++)
		{
			if(f[j].idade < f[j+1].idade)
			{
				aux = f[j];
				f[j] = f[j + 1];
				f[j + 1] = aux;
			}
		}
	}
	for(i = 0; i < casais ; i++)
	{
		printf("%s (%c,%d) e ", m[i].nome , m[i].sexo , m[i].idade);
		printf("%s (%c,%d)", f[i].nome , f[i].sexo , f[i].idade);
		printf("\n");
	}
		
	system("pause");
	return 0;
}
