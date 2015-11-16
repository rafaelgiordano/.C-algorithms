// RA408298_AP2-L02_ex11
// Rafael Paschoal Giordano

#include <stdio.h>

int bin(int num);

int main() {
	int n;
	scanf("%d",&n);
	bin(n);

	return 0;
}
int bin(int num){
	int r;
	if (num==0){
	   return 0;
	   }else{
	   r= num%2;
 		 bin(num/2);
 		 printf("%d", r);
		 }
		 return 0;
		 }
