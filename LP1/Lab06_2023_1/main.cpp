/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Candi
 *
 * Created on 29 de setiembre de 2023, 04:04
 */

#include <cstring>

#include "ListaGenerica.h"

using namespace std;

enum{HERO_COD, HERO_NAME, HERO_ROLE, HERO_TIER, HERO_SCORE};

char *leerCadena(ifstream &arch, char letra){
    char buffTexto[150]; 
    char *ptrCadena;
    arch.getline(buffTexto, 150, letra);
    ptrCadena = new char [strlen(buffTexto) + 1];
    strcpy(ptrCadena, buffTexto);
    
    return ptrCadena;
}

void *crearRegistroHeroe(ifstream &arch){
    int cod, *ptrCod;
    char *nombre, *rol, *tier;
    double puntaje, *ptrPuntaje;
    
    arch >> cod;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadena(arch, ',');
    rol = leerCadena(arch, ',');
    tier = leerCadena(arch, ',');
    arch >> puntaje; arch.get();
    
    ptrCod = new int; *ptrCod = cod;
    ptrPuntaje = new double; *ptrPuntaje = puntaje;
    
    void **hero = new void *[5];
    hero[HERO_COD] = ptrCod;
    hero[HERO_NAME] = nombre;
    hero[HERO_ROLE] = rol;
    hero[HERO_TIER] = tier;
    hero[HERO_SCORE] = ptrPuntaje;
    
    return hero;
}

void llenar_arreglo_heroes(void *&arr_heros, int &cant, const char *archNomb){
    ifstream arch(archNomb, ios::in);
    
    void **arreglo = new void *[270];
    void *heroe = nullptr;
    cant = 0;
    while(not arch.eof()){
        heroe = crearRegistroHeroe(arch);
        if(arch.eof()) break;
        arreglo[cant] = heroe;
        cant++;
    }
    
    void **aux = new void *[cant + 1] {};
    for(int i=0; i<cant; i++)
        aux[i] = arreglo[i];
    
    delete arreglo;
    arr_heros = aux;
}

int cmp_multicriterio_void(const void *arr_i,const void *arr_j){
    void **arreglo_i = (void **)arr_i;
    void **arreglo_j = (void **)arr_j;
    
    void **heroA  = (void  **)(* arreglo_i);
    void **heroB  = (void  **)(* arreglo_j);
    char *nombreA = (char   *)heroA[HERO_NAME];
    char *nombreB = (char   *)heroB[HERO_NAME];
    double *puntA = (double *)heroA[HERO_SCORE];
    double *puntB = (double *)heroB[HERO_SCORE];
    
    int eval = strcmp(nombreA,nombreB);
    if(eval != 0) return eval;
    else return *puntA-*puntB;
}

void imprimirHeroe(const void *hero){
    void **heroe = (void **)hero;
    
    cout << (char *)(heroe[HERO_NAME]) << "   " << *((double *)(heroe[HERO_SCORE])) << endl;
}

void leer_heroe(void *reg){
    
}

void crear_lista_heroes(void *arr_heros, void *&lista_heroes, void ( *leer)(void *)){
    crearLista(lista_heroes);
    void **arreglo_heroes = (void **)arr_heros;
    for(int i=0; arreglo_heroes[i]; i++){
        insertaRegistroLista(lista_heroes, arreglo_heroes[i]);
    }
}

int compararNombreHeroes(const void *heroA, const void *heroB){
    void **heroeA  = (void  **)(heroA);
    void **heroeB  = (void  **)(heroB);
    char *nombreA = (char   *)heroeA[HERO_NAME];
    char *nombreB = (char   *)heroeB[HERO_NAME];
    
    return strcmp(nombreA,nombreB);
}

void eliminar_lista_heroes_repetidos(void *&lista, void ( *eliminar)(void **&, void **&)){
    eliminarRepetidos(lista, compararNombreHeroes, eliminar);
}

int main(int argc, char** argv) {
    void *arreglo_heroes, *lista_heroes;
    int cantidad_total_heroes;
    
    void **arr = nullptr;
    llenar_arreglo_heroes(arreglo_heroes, cantidad_total_heroes, "heroes_changelog_1223.csv");   
    qsort(arreglo_heroes, cantidad_total_heroes, sizeof(void *), cmp_multicriterio_void);
    crear_lista_heroes(arreglo_heroes, lista_heroes, leer_heroe);
    imprimirLista(lista_heroes, imprimirHeroe);
   
    eliminar_lista_heroes_repetidos(lista_heroes, eliminar_registro);
    
    cout << endl << endl;
    imprimirLista(lista_heroes, imprimirHeroe);
    
    return 0;
}

