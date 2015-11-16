// RA408298_AP2-L02_ex17
// Rafael Paschoal Giordano

#include <stdio.h>

long int acker(int m , int n){
	if (m==0){
 	return n +1;}
 	else {
		 if ((m>0) && (n==0)){
		 return acker(m-1,1);}
		 else{if ((m>0) && (n>0)){
		 		 return acker(m-1,acker(m,n-1));}
				 }
				 }
				 }
 int main(){
 	 
 	 int m1 , n2;
 	 scanf ("%d %d", &m1 , &n2);
 	 printf("%d\n",acker(m1,n2));

 	 return 0;
	 }
	 
