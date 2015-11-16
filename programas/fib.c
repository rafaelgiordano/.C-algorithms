#include <stdio.h>

int main() {
	int n,fib=0,a=1,b=1,i;
	scanf("%d", &n);
	if(n==1){
		printf("0\n");}
		else{
			if(n==2||n==3){
			printf("1\n");}
			else{
				for(i=3;i<n;i++){
				fib=a+b;
				a=b;
				b=fib;	
				}
				printf("%d\n",fib);}
			}	
	system("pause");
	return 0;
}
