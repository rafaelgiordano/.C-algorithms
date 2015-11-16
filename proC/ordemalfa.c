#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    int i , j ;
    char nome[3][10], aux[10];
    for (i=0;i<3;i++){
        printf("\ninforme a palavra: ");
        gets(nome[i]);
        }
    for (i=0;i<3;i++){
        for(j=0;j<i;j++){
        if (strcmp(nome[j], nome[j+1]) > 0)
        {
           strcpy(aux,nome[j]);
           strcpy(nome[j],nome[j+1]);
           strcpy(nome[j+1],aux);
           }
           }
           }
    for (i=0;i<3;i++){

        printf("os nomes sao %s \n", nome[i]);
        }
        
        system("pause");
        return 0;
        }
