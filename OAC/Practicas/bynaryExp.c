#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern double limite_asm(int limit);
extern double limite_lineal_asm(int limit);

double limite_logn(int limit){
    double value = (1 + 1.0/limit);
    double res = 1;
    while(limit){
        if (limit & 1)
            res = res * value;
        
        value = value * value;
        limit = limit >> 1;
    }
    return res;
}

double limite_lineal(int limit){
    double value = (1 + 1.0/limit);
    double temp = value;
    while (limit--)
    {
        value = value * temp;
    }
    return value;
}


int main(){
    int limit = 1, power = 30;
    // printf("Ingrese un valor para b talque n = 2^b: ");
    // scanf("%d", &power);
    limit = limit << power;

    srandom(time(NULL));

    struct timespec ti, tf;
    double elapsed_c, elapsed_asm;
    printf("=================== Logaritmica ====================\n");

    clock_gettime(CLOCK_REALTIME, &ti);
    
    printf("El resultado de binaryExp en c es:   %5.12f\n", limite_logn(limit));

    clock_gettime(CLOCK_REALTIME, &tf);
    elapsed_c = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
    printf("el tiempo en nanosegundos que toma la función en C es %lf\n", elapsed_c);

    clock_gettime(CLOCK_REALTIME, &ti);

    printf("El resultado de binaryExp en asm es: %5.12f\n", limite_asm(limit));
    
    clock_gettime(CLOCK_REALTIME, &tf);
    elapsed_asm = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
    printf("el tiempo en nanosegundos que toma la función en ASM es %lf\n", elapsed_asm);

    printf("\nEl SpeedUp Logaritmico es: %5.4f\n", elapsed_c/elapsed_asm);

    printf("====================== Lineal ======================\n");

    clock_gettime(CLOCK_REALTIME, &ti);

    printf("El resultado de linealExp en asm es: %5.12f\n", limite_lineal(limit));
    
    clock_gettime(CLOCK_REALTIME, &tf);
    elapsed_c = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
    printf("el tiempo en nanosegundos que toma la función en C es %lf\n", elapsed_c);

    clock_gettime(CLOCK_REALTIME, &ti);

    printf("El resultado de linealExp en asm es: %5.12f\n", limite_lineal_asm(limit));
    
    clock_gettime(CLOCK_REALTIME, &tf);
    elapsed_asm = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
    printf("el tiempo en nanosegundos que toma la función en ASM es %lf\n", elapsed_asm);

    printf("\nEl SpeedUp Logaritmico es: %5.4f\n", elapsed_c/elapsed_asm);

    return 0;
}