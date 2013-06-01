#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main ()
{
        long numero, i, bandera, contador, j, memoria;
        long primos [] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

        while (scanf ("%ld", &numero))
        {

                if (numero == 0){
                        return 0;}

                memoria = numero;
                long cuentaPrimos[25] = {0};
                while (numero != 1)
                {
                        i = numero;
                        j = 0;

                        while (i > 1)
                       {
                                contador = 0;
                                while (i % primos[j] == 0)
                                {
                                        i /= primos[j];
                                        contador++;
                                }
                                cuentaPrimos[j] += contador;
                                j++;
                        }

                        numero--;
                }


                for (i = 24; i >= 0; i--)
                {
                        if (cuentaPrimos[i] != 0)
                                break;
                }
                j = i;

                printf("%3ld! =", memoria);
                if (j >= 15)
                        bandera = 0;
                else
                        bandera = 15;
                for (i = 0; i <= j; i++)
                {
                        printf("%3ld", cuentaPrimos[i]);
                        bandera++;
                        if (bandera == 15)
                                printf("\n%6c",' ');
                }
                printf("\n");
        }
        return 0;
}
