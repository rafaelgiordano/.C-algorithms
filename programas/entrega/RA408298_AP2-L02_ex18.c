// RA408298_AP2-L02_ex18
// Rafael Paschoal Giordano

#include <stdio.h>

int mdc(int x , int y);

int main(){
	int x1, y1;
	scanf("%d %d", &x1, &y1);//leitura nao importa ordem 
	printf("%d\n", mdc(x1,y1));

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
		  }}
		  
