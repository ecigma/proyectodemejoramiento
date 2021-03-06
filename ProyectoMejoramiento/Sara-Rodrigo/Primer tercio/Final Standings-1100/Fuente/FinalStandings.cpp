/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include <iostream>  
#include <algorithm>  
using namespace std;  

/*==============================================================================
Variables
==============================================================================*/  
struct node{  
    int id;  
    int m;  
}vector[10000000 + 10];  


/*==============================================================================
Definición de Metodos
==============================================================================*/
bool mayor(node a, node b);  

/*==============================================================================
Metodo principal
==============================================================================*/
int main(){  
    int n, i;  
    cin>>n;  
    for (i=0; i<n; i++)  
        cin>>vector[i].id>>vector[i].m;  
    stable_sort(vector, vector+n, mayor);  
    for (i=0; i<n; i++)  
        cout<<vector[i].id<<" "<<vector[i].m<<endl;  
}  

/*==============================================================================
mayor
metodo que determina cual es el mayor m para empezar la organizacion
==============================================================================*/  
bool mayor(node a, node b){  
    return a.m > b.m;  
}  
  
