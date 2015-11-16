//GIULIANNO RAPHAEL SBRUGNERA RA: 408093
//RAFAEL PASCHOAL GIORDANO RA: 408298

#include <stdio.h>
#define MAX 100

int main ()
{
    int n[MAX],//quantidade de dígitos do número que o apresentador escreveu na lousa
        d[MAX],//quantidade de dígitos que devem ser apagados
        a[MAX][MAX],
        b[MAX][MAX],
        i = 0,//contador
        j = 0,//contador
        k = 0,//contador
        cont_b = 0,//contador
        x = 0,//índice do maior dígito
        y = 0,
        m = 0,
        lim = 0,
        maior = 0;
    char num[MAX][MAX];
    //o bloco abaixo é o input do programa
    do
    {
        scanf ("%d %d", &n[i], &d[i]);
        if (n[i] != 0 || d[i] != 0)
        {
            scanf ("%s", num[i]);
        }
        i++;
    }while ((n[i - 1] != 0) || (d[i - 1] != 0));
    i--;
    if (i != 0)//se i = 0 significa que logo na primeira entrada houve 0 0
    {
        //transformação string para inteiro
        for (j = 0; j < i; j++)
        {
            for (k = 0; k < n[j]; k++)
            {
                a[j][k] = num[j][k] - '0';
            }
        }
        for (j = 0; j < i; j++)
        //linha por linha
        {
            x = -1;
            y = n[j];
            cont_b = 0;
            m = n[j] - d[j];//quantidade de dígitos necessária para o novo número
            do
            //repete até que a linha esteja completa da matriz b
            {
                maior = 0;
                if (cont_b != 0)
                {
                    x = lim;
                }
                for (k = x + 1; k < y; k++)
                {
                    if (a[j][k] > maior)
                    {
                        maior = a[j][k];
                    	x = k;
                    }
                }
                if ((n[j] - x) < m)
                //n[j] - x é a quantidade de números à direita do dígito
                //de posição x
                //m é a quantidade de dígitos que resta para o novo número
                {
                    y = x;//limite superior (da próxima vez não trabalhará com a posição x)
                    x = -1;//começa novamente do zero
                }
                else
                {
                    lim = x;//limite inferior
                    m--;//diminui a quantidade de dígitos que falta pro novo número
                    y = n[j];//limite superior
                    b[j][cont_b] = maior;
                    cont_b++;
                }
            }while (cont_b < (n[j] - d[j]));
        }
        //o bloco abaixo é o output do programa
        printf ("\n");
        for (j = 0; j < i; j++)
        {
            for (k = 0; k < (n[j] - d[j]); k++)
            {
                printf ("%d", b[j][k]);
            }
            printf ("\n");
        }
    }
    system("pause>nul");
}
