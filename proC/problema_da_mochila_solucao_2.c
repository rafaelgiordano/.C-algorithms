#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//SOLU��O 2
/*Nesta solu��o, temos como prioridade a maior rela��o pre�o por quilo (ou pre�o
de cada quilo) do objeto.
A cada peso e pre�o digitado de um determinado objeto, calcula-se o pre�o do quilo
e esse valor � guardado em um vetor.
Em seguida, esse vetor � ordenado, de maneira decrescente.
Assim, � conferido se ele pode entrar na mochila, de acordo com o seu peso e a 
capacidade da mesma. 
Se sim, ele entra na mochila, e ela tem seu peso restante diminuido. 
Caso contr�rio, nada � feito.
Em seguida, passa-se para o pr�ximo elemento do vetor.
Isso � feito sucessivamente, at� acabar o vetor ou o peso restante da mochila
chegar a zero.*/
int main ()
{
    int i, j;
    float W, n, v[MAX], w[MAX];
    float r[MAX], auxr,aux;
    r[0] = (5/10);
    printf ("\t\t\tR[0]: %3.5f\n\n\n", r[0]);
    printf ("Digite a capacidade de peso, em quilos, da mochila: ");
    scanf ("%f", &W);
    printf ("Digite a quantidade de objetos disponiveis: ");
    scanf ("%f", &n);
    for (i = 0; i < n; i++)
    {
        printf ("\nDigite o peso do objeto [%f]: ", i);
        scanf ("%f", &w[i]);
        printf ("Digite o preco do objeto [%f]: ", i);
        scanf ("%f", &v[i]);
        r[i] = v[i] / w[i];//rela��o pre�o por peso (pre�o de cada quilo, no caso)
    }
    printf ("\nPesos:\t\t\t");
    for (i = 0; i < n; i++)
    {
        printf ("%f ", w[i]);
    }
    printf ("\nPrecos:\t\t\t");
    for (i = 0; i < n; i++)
    {
        printf ("%f ", v[i]);
    }
    printf ("\nValor por quilo:\t");
    for (i = 0; i < n; i++)
    {
        printf ("%.2f ", r[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (r[j] < r[j + 1])
            {
                auxr = r[j + 1];
                r[j + 1] = r[j];
                r[j] = auxr;
                aux = w[i + 1];
                w[i + 1] = w[i];
                w[i] = aux;
                aux = v[i + 1];
                v[i + 1] = v[i];
                v[i] = aux;
            }
        }
    }
    i = 0;
    do
    {
        if (w[i] <= W)
        {
            W = W - w[i];
            printf ("\n\nObjeto na mochila\nPeso: %f\nPreco: %f", w[i], v[i]);
        }
        i = i + 1;
    }while (i < n && W != 0); 
    system ("pause>nul");
}
                
