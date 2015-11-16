#include <stdio.h>
#include <string.h>
int main() {
char palavra[3][20], aux[20], frase[60];
int i, bolha, lsup;
for (i = 0; i < 3; i++) {
printf("Palavra[%d]: ", i);
gets(palavra[i]);
}
lsup = 2;
while (lsup > 0) {
bolha = 0;
for (i = 0; i < lsup; i++) {
if (stricmp(palavra[i], palavra[i + 1]) >
0)
{
strcpy(aux, palavra[i]);
strcpy(palavra[i], palavra[i + 1]);
strcpy(palavra[i + 1], aux);
bolha = i;
}
}
lsup = bolha;
}
strcpy(frase,"");
for (i = 0; i < 3; i++) {
printf("Palavra[%d]: %s\n", i, palavra[i]);
strcat(frase, palavra[i]);
if(i!=2){
strcat(frase, " ");
}
}
printf("Frase: %s\n",frase);
system("pause");
}
