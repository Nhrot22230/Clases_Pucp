#include <bits/stdc++.h>

using namespace std;

int intCmpAscendente(const void *a, const void *b){
    int *a1, *b1;
    a1 = (int *)a;
    b1 = (int *)b;
    return *a1 - *b1;
}
int intCmpDescendente(const void *a, const void *b){
    int *a1, *b1;
    a1 = (int *)a;
    b1 = (int *)b;
    return *b1 - *a1;
}

void leerDatos(void *&alumnos, int &numAlumnos){
    numAlumnos = 0;
    
}

int main(){
    int numAlumnos;
    void *alumnos;

    leerDatos(alumnos, numAlumnos);
    return 0;
}