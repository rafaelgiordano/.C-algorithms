/* -------------------------------------------------------------------
   Algoritmos e Programacao II
   */

#include <stdio.h>
#include <math.h>

typedef struct consumo
{
    int qtddMorador;//quantidade de moradores na casa
    int consumo;//consumo da casa
    int consumoPessoa;//consumo das pessoas em cada residencia ADICIONADO POR MIM
}Consumo;

typedef struct cidade
{
    int idCidade;//contador que printa o numero da casa, sempre aumentando
    Consumo imoveis[1000];//vetor que em cada posicao possui qtddMorador e consumo
    double consumoMedio;//como faz parte só do struct Cidade, só pode entao ser o Consumo Medio (terceira linha da saída)
}Cidade;
//o que nao tem nos struct que precisa na main:
//variavel VETOR para calcular o consumo das pessoas em cada residencia 
//(segundo número da segunda linha da saída - tipo float arredondado para baixo)
//precisa ser vetor pois precisa ordenar de forma crescente para imprimir na tela
int main ()
{
    Cidade f;
    Consumo aux;
    int n = 0,//quantidade de imoveis
        i = 0,//contador
        j = 0,//contador
        cont = 0,//contador
        iguais;//flag
    float auxf,			//auxiliar
		  somaMorador = 0,//soma a quantidade de moradores de uma cidade
          somaConsumo = 0;//soma a quantidade de consumo de uma cidade
    f.idCidade = 0;//inicialização de variável
    do
    {
        scanf ("%d", &n);
        if (n != 0)
        {
            somaMorador = 0;
            somaConsumo = 0;
            f.idCidade++;//indicador da cidade
            for (i = 0; i < n; i++)
            {
                scanf ("%d %d", &f.imoveis[i].qtddMorador, &f.imoveis[i].consumo);
                f.imoveis[i].consumoPessoa = f.imoveis[i].consumo / f.imoveis[i].qtddMorador;
                somaMorador = somaMorador + f.imoveis[i].qtddMorador;
                somaConsumo = somaConsumo + f.imoveis[i].consumo;
            }
            f.consumoMedio = somaConsumo / somaMorador;
            for (i = 0; i < n; i++)//bloco que ordena as coisas
            {
                for (j = 0; j < n - 1; j++)
                {
                    if (f.imoveis[j].consumoPessoa > f.imoveis[j + 1].consumoPessoa)
                    {
                        aux = f.imoveis[j];
                        f.imoveis[j] = f.imoveis[j + 1];
                        f.imoveis[j + 1] = aux;
                    }
                }
            }
            
            /* bloco que sera realizado sempre que houver imoveis com consumo por pessoa iguais */
            do
            {
				iguais = 999;
				for (i = 0; i < n - 1; i++)
				{
					if (f.imoveis[i].consumoPessoa == f.imoveis[i + 1].consumoPessoa)
					{
						f.imoveis[i].qtddMorador = f.imoveis[i].qtddMorador + f.imoveis[i + 1].qtddMorador;
						f.imoveis[i + 1].consumoPessoa = -999;//flag para nao imprimir depois
						iguais = 1;//mostra que houve igualdade
					}
				}
			}while (iguais == 1);
			
            printf ("\nCidade# %d:\n", f.idCidade);        
            
			/* saida do programa */
			for (i = 0; i < n; i++)
            {
				if (f.imoveis[i].consumoPessoa != -999)
				{
                	printf ("%d-%d ", f.imoveis[i].qtddMorador, f.imoveis[i].consumoPessoa);//print qtde moradores e consumo por pessoa
				}
			}
			/*cria uma variavel float
			dai essa variavel recebe o 
			consumo medio / 0.01
			dai dps c faz ki o 
			consumo medio = (int)aux * 0.01
			explicando
			o numero eh 13.286546
			divide por 0.01 dah
			1328.6546 certo
			dai esse cast pra int pega soh a parte inteira do numero
			no caso 1328
			dai multiplica por 0.01
			dah 13.28*/
			auxf = f.consumoMedio / 0.01;
			f.consumoMedio = (int)auxf * 0.01;
            printf ("\nConsumo medio: %.2f m3.\n\n", f.consumoMedio);
        }
    }while (n != 0);
    return 0;
}
