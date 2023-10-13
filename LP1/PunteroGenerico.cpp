#include <bits/stdc++.h>

using namespace std;


int main(){
    int a = 30;
    double b = 120.0;
    char *ptrCadena = new char[50];
    strcpy(ptrCadena, "Mi mami"); 
    char letra = 'x';

    void *punteroGenerico;

    punteroGenerico = &a;
    cout << punteroGenerico << "    ";
    cout << *((int *)punteroGenerico) << endl;
    
    
    punteroGenerico = &b;
    cout << punteroGenerico << "    ";
    cout << *((double *)punteroGenerico) << endl;

    punteroGenerico = ptrCadena;
    cout << punteroGenerico << "    ";
    cout << (char *)punteroGenerico << endl;

    punteroGenerico = &letra;
    cout << punteroGenerico << "    ";
    cout << *((char *)punteroGenerico) << endl;


    void *v, **vv;
    vv = new void *[10];
    vv[0] = &a;
    cout << vv[0] << "    ";
    cout << *((int *)vv[0]) << endl;
    return 0;
}