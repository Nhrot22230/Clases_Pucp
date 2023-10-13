/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaGenerica.h
 * Author: alulab14
 *
 * Created on 28 de septiembre de 2023, 11:22 AM
 */

#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H

#include "NodoGenerico.h"

enum{LIST_HEAD};

void eliminar_registro(void **&prev, void **&current){
    void **aux = current;
    prev[NODO_NEXT] = (void **)(current[NODO_NEXT]);
    current = prev;
    delete aux;
}

void eliminarRepetidos(void *&lista, int (* cmp)(const void *, const void *), void (eliminar) (void **&, void **&)){
    void **listaTAD = (void **)(lista);
    void **current = (void **)(listaTAD[LIST_HEAD]);
    
    void **eliminador = nullptr;
    void **prev = nullptr;
    while(current){
        eliminador = (void **)(current[NODO_NEXT]);
        prev = current;
        
        while(eliminador){
            if(cmp(current[NODO_REG], eliminador[NODO_REG]) == 0){
                eliminar(prev, eliminador);
            }
            prev = eliminador;
            eliminador = (void **)(eliminador[NODO_NEXT]);
        }
        
        
        current = (void **)(current[NODO_NEXT]);
    }
}

void insertaRegistroLista(void *&lista, void *reg){
    void **listaTAD = (void **)(lista);
    void *nodo = crearNodo(reg);
    if(listaTAD[LIST_HEAD] == nullptr){
        listaTAD[LIST_HEAD] = nodo;
    }
    else{
        void **cur = (void **)(listaTAD[LIST_HEAD]);
        while(cur[NODO_NEXT]){
            cur = (void **)(cur[NODO_NEXT]);
        }
        cur[NODO_NEXT] = nodo;
    }
}

void crearLista(void *&lista){
    void **listaTAD = new void *[1];
    listaTAD[LIST_HEAD] = nullptr;
    lista = listaTAD;
}

void insertaOrdenadoRegistroLista(void *&lista, void *reg, int (* cmp)(const void *, const void *)){
    void **nodoInsertar = (void **)(crearNodo(reg));
    void **listaTAD = (void **)(lista);
    if(listaTAD[LIST_HEAD] == nullptr){
        listaTAD[LIST_HEAD] = nodoInsertar;
    }
    else{
        void **cur = (void **)(listaTAD[LIST_HEAD]), **prev = nullptr;
        while(cur[NODO_NEXT]){
            if(cmp(nodoInsertar[NODO_REG], cur[NODO_REG]) == 1){
                nodoInsertar[NODO_NEXT] = cur;
                
                if(prev) prev[NODO_NEXT] = nodoInsertar;
                else listaTAD[LIST_HEAD] = nodoInsertar;
                
                return;
            }
            prev = cur;
            cur = (void **)(cur[NODO_NEXT]);
        }
        cur[NODO_NEXT] = nodoInsertar;
    }
}

void imprimirLista(void *lista, void (* impReg)(const void *)){
    void **listaTAD = (void **)(lista);
    void **cur = (void **)(listaTAD[LIST_HEAD]);
    while(cur){
        impReg(cur[NODO_REG]);
        cur = (void **)(cur[NODO_NEXT]);
    }
    cout << endl;
}

#endif /* LISTAGENERICA_H */

