#include <stdio.h>


int main()
{
    char str[50];// cadena de entrada
    int maxi,max,i=0; 
    int ch[26]={0};//inicializando Alfabeto

    scanf("%s",&str); // captura de entrada
    // conversion de la cadena al alfabeto de repeticion
    while(str[i]){ 
        int indice=str[i]-'a';
       ch[indice]++;
       i++;
       }
     // suposicion de maximo hechizo
    maxi=0;
    max=ch[maxi];
    // encontrando el maximo Hechizo
    for(i=1;i<26;i++)
    {
        if(ch[i]>max)
        {
            maxi=i;
            max=ch[maxi];
        }
    }
    // Imprimiendo la salida
    printf("%c\n",maxi+'a');
    return 0;
}
