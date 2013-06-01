#include <stdio.h>
#include <stdlib.h>
/*
Definicion de procedimientos
*/
void  TresNMasUno(long long a, long long b,long long * respuesta);
/*================================================================*/
/*================================================================*/
int main(int argc, char* argv[]){
    
    long long a,b,c=1,auxiliar;
    
   while(scanf("%lld %lld",&a,&b)!=EOF){
    
    long long cuenta=0, maximo=0;
    long long ai,bi,i;
    
     ai=a;
     bi=b;
     if(b<a){
             auxiliar=a;
             a=b;
             b=auxiliar;
             }
  
    for( i=a;i<=b;i++){
         
         cuenta=0;
         TresNMasUno(c,i,&cuenta);
         if(cuenta>maximo){
                           maximo=cuenta;
                           }
        
         }
    printf("%lld %lld %lld\n",ai,bi,maximo);
    }
    return 0;
    }
/*================================================================
Objetivo: Encontrar la longitud de la funcion recursiva 3n+1
================================================================*/
 void TresNMasUno(long long a, long long b,long long* respuesta){
     if(b==1 || b==a){
              (*respuesta)+=1;
              
              }
     else if(b % 2 == 1){
             (*respuesta)+=1;
             TresNMasUno(a,3*b+1,respuesta);
          }
     else if (b%2 == 0){
             (*respuesta)+=1;
             TresNMasUno(a,b/2,respuesta);
          }   
      
      
     }
