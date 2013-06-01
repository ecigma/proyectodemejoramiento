#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int resultado;

    scanf("%i",&n);
    if(n>0){
        resultado=(n*(n+1))/2;
    }else{
        n=n*(-1);
        resultado=(((n*(n+1))/2)*(-1))+1;
    }
    printf("%i",resultado);
    return 0;
}
