/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaGenerica.h
 * Author: alulab14
 *
 * Created on 28 de septiembre de 2023, 11:43 AM
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

#include "NodoGenerico.h"

// front = first        back = last     FIFO
enum{QUEUE_FRONT, QUEUE_BACK};

void crearCola(void *&cola){
    void **colaTAD = new void*[2];
    colaTAD[QUEUE_BACK] = nullptr;
    colaTAD[QUEUE_FRONT] = nullptr;
    cola = colaTAD;
}

void encolarRegistro(void *&cola, void *reg){
    void **colaTAD = (void **)(cola);
    void **nodoGenerico = (void **)(crearNodo(reg));
    if(colaTAD[QUEUE_FRONT] == nullptr){
        colaTAD[QUEUE_BACK] = nodoGenerico;
        colaTAD[QUEUE_FRONT] = nodoGenerico;
    }
    else{
        void **last = (void **)(colaTAD[QUEUE_BACK]);
        last[NODO_NEXT] = nodoGenerico;
        colaTAD[QUEUE_BACK] = nodoGenerico;
    }
}

void *desencolaRegistro(void *&cola){
    void **colaTAD = (void **)(cola);
    void **nodoGenerico = (void **)(colaTAD[QUEUE_FRONT]);
    
    void *reg = nodoGenerico[NODO_REG];
    
    colaTAD[QUEUE_FRONT] = nodoGenerico[NODO_NEXT];
    
    delete nodoGenerico;
    return reg;
}

void imprimirCola(void *&cola, void (* impReg)(void *)){
    void **colaTAD = (void **)(cola);
    void **cur = (void **)(colaTAD[QUEUE_FRONT]);
    while(cur){
        impReg(cur[NODO_REG]);
        cur = (void **)(cur[NODO_NEXT]);
    }
    cout << endl;
}

#endif /* COLAGENERICA_H */

