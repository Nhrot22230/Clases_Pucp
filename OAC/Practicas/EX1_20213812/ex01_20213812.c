#include <stdio.h>
#include <stdlib.h>

extern int binarySearch_ASM(int *arrNums, int numA, int numB, int cant_elem);

int binarySearch(int *arrNums, int numA, int numB, int cant_elem){
    int left = 0, right = cant_elem - 1;
    int med = 0;
    int i = 0, j = 0;
    while(left <= right){
        med = left + (right - left)/2;
        
        if(arrNums[med] == numA){
            i = med;
            break;
        }
        if(arrNums[med] < numA){
            left = med + 1;
        }
        else {
            right = med - 1;
        }
    }

    left = 0;
    right = cant_elem -1;

    while(left <= right){
        med = (left + right)/2;
        if(arrNums[med] == numB){
            j = med;
            break;
        }
        if(arrNums[med] < numB){
            left = med + 1;
        }
        else {
            right = med - 1;
        }
    }

    if(i > j){
        int aux = j;
        j = i;
        i = aux;
    }

    int result = 1;
    for(int index = i; index <=j; index++){
        result *= arrNums[index];
    }

    int suma = 0;
    while(result){
        suma += result%10;
        result /= 10;
    }

    return suma;
}

int main(int argc, char const *argv[])
{
    int cant_elem;
    printf("Ingrese elementos del arreglo: ");
    scanf("%d", &cant_elem);
    int arrNumeros[cant_elem];
    int num;
    for(int i=0; i<cant_elem; i++){
        scanf("%d", &num);
        arrNumeros[i] = num;
    }
    

    int numA = 0, numB = 0;
    printf("Ingrese los términos a buscar: ");
    scanf("%d%d", &numA, &numB);
    int suma = binarySearch(arrNumeros, numA, numB, cant_elem);
    printf("La suma de digitos en C   es: %d\n", suma);

    suma = binarySearch_ASM(arrNumeros, numA, numB, cant_elem);
    printf("La suma de digitos en ASM es: %d\n", suma);    

    return 0;
}
