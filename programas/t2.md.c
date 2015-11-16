// Rafael Paschoal Giordano - RA:408298

#include <stdio.h>

int mdc(int x , int y);

int main(){
	int x[100], y[100],i=0,cont;
	scanf("%d %d", &x[i], &y[i]);

	while(x[i]!=0 && y[i]!=0)
	{
			i++;
	scanf("%d %d", &x[i], &y[i]);//leitura nao importa ordem 

	}
	cont=i;
	for(i=0;i<cont;i++)
	{
	printf("%d", mdc(x[i],y[i]));
	if (i != cont-1)
	{
		printf("\n");
	}
	}
	system("pause");
	return 0;
}

int mdc (int x, int y){
	if ((y<=x) && (x % y ==0)){
 	   return y;
	   } else{
 	   	 if (x < y) {
		 	  return mdc(y,x);
			  }
		  else {
	   	   return mdc(y,(x%y));;
			 }
		  }
		  }
		  
