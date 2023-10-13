#include <bits/stdc++.h>
#define INCREMENTO 1

using namespace std;

enum Reg{COD, NOM, NOTA, PROM};

void cargarAlumnos(void *&al, const char *nombreArch){
    void **alumnos, *reg;
    int numDat=0, cap=0;
    ifstream arch(nombreArch, ios::in);
    
    if(not arch.is_open()){
        cout << "Error" << endl; exit(1);
    }
    alumnos = nullptr;
    while(not arch.eof()){
        reg = leerRegistro(arch);
        if(arch.eof()) break;
        if(numDat == cap) aumentarEspacios(alumnos, numDat, cap);
        alumnos[numDat-1] = reg;
        numDat++;
    }
}

void aumentarEspacios(void **&alumnos, int &numDat, int &cap){
    void **aux;
    cap += INCREMENTO;
    if(alumnos == nullptr){
        alumnos = new void*[cap]{};
        numDat = 1;
    }
    aux = new void*[cap]{};
    for(int i=0; i<numDat; i++){
        aux[i] = alumnos[i];
    }
    delete alumnos;
    alumnos = aux;
}

char *leeCadena(ifstream &arch){
    char cadena[100];
    arch >> cadena;
    char * ptrCad = new char[strlen(cadena) + 1];
    strcpy(ptrCad, cadena);
    return ptrCad;
}

void *leerRegistro(ifstream &arch){
    void **registro;
    int *codigo, cod;
    char *nombre;
    arch >> cod;
    if(arch.eof()) return nullptr;
    codigo = new int;
    *codigo = cod;
    arch.get();
    nombre = leeCadena(arch);
    registro = new void*[4];
    registro[COD] = codigo;
    registro[NOM] = nombre;
    registro[NOTA] = nullptr;
    registro[COD] = nullptr;
    
}

void probarLectura(void *al, const char *nombreArch){
    void **alumnos = (void **)al;
    for(int i=0; alumnos[i]; i++){
        imprimeAlumno(alumnos[i]);
    }
}

void imprimeAlumno(void *alumno){
    void **aux = (void **)alumno;
    int *codigo;
    char *nombre;
    codigo = (int *)aux[COD];
    nombre = (char *)aux[NOM];
    cout << "Codigo: "<< codigo << setw(10) << "| Nombre: " << nombre << endl;
}

int main(){
    return 0;
}