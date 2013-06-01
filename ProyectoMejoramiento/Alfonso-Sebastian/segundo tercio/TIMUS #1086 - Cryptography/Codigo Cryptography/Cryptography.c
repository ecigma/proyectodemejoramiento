#include <stdlib.h>
#include <stdio.h>

int esPrimo(int primo){
    int es=1;
    int i;
    for(i=2;i<=primo/2 && es;i++){
        if(primo%i==0){
            es=0;
        }
    }
    return es;
}

int main(){
    int casos,numeral,i,j,primo,cuenta;
    int primoEncontrado;
    scanf("%i",&casos);

    while(casos!=0){
        //leer el caso
        scanf("%i",&numeral);
        //encontrar el iesimo primo
        cuenta=0;
        primo=2;
        primoEncontrado=0;
        while(!primoEncontrado){
            if(esPrimo(primo)){
                cuenta++;
            }
            if(cuenta==numeral){
                primoEncontrado=1;
            }else{
                primo++;
            }
        }
        printf("%i\n",primo);
        //disminuir el numero de casos
        casos--;
    }
}
