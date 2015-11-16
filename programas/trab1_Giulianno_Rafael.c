#include <stdio.h>
#include <string.h>
#define MAX 100

int main ()
{
    int i=0,//contador
        j=0,//contador
        k=0,//contador
        l=0,//contador
        m=0,//contador e auxiliar
        s[MAX],//quantidade de "tra�os"
        tam[MAX],//vari�vel que recebe o tamanho da string n
        a[MAX][9];//capacidade de 8 d�gitos
    char n[MAX][9];//capacidade de 8 caracteres
    //o bloco abaixo � o input do programa (entrada das vari�veis s e n)
    do
    {
        scanf ("%d %s", &s[i], n[i]);
        //tratamento de erros (valores n�o aceitos)
        //n[i] < 0
        m = strcmp("0", n[i]);
        while ((s[i] < 1 || s[i] > 10) && (s[i] != 0 || m != 0))
        //caso s[i] < 1 ou caso s[i] > 10
        {
            scanf ("%d", &s[i]);
        }
        while (strlen(n[i]) >= 9)
        //caso n[i] > 99 999 999
        {
            scanf ("%s", n[i]);
        }
        i++;
    }while (s[i - 1] != 0 || m != 0);
    i--;
    if (i != 0)// se i = 0, significa que logo na primeira entrada houve 0 0
    {
        for (j = 0; j < i; j++)
        //estes dois loops servem apenas para alimentar a matriz 'a' e o vetor 'tam'
        {
            tam[j] = strlen(n[j]);
            for (k = 0; k < tam[j]; k++)
            {
                a[j][k] = n[j][k] - '0';/*matriz a recebe a posi��o na tabela ascii do n�mero
                que est� no vetor n menos a posi��o do n�mero 0 na tabela ascii. O 
                resultado sempre ser� o n�mero do vetor n, mas agora ele virou int
                ao inv�s de char*/
            }
        }
        //as linhas abaixo s�o o output do programa
        for (j = 0; j < i; j++)//vai da primeira � �ltima linha da matriz a
        {
            for (k = 0; k < ((2 * s[j]) + 3); k++)/*esse loop ser� realizado 2s + 3 
            vezes, que � a quantidade de linhas que vai ter*/
            {
                for (l = 0; l < tam[j]; l++)//percorre a linha da matriz a, elemento a elemento
                {
                    if (a[j][l] == 0)//desenho para o n�mero 0
                    {
                        if (k == 0 || k == ((2 * s[j]) + 2))
                        //primeira ou �ltima linha
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//n�o � a primeira nem a �ltima linha
                        {
                            if (k == (s[j] + 1))//linha do meio
                            {
                                printf (" ");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf (" ");
                                }
                                printf ("  ");//garante um espa�o entre dois n�meros
                            }
                            else
                            //n�o � a primeira, nem a �ltima nem a linha do meio
                            {
                                printf ("|");
                                for (m = 0; m < s[j]; m++)/*garante que a quantidade
                                de espa�os seja s*/
                                {
                                    printf (" ");
                                }
                                printf ("| ");//garante um espa�o entre dois n�meros
                            }
                        }
                    }
                    if (a[j][l] == 1)//desenho para o n�mero 1
                    {
                        if (k == 0 || k == ((2 * s[j]) + 2) || k == (s[j] + 1))
                        //primeira ou �ltima linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf (" ");
                            }
                            printf ("  ");//garante um espa�o entre dois n�meros
                        }
                        else//n�o � a primeira, nem a �ltima e nem a linha do meio
                        {
                            for (m = 0; m < (s[j] + 1); m++)
                            {
                                printf (" ");//garante os espa�os antes do tra�o |
                            }
                            printf ("| ");
                        }          
                    }   
                    if (a[j][l] == 2)//desenho para o n�mero 2
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou �ltima linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//n�o � a primeira, nem a �ltima e nem a linha do meio
                        {
                            if (k + 1 <= s[j] + 1)
                            //se sim, significa que k est� acima da linha do meio
                            {
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espa�os antes do tra�o |
                                }
                                printf ("| ");
                            }
                            else
                            {
                                printf ("|");
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espa�os depois do tra�o |
                                }
                                printf (" ");
                            }
                        }
                    }  
                    if (a[j][l] == 3)//desenho do n�mero 3
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou �ltima linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//n�o � a primeira, nem a �ltima e nem a linha do meio
                        {
                            for (m = 0; m < (s[j] + 1); m++)
                            {
                                printf (" ");//garante os espa�os antes do tra�o |
                            }
                            printf ("| ");
                        }
                    }
                    if (a[j][l] == 4)//desenho do n�mero 4
                    {
                        if (k == 0 || k == ((2 * s[j]) + 2))//primeira ou �ltima linha
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf (" ");
                            }
                            printf ("  ");
                        }
                        else//n�o � a primeira nem a �ltima linha
                        {
                            if (k == (s[j] + 1))//linha do meio
                            {
                                printf (" ");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf ("-");
                                }
                                printf ("  ");
                            }
                            else//n�o � a primeira linha, nem a �ltima, nem a linha do meio
                            {
                                if (k + 1 <= s[j] + 1)
                                //se sim, significa que k est� acima da linha do meio
                                {
                                    printf ("|");
                                    for (m = 0; m < s[j]; m++)
                                    {
                                        printf (" ");//garante os espa�os antes do tra�o |
                                    }
                                    printf ("| ");
                                }
                                else
                                /*n�o � a primeira, nem a �ltima, nem a do meio, 
                                nem acima da linha do meio. Ou seja, abaixo da do meio*/
                                {
                                    printf (" ");
                                    for (m = 0; m < s[j]; m++)
                                    {
                                        printf (" ");
                                    }
                                    printf ("| ");  
                                }
                            }
                        } 
                    }
                    if (a[j][l] == 5)//desenho do n�mero 5
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou �ltima linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//n�o � a primeira, nem a �ltima e nem a linha do meio
                        {
                            if (k + 1 <= s[j] + 1)
                            //se sim, significa que k est� acima da linha do meio
                            {
                                printf ("|");
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espa�os depois do tra�o |
                                }
                                printf (" ");
                            }
                            else
                            {
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espa�os antes do tra�o |
                                }
                                printf ("| ");
                            }
                        }
                    }
                    if (a[j][l] == 6)//desenho do n�mero 6
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou �ltima linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//n�o � a primeira, nem a �ltima e nem a linha do meio
                        {
                            if (k + 1 <= s[j] + 1)
                            //se sim, significa que k est� acima da linha do meio
                            {
                                printf ("|");
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espa�os depois do tra�o |
                                }
                                printf (" ");
                            }
                            else//linha abaixo da do meio
                            {
                                printf ("|");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf (" ");
                                }
                                printf ("|");
                                printf (" ");//garante um espa�o entre dois n�meros
                            }
                        }
                    }
                    if (a[j][l] == 7)//desenho do n�mero 7
                    {
                        if (k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //�ltima linha ou linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf (" ");
                            }
                            printf ("  ");
                        }
                        else//n�o � a �ltima nem a linha do meio
                        {
                            if (k == 0)//primeira linha
                            {
                                printf (" ");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf ("-");
                                }
                                printf ("  ");
                            }
                            else
                            //linha abaixo ou acima da do meio, sem ser a �ltima ou a primeira
                            {
                                printf (" ");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf (" ");
                                }
                                printf ("| ");
                            }
                        }
                    }
                    if (a[j][l] == 8)//desenho para o n�mero 8
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou �ltima linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//n�o � a primeira, nem a �ltima, e nem a linha do meio
                        {
                            printf ("|");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf (" ");
                            }
                            printf ("| ");
                        }
                    }
                    if (a[j][l] == 9)//desenho para o n�mero 9
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou �ltima linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//n�o � a primeira, nem a �ltima, e nem a linha do meio
                        {
                            if (k + 1 <= s[j] + 1)
                            //se sim, significa que k est� acima da linha do meio
                            {
                                printf ("|");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf (" ");//garante os espa�os entre os tra�os |
                                }
                                printf ("| ");
                            }
                            else//linha abaixo da do meio
                            {
                                printf (" ");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf (" ");
                                }
                                printf ("| ");
                            }
                        }
                    }
                }   
                printf ("\n");
            }
        }
    }
    system ("pause>nul");
}
        
        
