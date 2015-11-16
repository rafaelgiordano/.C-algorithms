//GIULIANNO RAPHAEL SBRUGNERA RA: 408093
//RAFAEL PASCHOAL GIORDANO RA: 408298
#include <stdio.h>

int main ()
{
 	int m[7][6],//matriz utilizada
 		x, //contador
		i,//contador
		j,//contador
		cont,//contador
		a,//variável de controle
		p;//posição que vai colocar a ficha	
    for (x=1;x<=6;x++){
		printf("#%d\t",x);}
		printf("\n\n");
	for (i = 0; i < 7; i++)
    {
	 	for (j = 0; j < 6; j++)
	 	{
		 	m[i][j] = 0;
 			printf ("%d\t", m[i][j]);
		}
		printf ("\n\n");
    }
    do
    {
		a = 0; 
		cont = 0;
	  	printf ("digite a coluna: ");
	  	scanf ("%d", &p);
	  	while (p < 1 || p > 6)
	  	{
		 	  printf ("coluna inexistente. digite um numero de 1 a 6: ");
		 	  scanf ("%d", &p);
        }
        for (x=1;x<=6;x++){
		printf("#%d\t",x);}
		printf("\n\n");
        for (i = 7; i>= 0; i--)
        {
		 	if (m[i][p -1] == 0)
		 	{
				m[i][p -1] = 1;
				i = -1;
			}
			else
			{
				cont++;
			}
		}
		if (cont == 8)//coluna cheia
		{
			a= -1;
			printf ("coluna cheia. digite outra: \n");
		} 
		else
		{
		for (i = 0; i < 7; i++)
    	{
	 		for (j = 0; j < 6; j++)
	 		{
 				printf ("%d\t", m[i][j]);
 				if (m[i][j] == 0)//tem pelo menos um espaço ainda
 				{
					a = -1;
				}
			}
			printf ("\n\n");
    	}
		}
	}while (a == -1);
	/*for (i = 0; i < 7; i++)
    {
	 	for (j = 0; j < 6; j++)
	 	{
 			printf ("%d\t", m[i][j]);
		}
		printf ("\n\n");
    }*/
    system ("pause");
	return 0;
}
			
 		
