//Rafael Paschoal Giordano RA:408298
//trab4-RafaelGiordano.c

#include <stdio.h>

// insere n elementos lidos no vetor
void le_vet(int v[], int n);

// insere o elemento elem no inicio do vetor e retorna o numero de elementos apos a insercao
int insere_inicio(int v[], int elem, int n,int pos);

// insere o elemento elem no fim do vetor e retorna o numero de elementos apos a insercao
int insere_fim(int v[], int elem, int n);

// insere o elemento elem no meio do vetor e retorna o numero de elementos apos a insercao
int insere_meio(int v[], int elem, int n);

// remove o elemento que esta na posicao pos no vetor e retorna 1 se a remocao foi realizada com sucesso ou 0 caso contrario
int remove_pos(int v[], int pos, int n);

// imprime todos os elementos do vetor
void imprime_vetor(int v[], int n);

int main()
{
	int vet10[10],vet5[5],//vetores para o de 10 e 5 posiçoes
	num ,//numero de posiçoes do vetor que pode ser escolhido pelo usuario
	quant , //quantidade de posiçoes do vetor principal
	vet[1000],//vetor principal
	i,aux; // contadores e auxiliar
	
	scanf("%d", &quant);//entrada da quantidade de posições do vetor 
	le_vet(vet,quant);//chamada da funçao que le o vetor nao pre defenido
	le_vet(vet10,10);//chamada para leiturapro vetor de 10 posiçoes
	le_vet(vet5,5);//chamada para leitura do vetor de 5 posiçoes
	scanf("%d", &num);//numero que sera adicionado ao meio do vetor
	aux=9;//auxilia na inversao do vetor de 10 posiçoes
	/*loop que insere o vetor inicio no vetor principal*/
	for(i = 0; i < 10 ; i++)
	{
	quant = insere_inicio(vet,vet10[aux],quant,i);	//chamada da funçao que adiciona no começo o vetor de 10 no vetor principal
	aux--;//decrementa o valor do aux
	}
	/*loop que insere o vetor fim no vetor principal*/
	for(i = 0; i < 5 ; i++)
	{
	quant = insere_fim(vet,vet5[i],quant);//chamada da funçao que adiciona o valor no fim do vetor principal
	}
	quant = insere_meio(vet, num, quant);//chamada da funçao que adiciona um valor lido no meio do vetor
	aux=0;//zera contador para ajudar a apagar os numeros
	for(i = 0; i < quant; i++)
	{
		aux++;//incrementa ao passar os valores
		if(aux % 10 == 0)//se for multiplo da posiçao 10 ele chama a funçao
		{
		quant = remove_pos(vet,i,quant);//chamada da funçao que apaga as posiçoes desejadas e diminui 1 na quantidade de valores no vetor
		aux=0;
		}		
	}

	imprime_vetor(vet,quant);//chamada da funçao imprime
	
return 0;
	
}
//funçao que  le os valores do vetor
void le_vet(int v[], int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&v[i]);
	}	
}
//funcao que insere o vetor de 10 no inicio do principal e retorna quantidade de valores do vetor principal
//estrategia: passa vetor por vetor para a posiçao + 1 ate a posiçao informada na funçao
int insere_inicio(int v[], int elem, int n,int pos)
{
	int i,aux;
	for(i = n; i > pos ; i--)
	{
		v[i] = v[i-1];
	}
	v[pos]=elem;	
	return n + 1;
	
}
//funcao que insere o valor no fim do vetor principal e retorna quantidade de valores do vetor principal
int insere_fim(int v[], int elem, int n)
{
	v[n] = elem;
	return n+1;
	
}
//funcao que insere o valor no meio, 
//estrategia: divide a quantidade por 2 e a posiçao dessa conta inteira eh a posicao do valor 
//e retorna quantidade de valores do vetor principal
int insere_meio(int v[], int elem, int n)
{
	int i,aux;
	aux = n / 2;
	for(i = n; i > aux ; i--)
	{
		v[i]=v[i-1];
	}	
	v[aux]=elem;
	return n + 1;
}
//funcao que remove os valores das posiçoes multiplas de 10 e retorna quantidade de valores do vetor principal
//estrageia a partir da posicao a ser removida os valores sao deslocados para uma anterior
int remove_pos(int v[], int pos, int n)
{
	int i;
	for(i = pos; i < n ; i++)
	{
		v[i]=v[i+1];
	}
	return n-1;
}
//funcao que imprime o vetor principal apos modificaçoes
void imprime_vetor(int v[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",v[i]);
		if(i != n-1)
		{
			printf(" ");
		}
	}
}
