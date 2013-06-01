/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include<stdio.h>
#include<list>
#include<vector>
#include <iostream>  
using namespace std;

/*==============================================================================
Variables
==============================================================================*/
int padre[26], visitado[26];
vector< list<int> > grafo(26);
char c1[256], c2[256];//ciudades a explorar
int casos, ciudades, consultas;
/*==============================================================================
Metodos
==============================================================================*/ 
void borrar_grafo();
void inicializar_busqueda();
void BFS(int v);
void camino(int origen, int destino);
/*==============================================================================
Metodo principal
==============================================================================*/ 
int main(){
    int nodo1, nodo2;
    cin>>casos;
	while(casos>0){
        cin>>ciudades>>consultas;                                       
        borrar_grafo();
		for(int i=0; i<ciudades; i++){
			cin>>c1>>c2;
			nodo1 = c1[0] - 'A';
			nodo2 = c2[0] - 'A';
			grafo[nodo1].push_back(nodo2);
            grafo[nodo2].push_back(nodo1);
		}
  		  for(int j=0; j<consultas; j++){
			cin>>c1>>c2;
			nodo1 = c1[0] - 'A';
			nodo2 = c2[0] - 'A';
            inicializar_busqueda();
            BFS(nodo1);//encuentra los caminos a partir de nodo1(origen)
			camino( nodo1, nodo2);
            printf("\n");
		}
		casos--;
		if(casos>0)
			printf("\n");
	}

    return 0;
}
/*==============================================================================
Elimina la información que se encuentra contenida en el grafo
==============================================================================*/
void borrar_grafo(){
int i;
    for(i = 0; i < 26; i++)
       grafo[i].clear();
}
/*==============================================================================
Icicializa por defecto la busqueda
==============================================================================*/
void inicializar_busqueda(){
int i;
    for(i = 0; i < 26; i++){
        padre[i] = -1;
        visitado[i] = 0;
    }
}

/*==============================================================================
ALgoritmo que recorre un grafo por anchura 
==============================================================================*/
void BFS(int v){//recorre el grafo por anchura a partir de v
list<int> cola;//cola de adyacentes
list<int>::iterator aux, fin;//iteradores para recorrer adyacentes del 
                             //nodo actual
int nact;//nodo actual
    visitado[v] = 1;//se marca nodo v como visitado
    cola.push_back(v);//se mete a la cola de adyacentes
    while(!cola.empty()){
       nact = cola.front();//se obtiene primer elemento de la cola
       cola.pop_front();//se elimina dicho elemento
       aux = grafo[nact].begin();//se obtienen iteradores a lista de nodo actual
       fin = grafo[nact].end();
       while(aux != fin){//mientras haya adyacentes al nodo actual
          if(!visitado[*aux]){//se toman los nodos no visitados
             visitado[*aux] = 1;//se marcan como visitados
             padre[*aux] = nact;//se almacena el padre del nodo recien visitado
             cola.push_back(*aux);//se mete dicho nodo a la cola
          }
          aux++;
       }
    }
}
/*==============================================================================
encuentra un camino de la ciudad de origen a la ciudad de destino
==============================================================================*/
void camino(int origen, int destino){
    if(origen == destino){//si se llego al caso base
          char x=origen + 'A';
          cout<<x;
    }else{
        if(padre[destino] == -1){
           cout<<"no existe camino de "<<origen + 'A'<<"a "<<destino + 'A';
        }else{
            camino( origen, padre[destino]);//funcion recursiva
            char y=destino + 'A';
            cout<<y;
        }
    }
}
