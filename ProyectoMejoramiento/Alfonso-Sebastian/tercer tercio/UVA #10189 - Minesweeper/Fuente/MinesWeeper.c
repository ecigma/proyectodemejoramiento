/*
Bibliotecas
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Constantes
*/
#define M 100
#define N 100

/*
Declaracion Subprogramas
*/
void imprimirMatriz(int matrizSalida[M][N],int m, int n);
int casillaEnRiesgo(int i, int j, char matrizEntrada[M][N],int m, int n);
void calcularMatrizDeBombasAdyacentes(int matrizSalida[M][N],char matrizEntrada[M][N],int m,int n);
int main(void){
    //declaracion de variables
    bool seAcabo=false;
    int casos=1;
    int m;
    int n;
    char matrizEtrada[M][N];
    int matrizSalida[M][N];
    //lectura de la entrada
    while(!seAcabo){
        scanf("%i %i",&m,&n);
        if(m==0 && n==0){
            seAcabo=true;
        }
        int i=0;
        int j=0;
        for(i;i<m;i++){
            j=0;
            for(j;j<n;j++){
                scanf("%c",matrizEtrada[i][j]);
            }
        }
        if(!seAcabo){
            calcularMatrizDeBombasAdyacentes(matrizSalida,matrizEtrada,m,n);
            printf("FIELD #%i:\n",casos);
            imprimirMatriz(matrizSalida,m,n);
            casos++;
        }
        }
return 0;
}
/*
Implementacion Subprogramas
*/
/*
------------------------------------------------------------------------------------------------------------------------------------------------
OBJ : Imprimir la matriz resultado
PRE : los limites m, n de la matriz y la matriz a imprimir
POS : impresion
------------------------------------------------------------------------------------------------------------------------------------------------
*/
void imprimirMatriz(int matrizSalida[M][N],int m , int n){
    int i=0;
    int j=0;
    for(i;i<m;i++){
        j=0;
        for(j;j<n;j++){
            if((char)matrizSalida[i][j]=='*'){
                printf("%c",(char)matrizSalida[i][j]);
            }else{
                printf("%i",matrizSalida[i][j]);
            }
        }
        printf("\n");
    }
}
/*
------------------------------------------------------------------------------------------------------------------------------------------------
OBJ : Saber cuantas bombas adyacentes tiene una casilla
PRE : las coordenadas de la casilla, la matriz entrada, los limites de la matriz
POS : Retorna un entero con el numero de bombas adyacentes
------------------------------------------------------------------------------------------------------------------------------------------------
*/
int casillaEnRiesgo(int i, int j, char matrizEntrada[M][N],int m, int n){
    int k=i-1;
    int r;
    int bombasAdyacentes=0;

    for(k;k<=i+1;k++){
        r=j-1;
        for(r;r<=j+1;r++){
            if(k<m && k>=0 && r<n && r>=0){
                if(matrizEntrada[k][r]=='*'){
                    bombasAdyacentes++;

                }
            }
        }
    }
    return bombasAdyacentes;
}
/*
------------------------------------------------------------------------------------------------------------------------------------------------
OBJ : Crear la matriz solucion de bombas adyacentes
PRE : la matriz entrada, la matriz de salida, los limites de las matrices
POS : Retorna un entero con el numero de bombas adyacentes
------------------------------------------------------------------------------------------------------------------------------------------------
*/
void calcularMatrizDeBombasAdyacentes(int matrizSalida[M][N],char matrizEntrada[M][N],int m, int n){
    int i=0;
    int j=0;
    for(i;i<m;i++){
        j=0;
        for(j;j<n;j++){
            if(matrizEntrada[i][j]=='*'){
                matrizSalida[i][j]=matrizEntrada[i][j];
            }else{
                matrizSalida[i][j]=casillaEnRiesgo(i,j,matrizEntrada,m,n);
            }
        }
    }

}
