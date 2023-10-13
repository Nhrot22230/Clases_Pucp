#include<bits/stdc++.h>
using namespace std;
enum{NODO_VAL, NODO_NEXT};

void *crearNodo(int valor){
    void **nodo = new void *[2];
    nodo[NODO_NEXT] = nullptr;
    int *ptrValor = new int; *ptrValor = valor;
    nodo[NODO_VAL] = ptrValor;

    return nodo;
}

void eliminarNodo(void **&node){
    int *ptrValor = (int *)(node[NODO_VAL]);
    delete ptrValor;
    delete node;
}

int desapilar(void *&pilaEnteros){
    if(pilaEnteros == nullptr) return -1;

    void **cima = (void **)pilaEnteros;
    int resultado = *((int *)(cima[NODO_VAL]));
    pilaEnteros = cima[NODO_NEXT];
    eliminarNodo(cima); 
    return resultado;
}

void apilar(void *&pilaEnteros, int valor){
    void **pila = (void **)pilaEnteros;
    if(pila == nullptr){
        pilaEnteros = crearNodo(valor);
    }
    else{
        void **cima = (void **)crearNodo(valor);
        cima[NODO_NEXT] = pila;
        pilaEnteros = cima;
    }
}

void imprimirPila(void *pilaEnteros){
    void **cur = (void **)pilaEnteros;
    while(cur){
        cout << *((int *)(cur[NODO_VAL])) << "->";
        cur = (void **)(cur[NODO_NEXT]);
    }
    cout << endl;
}

void crearPila(void *&pila){
    pila = nullptr;
}

int contarElementos(void *pilaEnteros){
    void **cur = (void **)pilaEnteros;
    int cont = 0;
    while(cur){
        cur = (void **)(cur[NODO_NEXT]);
        cont++;
    }
    return cont;
}

void hanoi_recursion(int n, void *&pilaA, void *&aux, void *&pilaB){
    if(n == 1){
        apilar(pilaB, desapilar(pilaA));
    }
    else{
        hanoi_recursion(n-1, pilaA, pilaB, aux);
        
        apilar(pilaB, desapilar(pilaA));

        hanoi_recursion(n-1, aux, pilaA, pilaB);
    }
}

void tower_hanoi(void *&pilaA, void *&pilaB){
    void *aux;
    crearPila(aux);
    int n = contarElementos(pilaA);
    hanoi_recursion(n, pilaA, aux, pilaB);
}

int cima(void *pila){
    void **aux = (void **)pila;
    return *((int *)(aux[NODO_VAL]));
}

void Hanoi_dibujito(void *&aux, void*&destino, void *&origen){
    while(aux != nullptr || origen != nullptr){
        cout << "A: ";
        imprimirPila(origen);
        cout << "aux: ";
        imprimirPila(aux);
        cout << "B: ";
        imprimirPila(destino);
        cout << endl;
        if(destino == nullptr && origen != nullptr){                // caso destino vacio, pasar ultimo elemento de A
            apilar(destino, desapilar(origen));
            if(aux != nullptr)                                      
                while (aux != nullptr)
                    apilar(destino, desapilar(aux));        // para que esto funcione correctamente debe estar aux como : 4->3->2->1 XD
        }
        else if(cima(destino) > cima(origen)){
            apilar(destino, desapilar(origen));
            if(aux != nullptr)
                while (aux != nullptr)
                    apilar(destino, desapilar(aux));
        }
        else
            apilar(aux, desapilar(destino));
    }
}

int main(){
    void *pilaA, *pilaB, *aux;
    crearPila(pilaA); crearPila(pilaB); crearPila(aux);
    
    for(int i=10; i>0; i--){
        apilar(pilaA, i);
    }
    cout << "===== ANTES DE HANOI ====="<<endl;
    imprimirPila(pilaA);
    imprimirPila(pilaB);

    Hanoi_dibujito(aux, pilaB, pilaA);

    cout << "==== DESPUES DE HANOI ===="<<endl;
    imprimirPila(pilaA);
    imprimirPila(pilaB);
    clock_gettime;
    return 0;
}