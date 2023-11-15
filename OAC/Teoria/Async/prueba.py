import random
import asyncio
import time

def func1():
    print("Funcion 1 empezando....")
    time.sleep(2)
    print("Funcion 1 terminado")

def func2():
    print("Funcion 2 empezando....")
    time.sleep(3)
    print("Funcion 2 terminado")

def func3():
    print("Funcion 3 empezando....")
    time.sleep(1)
    print("Funcion 3 terminado")

def prueba():
    inicio = time.perf_counter()
    func1()
    func2()
    func3()
    fin = time.perf_counter()
    print( f"Tiempo total de ejecucion: {fin - inicio}") 



if __name__ == '__main__':
    prueba()
    