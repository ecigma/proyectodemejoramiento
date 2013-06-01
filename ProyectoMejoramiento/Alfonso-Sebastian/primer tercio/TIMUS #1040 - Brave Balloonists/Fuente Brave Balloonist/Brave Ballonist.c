//Brave-balloonists
#include <stdio.h>
#include <stdlib.h>




int main () {
    long long producto=1;
    int entrada;
    int i;
    int j;
    int numDivisores=1;
    int factores[10000]={0};

    for(i=0;i<10;i++){
        scanf("%i",&entrada);
        j=2;
        while(entrada!=1){
            if(entrada%j==0){
                entrada=entrada/j;
                factores[j]++;
            }else{
                j++;
            }
        }
    }
    for(i=0;i<10000;i++){
        if(factores[i]!=0){
            numDivisores*=(factores[i]+1);
        }
    }

    printf("%i",numDivisores%10);

}
