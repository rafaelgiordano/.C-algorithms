#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    
    int i , vet[5], cont=0;
    for (i=0;i<5;i++) {
        printf("\nInforme o vetor");
        scanf("%d", &vet[i]);
        if ((vet[i] % 2)== 0) {
               cont++;
                                }           
                              }
        for (i=0;i<5;i++){
            printf("\no vetor %d eh %d", i , vet[i]);
                          }
            printf("\n e o vetor possui %d numeros pares", cont);
               
    system("pause");
}
