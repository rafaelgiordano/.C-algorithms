/* --------------------------------------------------------------------
   Algoritmos e Programacao II
   Trabalho 4 - Estiagem
   Descricao: o programa verifica o consumo de cada uma das pessoas da 
   		      cidade e o consumo médio de cada cidade por habitante.
   Entradas.: numero de imoveis na cidade, a quantidade de moradores e
   			  o consumo em cada imovel.
   Saidas...: numero da cidade, numero de pessoas e seu comsumo em cada
   			  imovel e o consumo medio na cidade.
   Autores..: Giulianno Raphael Sbrugnera RA: 408093
			  Rafael Paschoal Giordano RA: 408298
   -------------------------------------------------------------------- */

/* bibliotecas do sistema */
#include <stdio.h>
#include <math.h>

/* registros do programa */
typedef struct consumo
{
    int qtddMorador;
    int consumo;	
    int consumoPessoa;  
}Consumo;

typedef struct cidade
{
    int idCidade;		
    Consumo imoveis[1000];  
    double consumoMedio;
}Cidade;


int main ()
{
    Cidade f;
    Consumo aux;
    int n = 0,//quantidade de imoveis
        i = 0,//contador
        j = 0,//contador
        iguais;//flag
    float auxf,			  //auxiliar
		  somaMorador = 0,//soma a quantidade de moradores de uma cidade
          somaConsumo = 0;//soma a quantidade de consumo de uma cidade
    f.idCidade = 0;       //inicialização de variável
    do
    {
        scanf ("%d", &n);
        if (n != 0)
        {
            somaMorador = 0;
            somaConsumo = 0;
            f.idCidade++;
            
            for (i = 0; i < n; i++)
            {
                scanf ("%d %d", &f.imoveis[i].qtddMorador, &f.imoveis[i].consumo);
                f.imoveis[i].consumoPessoa = f.imoveis[i].consumo / f.imoveis[i].qtddMorador;
                somaMorador = somaMorador + f.imoveis[i].qtddMorador;
                somaConsumo = somaConsumo + f.imoveis[i].consumo;
            }
            
            f.consumoMedio = somaConsumo / somaMorador;
            
			/* Loop que ordena os registros na forma crescente de consumo por pessoa*/
			for (i = 0; i < n; i++)
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
            
            /* --------------------------------------------------------------
			   Loop que sera realizado sempre que houver imoveis com consumo
			   por pessoa iguais
			   Estrategia:
		       1. O programa assume que o consumo por pessoa da posicao i eh 
			   diferente da posicao i + 1.
			   2. Caso eles sejam iguais, somamos na posicao i sua quantidade
			   de pessoas com a quantidade de pessoas da posicao i + 1. A 
			   variavel 'consumoPessoa' da posicao i + 1 recebe -999 para nao
			   ser impressa depois. A variavel 'iguais' recebe 1 para que
			   o loop continue a procurar por igualdade.
			   3. Toda vez que o loop se repete, a variavel 'iguais' recebe
			   999. Se, em nenhum momento, o consumo por pessoa dos imoveis 
			   for igual, ela nao eh mudada, saindo do loop.
			   -------------------------------------------------------------- */
            do
            {
				iguais = 999;
				for (i = 0; i < n - 1; i++)
				{
					if (f.imoveis[i].consumoPessoa == f.imoveis[i + 1].consumoPessoa)
					{
						f.imoveis[i].qtddMorador = f.imoveis[i].qtddMorador + f.imoveis[i + 1].qtddMorador;
						f.imoveis[i + 1].consumoPessoa = -999;
						iguais = 1;
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
			
			/* -------------------------------------------------------------------
			   A variavel auxiliar float 'auxf' recebe consumoMedio / 0.01, que 
			   eh o mesmo que multiplicar por 100. Assim a parte inteira incorpora
			   os dois primeiros numeros decimais. Em seguida a variavel 
			   'consumoMedio' recebe a parte initeira da variavel 'auxf' vezes
			   0.01, que eh o mesmo que dividir por 100.
			   Dessa forma, 'consumoMedio' possui duas casas decimas corretas, 
			   sem arredondamente automatico do %.2f.
			   ------------------------------------------------------------------- */
			auxf = f.consumoMedio / 0.01;
			f.consumoMedio = (int)auxf * 0.01;
            printf ("\nConsumo medio: %.2f m3.\n\n", f.consumoMedio);
        }
    }while (n != 0);
    return 0;
}
