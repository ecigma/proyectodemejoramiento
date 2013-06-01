#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define largo unsigned long long

largo divisores(int a){
      int sum=0;  
      int j; 
      for(j=1;j<=a/2;j++)
        {
        if(a%j==0)
        sum=sum+j;
        }
         
         return (largo)(sum);
      } 

int main (){
    unsigned long long a;
    
   
    int i=0;
    int j=0;  
    largo vec[1001];
     while(scanf("%lld",&a)!=EOF && a!=0){
             vec[i]=a;
             i++;
             }
         for(j=0;j<i;j++){
            if(j==0){
                    printf("PERFECTION OUTPUT\n");
            } 
            largo divisor=divisores(vec[j]);
            
            if(divisor==vec[j]){
              printf("%5lld  PERFECT\n",vec[j]);                   
            }else if(divisor<vec[j]){
                  printf("%5lld  DEFICIENT\n",vec[j]);   
            }else if(divisor>vec[j]){
                  printf("%5lld  ABUNDANT\n",vec[j]); 
                  }
            if(j==i-1){
              printf("END OF OUTPUT\n");
            }
         }
     
    return 0;
   
    }
