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
        s[MAX],//quantidade de "traços"
        tam[MAX],//variável que recebe o tamanho da string n
        a[MAX][9];//capacidade de 8 dígitos
    char n[MAX][9];//capacidade de 8 caracteres
    //o bloco abaixo é o input do programa (entrada das variáveis s e n)
    do
    {
        scanf ("%d %s", &s[i], n[i]);
        //tratamento de erros (valores não aceitos)
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
                a[j][k] = n[j][k] - '0';/*matriz a recebe a posição na tabela ascii do número
                que está no vetor n menos a posição do número 0 na tabela ascii. O 
                resultado sempre será o número do vetor n, mas agora ele virou int
                ao invés de char*/
            }
        }
        //as linhas abaixo são o output do programa
        for (j = 0; j < i; j++)//vai da primeira à última linha da matriz a
        {
            for (k = 0; k < ((2 * s[j]) + 3); k++)/*esse loop será realizado 2s + 3 
            vezes, que é a quantidade de linhas que vai ter*/
            {
                for (l = 0; l < tam[j]; l++)//percorre a linha da matriz a, elemento a elemento
                {
                    if (a[j][l] == 0)//desenho para o número 0
                    {
                        if (k == 0 || k == ((2 * s[j]) + 2))
                        //primeira ou última linha
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//não é a primeira nem a última linha
                        {
                            if (k == (s[j] + 1))//linha do meio
                            {
                                printf (" ");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf (" ");
                                }
                                printf ("  ");//garante um espaço entre dois números
                            }
                            else
                            //não é a primeira, nem a última nem a linha do meio
                            {
                                printf ("|");
                                for (m = 0; m < s[j]; m++)/*garante que a quantidade
                                de espaços seja s*/
                                {
                                    printf (" ");
                                }
                                printf ("| ");//garante um espaço entre dois números
                            }
                        }
                    }
                    if (a[j][l] == 1)//desenho para o número 1
                    {
                        if (k == 0 || k == ((2 * s[j]) + 2) || k == (s[j] + 1))
                        //primeira ou última linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf (" ");
                            }
                            printf ("  ");//garante um espaço entre dois números
                        }
                        else//não é a primeira, nem a última e nem a linha do meio
                        {
                            for (m = 0; m < (s[j] + 1); m++)
                            {
                                printf (" ");//garante os espaços antes do traço |
                            }
                            printf ("| ");
                        }          
                    }   
                    if (a[j][l] == 2)//desenho para o número 2
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou última linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//não é a primeira, nem a última e nem a linha do meio
                        {
                            if (k + 1 <= s[j] + 1)
                            //se sim, significa que k está acima da linha do meio
                            {
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espaços antes do traço |
                                }
                                printf ("| ");
                            }
                            else
                            {
                                printf ("|");
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espaços depois do traço |
                                }
                                printf (" ");
                            }
                        }
                    }  
                    if (a[j][l] == 3)//desenho do número 3
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou última linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//não é a primeira, nem a última e nem a linha do meio
                        {
                            for (m = 0; m < (s[j] + 1); m++)
                            {
                                printf (" ");//garante os espaços antes do traço |
                            }
                            printf ("| ");
                        }
                    }
                    if (a[j][l] == 4)//desenho do número 4
                    {
                        if (k == 0 || k == ((2 * s[j]) + 2))//primeira ou última linha
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf (" ");
                            }
                            printf ("  ");
                        }
                        else//não é a primeira nem a última linha
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
                            else//não é a primeira linha, nem a última, nem a linha do meio
                            {
                                if (k + 1 <= s[j] + 1)
                                //se sim, significa que k está acima da linha do meio
                                {
                                    printf ("|");
                                    for (m = 0; m < s[j]; m++)
                                    {
                                        printf (" ");//garante os espaços antes do traço |
                                    }
                                    printf ("| ");
                                }
                                else
                                /*não é a primeira, nem a última, nem a do meio, 
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
                    if (a[j][l] == 5)//desenho do número 5
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou última linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//não é a primeira, nem a última e nem a linha do meio
                        {
                            if (k + 1 <= s[j] + 1)
                            //se sim, significa que k está acima da linha do meio
                            {
                                printf ("|");
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espaços depois do traço |
                                }
                                printf (" ");
                            }
                            else
                            {
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espaços antes do traço |
                                }
                                printf ("| ");
                            }
                        }
                    }
                    if (a[j][l] == 6)//desenho do número 6
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou última linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//não é a primeira, nem a última e nem a linha do meio
                        {
                            if (k + 1 <= s[j] + 1)
                            //se sim, significa que k está acima da linha do meio
                            {
                                printf ("|");
                                for (m = 0; m < (s[j] + 1); m++)
                                {
                                    printf (" ");//garante os espaços depois do traço |
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
                                printf (" ");//garante um espaço entre dois números
                            }
                        }
                    }
                    if (a[j][l] == 7)//desenho do número 7
                    {
                        if (k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //última linha ou linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf (" ");
                            }
                            printf ("  ");
                        }
                        else//não é a última nem a linha do meio
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
                            //linha abaixo ou acima da do meio, sem ser a última ou a primeira
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
                    if (a[j][l] == 8)//desenho para o número 8
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou última linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//não é a primeira, nem a última, e nem a linha do meio
                        {
                            printf ("|");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf (" ");
                            }
                            printf ("| ");
                        }
                    }
                    if (a[j][l] == 9)//desenho para o número 9
                    {
                        if (k == 0 || k == (s[j] + 1) || k == ((2 * s[j]) + 2))
                        //primeira ou última linha, ou a linha do meio
                        {
                            printf (" ");
                            for (m = 0; m < s[j]; m++)
                            {
                                printf ("-");
                            }
                            printf ("  ");
                        }
                        else//não é a primeira, nem a última, e nem a linha do meio
                        {
                            if (k + 1 <= s[j] + 1)
                            //se sim, significa que k está acima da linha do meio
                            {
                                printf ("|");
                                for (m = 0; m < s[j]; m++)
                                {
                                    printf (" ");//garante os espaços entre os traços |
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
        
        
