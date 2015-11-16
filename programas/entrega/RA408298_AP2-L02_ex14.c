// RA408298_AP2-L02_ex14
// Rafael Paschoal Giordano

#include <stdio.h>

int f(int n);
int g(int n);

int main(){
	int num;
	scanf("%d", &num);
	printf("\n%d  %d\n", f(num), g(num));
	return 0;
}
int f(int n){
	if (n==1){
 	return 2;
	}
	else{
 		 if(n==2){
		  return 1;}
		  else{
		  	   return 2* f(n-1) + g(n-2);}
			   }}
 int g(int n){
 	 if (n==1){
 	return 1;
	}
	else{
 		 if(n==2){
		  return 2;}
		  else{
		  	   return g(n-1)+(3*f(n-2));}
			   }}
			   
 	 
