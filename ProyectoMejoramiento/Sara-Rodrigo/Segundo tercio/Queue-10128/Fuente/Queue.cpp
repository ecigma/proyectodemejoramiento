/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include <iostream>
using namespace std;
/*==============================================================================
Variables
==============================================================================*/
typedef long long int64;
int64 d[17][17][17];

/*==============================================================================
Definici�n de Metodos
==============================================================================*/
void candidatos ();
/*==============================================================================
Metodo principal
==============================================================================*/
int main () {
    candidatos ();
    int T, n, p, r;
    cin >> T;
    
    while ( T-- ) {
        cin >> n >> p >> r;
        cout << d[n][p][r] << endl;
    }
    return 0;
}
/*
Encuentra todos los posibles condidatos a soluci�n para todas las combinaciones
*/
void candidatos () {
    d[1][1][1] = 1;
    for ( int i = 2; i <= 13; i++ )//Realizan permutacion
        for ( int j = 1; j <= i; j++ )//Realizan permutacion
            for ( int k = 1; k <= i; k++ ){//Realizan permutacion
                d[i][j][k] = d[i-1][j][k] * ( i - 2 ) + d[i-1][j-1][k] + d[i-1][j][k-1];//Ecuaci�n que obtiene el numero de configuraciones
            }
}


