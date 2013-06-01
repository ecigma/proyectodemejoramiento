#include <stdlib.h>
#include <stdio.h>

int valoresInmediatos[100000]={-1};
int valores();
int mayores();

int main(){

    int n;
    int i=0;

    valoresInmediatos[0]=0;
    valoresInmediatos[1]=1;

    scanf("%i",&n);

    while(n!=0){
        for(i=2;i<=n;i++){
            valoresInmediatos[i]=valores(i);
        }
        printf("%i\n",mayores(n));
        scanf("%i",&n);
    }
    return 0;
}
int valores(int n){

    int r=0;

    if(valoresInmediatos[n]!=0 && n!=0){
        r=valoresInmediatos[n];
    }else if(n==0){
        r=0;
    }else if(n==1){
        r=1;
    }else if(n%2==0){
        r=valores(n/2);
        valoresInmediatos[n]=r;
    }else if(n%2==1){
        r=valores(n-1)+valores(n+1);
        valoresInmediatos[n]=r;
    }

    return r;

}
int mayores(int n){

    int i;
    int mayor=valoresInmediatos[0];

    for(i=1;i<=n;i++){
        if(mayor<valoresInmediatos[i]){
            mayor=valoresInmediatos[i];
        }
    }
    return mayor;
}
