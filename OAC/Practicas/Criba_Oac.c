#include <stdlib.h>
#include <stdio.h>


void criba_dibujito(int *arrPrimos, int *arreglo_faltantes, int n, int x){
    for(int i=0; i<n; i++){
        arrPrimos[i] = i<(x-2);
        arreglo_faltantes[i] = 0;
    }

    for(int i=2; i*i<x-2; i++){
        if(arrPrimos[i-2]){
            for(int j=i*i; j<x; j+=i){
                arrPrimos[j-2] = 0;
            }
        }
    }

    for(int i=0; i<x-2; i++){
        if(arrPrimos[i]) arreglo_faltantes[i] = 0;
        else{
            arreglo_faltantes[i] = 0;
            for(int j=i; j<x; j++){
                if(arrPrimos[j]){
                    arreglo_faltantes[i] = j - i;
                    break;
                }
            }
        }
    }
}

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    printf("N = %d\nX = %d\n", n, x);

    int arreglo_primos[n+1], arreglo_faltantes[n+1];

    criba_dibujito(arreglo_primos, arreglo_faltantes, n, x);

    for(int i=0; i<n-1; i++){
        printf("%d\t", i + 2);
    }
    printf("\n");

    for(int i=0; i<n-1; i++){
        printf("%d\t", arreglo_primos[i]);
    }
    printf("\n");
    for(int i=0; i<n-1; i++){
        printf("%d\t", arreglo_faltantes[i]);
    }
    printf("\n");
    return 0;
}