/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 28 de septiembre de 2023, 10:13 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ListaGenerica.h"
#include "ColaGenerica.h"
using namespace std;

int compararRegistroEntero(const void *regA, const void *regB){
    int numA = *((int *)(regA));
    int numB = *((int *)(regB));
    
    if(numA > numB) return 1;
    if(numA == numB) return 0;
    return -1;
}

void *creaRegistroEntero(ifstream &arch){
    int num;
    arch >> num;
    if(arch.eof()) return nullptr;
    
    void * reg = nullptr;
    int *ptrNum = new int;
    
    *ptrNum = num;
    reg = ptrNum;
    return reg;
}

void imprimirRegistroEntero(void *reg){
    int numA = *((int *)(reg));
    cout << numA << "  ";
}
/*
 * 
 */
int main(int argc, char** argv) {
    void *lista, *listaOrdenada, *cola;
    crearLista(lista);
    crearLista(listaOrdenada);
    crearCola(cola);
    ifstream archNum("input.txt", ios::in);
    void *reg = nullptr;
    
    while(not archNum.eof()){
        reg = creaRegistroEntero(archNum);
        if(archNum.eof()) break;
        insertaRegistroLista(lista, reg);
        insertaOrdenadoRegistroLista(listaOrdenada, reg, compararRegistroEntero);
        encolarRegistro(cola, reg);
    }
    
    imprimirLista(lista, imprimirRegistroEntero);
    imprimirLista(listaOrdenada, imprimirRegistroEntero);
    
    reg = desencolaRegistro(cola);
    imprimirCola(cola, imprimirRegistroEntero);
    
    cout << endl;
    imprimirRegistroEntero(reg);
    return 0;
}

