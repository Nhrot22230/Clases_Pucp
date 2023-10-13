/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoGenerico.h
 * Author: alulab14
 *
 * Created on 28 de septiembre de 2023, 11:38 AM
 */

#ifndef NODOGENERICO_H
#define NODOGENERICO_H

#include <iostream>
#include <fstream>

using namespace std;

enum {NODO_REG, NODO_NEXT};

void *crearNodo(void *reg){    
    void **nodo = new void *[2];
    nodo[NODO_REG] = reg;
    nodo[NODO_NEXT] = nullptr;
    return nodo;
}

#endif /* NODOGENERICO_H */

