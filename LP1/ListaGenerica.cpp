#include <bits/stdc++.h>

using namespace std;

enum {LIST_ELEM, LIST_NEXT};
enum {ELEM_DNI, ELEM_NOMBRE, ELEM_CURSOS};

void crearLista(void *&my_list, void *elemento){
    void **mi_lista = new void *[2];
    mi_lista[LIST_ELEM] = elemento;
    mi_lista[LIST_NEXT] = nullptr;
    my_list = mi_lista;
}

void *crearElemento(int dni, const char *nom){
    void **elemento = new void *[3];
    int *ptrDni = new int; *ptrDni = dni;

    char *nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);

    elemento[ELEM_DNI] = ptrDni;
    elemento[ELEM_NOMBRE] = nombre;
    elemento[ELEM_CURSOS] = nullptr;
    return elemento;
}

void imprimirRegistro(void *elem){
    void **elemento = (void **)elem;
    cout << "Dni:    " << *((int *)(elemento[ELEM_DNI])) << endl;
    cout << "Nombre: " << (char *)(elemento[ELEM_NOMBRE]) << endl;
}

void imprimirLista(void *my_list){
    void **cur = (void **)my_list;

    while(cur){
        imprimirRegistro(cur[LIST_ELEM]);
        cur = (void **)(cur[LIST_NEXT]);
    }
}

void insertarElemento(void *my_list, void *elem){
    if(my_list == nullptr){
        crearLista(my_list, elem);
        return;
    }
    void **cur = (void **)my_list;

    while(cur[LIST_NEXT]){
        cur = (void**)cur[LIST_NEXT];
    }
    


}

int main(){
    void *lista;
    
    crearLista(lista, (crearElemento(74368258, "Nhrot Fc")));
    imprimirLista(lista);

    return 0;
}