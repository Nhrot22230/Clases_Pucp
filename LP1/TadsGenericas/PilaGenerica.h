/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaGenerica.h
 * Author: alulab14
 *
 * Created on 28 de septiembre de 2023, 12:05 PM
 */

#ifndef PILAGENERICA_H
#define PILAGENERICA_H

#include "NodoGenerico.h"

enum{STACK_PEEK};

void crearPila(void *&pila){
    void **pilaTAD = new void *[1];
    pilaTAD[STACK_PEEK] = nullptr;
    
    pila = pilaTAD;
}

#endif /* PILAGENERICA_H */

