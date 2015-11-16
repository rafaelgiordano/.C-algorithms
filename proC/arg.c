#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int i;
    char nome[20];
    printf ("informe o nome: \n");
    gets(nome);
    for (i=0;i<20;i = i+2) {
        printf ("  %c", nome[i]);
        }
        system("pause");
        }
        
    
