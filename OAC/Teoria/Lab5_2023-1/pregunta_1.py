import threading
from concurrent.futures import ThreadPoolExecutor
import time

valores = [1_000_000_000, 500_000_000, 100_000_000, 10_000_000, 1_000_000]

def calcSuma(inicio, fin) -> int:
    suma = 0
    #print(f"LLamando a la funcion con {inicio} y {fin}")
    for i in range(inicio, fin + 1):
        suma += 2*i - 1

    #print("El valor de la sub_suma es:", suma)
    return suma

def no_tengo_idea(num, ga):
    print("No tengo idea ", num, ga)

def seccion_A():
    for fin in valores:
        print(f"El valor de la suma es {calcSuma(1, fin)}")

def seccion_B(val):
    suma = 0
    with ThreadPoolExecutor(max_workers=workers) as contadores:
        for i in range(workers):
            #print(f"Calculando suma de {val}...")
            f = contadores.submit(calcSuma, int((val/workers*i)+1), int( (val/workers)*(i+1) ))
            suma += f.result()
    print(suma)

def main():
    #seccion_A()
    ga = 0

if __name__ == '__main__':

    inicio_tiempo = time.perf_counter()
    seccion_A()
    fin_tiempo = time.perf_counter()
    print("Valor total de la ejecucion:", fin_tiempo - inicio_tiempo)
    
    workers = 5
    inicio_tiempo = time.perf_counter()

    with ThreadPoolExecutor(max_workers=workers) as hilos:
        for val in valores:
            hilos.submit(seccion_B, val)

    fin_tiempo = time.perf_counter()
    print("Valor total de la ejecucion:", fin_tiempo - inicio_tiempo)
