// RA408298_AP2-L02_ex03
// Rafael Paschoal Giordano

#include <stdio.h>

int fat(int n){
	if (n==0) {
	   		return 1;
			   }
	   		else{
 			return n * fat(n-1);
			}
			}
	int main() {
		int n;
		scanf ("%d", &n);
		printf("\n%d\n",fat(n));

		return 0;
		}
