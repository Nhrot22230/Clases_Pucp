#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float varianza_c(float* arr, int N);
extern float varianza_asm(float* arr, int N);

int main(){
    int N = 5;
    float arreglo[5] = {4.1, 2.2, 3.3, 2.7, 1.1};
    float varianza;

    varianza = varianza_c(arreglo, N);
   
    printf("La varianza en c es:\t %.4f\n", varianza);
    varianza = varianza_asm(arreglo, N);
    printf("La varianza en asm es:\t %.4f\n", varianza);
    return 0;
}

float varianza_c(float* arr, int N){
    int i, j;
    float suma, media, var;
    suma = 0.0;
    for(i=0;i<N;i++){
        suma+=arr[i];
    }
    media = suma/N;
    printf("La media es:\t %.4f\n", media);
    suma = 0.0;
    for(j=0;j<N;j++){
        suma+=((arr[j]-media)*(arr[j]-media));
    }
    var = suma/N;
    return var;
}