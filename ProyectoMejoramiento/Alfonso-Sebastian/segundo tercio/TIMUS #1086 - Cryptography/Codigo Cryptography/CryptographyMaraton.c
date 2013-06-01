#include<stdio.h>
#include<math.h>
#define max 500000

int primo[max];
int main(){

    int i,j,n,t,k;
    int cuenta=0;

    primo[0] = 1;
    primo[1] = 1;

    for(i=4; i<=max; i+=2){
        primo[i] = 1;
    }

    for(i=3; i<= sqrt(max*1.)+1; i+=2){
        if(primo[i]==1){
        continue;
        }
        for(j=i*i; j<=max; j+=2*i){
            primo[j] = 1;
        }
    }

    primo[0]=2;
    j=1;
    for(i=3; i<=max; i+=2){
        if(primo[i]==0){
            primo[j] = i;
            j++;
        }
    }

    scanf("%d", &t);
    for(k=0; k<t; k++){
        scanf("%d", &n);
        printf("%d\n", primo[n-1]);
    }

    return 0;
}
