/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include <iostream>    
#include <string.h>
#include <sstream>
#include <math.h>

using namespace std;

/*==============================================================================
Variables
==============================================================================*/

struct arco{
     int p1, p2;
     float dis;
}arcos[10000];
 
struct peca{
     float x, y;    
}pecas[100];

int padre[100];

/*==============================================================================
Metodos
==============================================================================*/ 

float Kruskal(int numPecas, int pos);
float hallaDistancia(peca p1, peca p2);
void inicializa(int n);
int encuentra(int x);
bool compara(const arco &a, const arco &b);

/*==============================================================================
Metodo principal
==============================================================================*/ 
int main(){
    float total;
    int caso, numPecas, pos;        
    cin>>caso;
    while(caso--){
       cin>>numPecas;
       pos=0;
       for(int i=0; i<numPecas; i++){
            cin>>pecas[i].x>>pecas[i].y;
            for(int j=0; j<i; j++){
                 arcos[pos].p1=i;
                 arcos[pos].p2=j;
                 arcos[pos].dis= hallaDistancia(pecas[i],pecas[j]);
                 pos++;
            }
       }
       total=Kruskal(numPecas, pos);
       cout<<total<<endl;
    }
    
    getchar();
    getchar();
    return 0;
}

/*==============================================================================
Halla la distancia entre las dos pecas
==============================================================================*/ 
float hallaDistancia(peca p1, peca p2){
    return sqrt((pow(p2.x - p1.x, 2)) + (pow(p2.y - p1.y, 2)));
}

/*==============================================================================
ALGORITMO DE KRUSKAL
Tomado de http://jariasf.wordpress.com/2012/04/19/arbol-de-expansion-minima-algoritmo-de-kruskal/
y modificado por Sara Chica Hernández y Rodrigo Gualtero
==============================================================================*/

/*==============================================================================
Kruskal: Kruskal
==============================================================================*/
float Kruskal(int numPecas, int pos){
     float total=0;
     sort(arcos, arcos+pos, compara);

     inicializa(numPecas);
     
     for(int i=0; i<pos; i++){
         int fa = encuentra(arcos[i].p1);
         int fb = encuentra(arcos[i].p2);
         if(fa!=fb){
             padre[fa]=fb;
             total+=arcos[i].dis;
         }
     }
     return total;
}

/*==============================================================================
Kruskal: Método para encontrar la raiz del vértice actual
==============================================================================*/
int encuentra(int x){
     if(x==padre[x])
         return x;
     padre[x]= encuentra(padre[x]); 
     return padre[x];
}

/*==============================================================================
Kruskal: Inicializa el vector padre
==============================================================================*/
void inicializa(int n){
    for (int i=0; i<n; i++) 
        padre[i]=i;
}

/*==============================================================================
Kruskal: Método de comparación
==============================================================================*/
bool compara(const arco &a, const arco &b){
     if(a.dis == b.dis)
         return a.p1 < b.p1;
     return a.dis < b.dis;
}

