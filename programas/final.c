//GIULIANNO RAPHAEL SBRUGNERA RA: 408093
//RAFAEL PASCHOAL GIORDANO RA: 408298

#include <stdio.h>
#define MAX 100000

int main ()
{
    int n[MAX],//quantidade de d�gitos do n�mero que o apresentador escreveu na lousa
        d[MAX],//quantidade de d�gitos que devem ser apagados
        a[MAX],
        b[MAX],
        i = 0,//contador
        j = 0,//contador
        k = 0,//contador
        cont_b = 0,//contador
        x = 0,//�ndice do maior d�gito
        y = 0,
        m = 0,
        lim = 0,
        maior = 0;
    char num[MAX];
    //o bloco abaixo � o input do programa
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
        //transforma��o string para inteiro
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
            m = n[j] - d[j];//quantidade de d�gitos necess�ria para o novo n�mero
            do
            //repete at� que a linha esteja completa da matriz b
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
                //n[j] - x � a quantidade de n�meros � direita do d�gito
                //de posi��o x
                //m � a quantidade de d�gitos que resta para o novo n�mero
                {
                    y = x;//limite superior (da pr�xima vez n�o trabalhar� com a posi��o x)
                    x = -1;//come�a novamente do zero
                }
                else
                {
                    lim = x;//limite inferior
                    m--;//diminui a quantidade de d�gitos que falta pro novo n�mero
                    y = n[j];//limite superior
                    b[j][cont_b] = maior;
                    cont_b++;
                }
            }while (cont_b < (n[j] - d[j]));
        }
        //o bloco abaixo � o output do programa
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
