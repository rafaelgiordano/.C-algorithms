#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//SOLUÇÃO 1
/*Nesta solução, temos como prioridade o objeto com maior preço. 
Portanto, o vetor de preços é ordenado, de maneira decrescente (consequentemente
ordena-se o vetor de pesos também), e em seguida é conferido se ele pode entrar 
na mochila, de acordo com o seu peso e a capacidade da mesma. 
Se sim, ele entra na mochila, e ela tem seu peso restante diminuido. 
Caso contrário, nada é feito.
Em seguida, passa-se para o próximo elemento do vetor.
Isso é feito sucessivamente, até acabar o vetor ou o peso restante da mochila
chegar a zero.*/
int main ()
{
    int W, n, v[MAX], w[MAX], i, j, aux;
    printf ("Digite a capacidade de peso, em quilos, da mochila: ");
    scanf ("%d", &W);
    printf ("Digite a quantidade de objetos disponiveis: ");
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf ("\nDigite o peso do objeto [%d]: ", i);
        scanf ("%d", &w[i]);
        printf ("Digite o preco do objeto [%d]: ", i);
        scanf ("%d", &v[i]);
    }
    printf ("\nPesos: ");
    for (i = 0; i < n; i++)
    {
        printf ("%d ", w[i]);
    }
    printf ("\nPrecos: ");
    for (i = 0; i < n; i++)
    {
        printf ("%d ", v[i]);
    }
    for (i = 0; i < n; i++)//ordenar os dois vetores na ordem decrescente
    {
        for (j = 0; j < n - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                aux = v[j + 1];
                v[j + 1] = v[j];
                v[j] = aux;
                aux = w[j + 1];
                w[j + 1] = w[j];
                w[j] = aux;
            }
        }
    }
    i = 0;
    do
    {
        if (w[i]<= W)
        {
            W = W - w[i];
            printf ("\n\nObjeto na mochila\nPeso: %d\nPreco: %d", w[i], v[i]);
        }
        i = i + 1;
    }while (i < n && W != 0);
    system ("pause>nul");
}
                
            
