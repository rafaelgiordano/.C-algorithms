//Rafael Paschoal Giordano - RA:408298
//trab6-RafaelGiordano.c

/* ----------------------------------------------------------------------------------------------

Programa: Trabalho6.c - 07/01/13
Objetivo: "A partir da idade da pessoas encontrar casais a partir da proximidade desses numeros"
Entradas: numero de pessoas e dados das mesmas, idade , sexo e nome , nesta ordem
Saídas..: casais formados a partir de suas idades
Autor...: Rafael Paschoal Giordano - RA: 408298
-------------------------------------------------------------------------------------------------*/

/* bibliotecas do sistema */

#include <stdio.h>
#include <string.h>

/*struct utilizado na implementação*/

typedef struct {
int idade;//indica idade da pessoa
char sexo;//indida o sexo da pessoa
char nome[10];//indica o nome da pessoa
} pessoa;

// esta função lê os dados de uma pessoa e armazena no endereço para o qual p aponta
void le_dados (pessoa *p)
{
	/*entradas do usuario*/
	scanf("%d ",&p->idade);
	
	scanf("%c ",&p->sexo);
	
	scanf("%s",&p->nome);
}
/*uma função para organizar as pessoas de maneira que seja possível identificar as afinidades. 
Nesta função você deve usar ponteiros, mas o protótipo fica livre e deve ser implementado de acordo com a sua necessidade.*/

/*Esta função ordena o vetor de ordem decrescente conforme a idade das pessoas dessa forma o mais velho tera preferencia de encontrar alguem.*/
void ordena (pessoa *p,int cont)
{
	int i , j;//variaveis para controlar o loop
	pessoa aux;//variavel para ajudar na ordenaçao do vetor
	for(i = 0;i < cont ; i++)
	{
		for(j = 0; j < cont-1; j++)
		{
			if(p[j].idade < p[j+1].idade)
			{
				aux = p[j];
				p[j] = p[j + 1];
				p[j + 1] = aux;
			}
			/*se idades iguais ele ordena alfabeticamente*/
			if ((p[j].idade == p[j+1].idade) && (strcmp(p[j].nome, p[j + 1].nome)) > 0)
			{
				aux = p[j];
				p[j] = p[j + 1];
				p[j + 1] = aux;
			}
		}
	}
}
int main()
{
	pessoa p[100],
	m[100],f[100];//variaveis para seperar mulheres de homens, formando grupos a parte.
	int num,//numero de pessoas
	i,j,//contadores para os loops
	casais,contM=0,contF=0;//contadores para o numero de casais , de homens e de mulheres.
	scanf("%d",&num);//entrada do usuario
	/*loop que chama a função de leitura e ja passa os valores para o vetor M se for homem ou F se for mulher*/
	for (i = 0 ; i < num ; i++)
	{
		le_dados (&p[i]);
		/*if para separar sexo Masculino de feminino*/
		if (p[i].sexo == 'M'|| p[i].sexo == 'm')
		{
			m[contM]=p[i];
			contM++;//contador aumenta se for homem.
		}
		else 
		{
			f[contF] = p[i];
			contF++;//contador aumenta de for mulher
		}
	}
	/*numero de casais é dado pelo menor numero de pessoas de um mesmo sexo*/
	if(contF > contM)
	{
		casais = contM;
	}
	else
	{
		 casais = contF;
	}
	/*chamada das funçoes ordena, que ordena ambos os vetores na ordem decrescente*/
	ordena(&m,contM);//ordena vetor dos homens
	ordena(&f,contF);//ordena vetor das mulheres
	/*imprime os casais com preferencia aos mais velhos*/
	for(i = 0; i < casais ; i++)
	{
		printf("%s (%c, %d) e ", m[i].nome , m[i].sexo , m[i].idade);
		printf("%s (%c, %d)\n", f[i].nome , f[i].sexo , f[i].idade);
	}
	system("pause");
	return 0;
}
