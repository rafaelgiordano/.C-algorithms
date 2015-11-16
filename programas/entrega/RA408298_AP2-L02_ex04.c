// RA408298_AP2-L02_ex04
// Rafael Paschoal Giordano

#include <stdio.h>

float pote(float x1, float y1){

	if (y1==0){
	   		   return 1;}
 			   else { 
			   		 if (y1<0){
			   		 return (1 / x1) * (pote (x1, y1+1));
						       }
					 else {
					 	  return x1 * pote(x1 , y1-1);}
						  }
				  }
 int main(){
 	 float x , y;
 	 scanf ("%f %f", &x , &y);
 	 if (y<0) {//apenas para nao colocar pontos no inteiro
 	 printf ("\n%f\n", pote(x, y));
	  }
 	 else {
	 	   	 printf ("\n%.0f\n", pote(x, y));
			 }
 
 	 return 0;
	 }
