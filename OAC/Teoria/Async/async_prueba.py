import random
import asyncio
import time

async def func1():
    print("Funcion 1 empezando...")
    await asyncio.sleep(2)
    print("Funcion 1 terminado")

async def func2():
    print("Funcion 2 empezando...")
    await asyncio.sleep(3)
    print("Funcion 2 terminado")

async def func3():
    print("Funcion 3 empezando...")
    
    for i in range(100000000):
        i
    
    print("Funcion 3 terminado")
 
async def dormir(num: int):
    await asyncio.sleep(num/10000)
    print(num)

async def sleepSort(arr: list):
    f_list = []
    for elem in arr:
        f_list.append(dormir(elem))

    await asyncio.gather(*f_list)

async def prueba():
    await asyncio.gather(func1(), func2(), func3())

    

if __name__ == '__main__':
    inicio = time.perf_counter()
    numeros = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
    asyncio.run(prueba())
    fin = time.perf_counter()
    print( f"Tiempo total de ejecucion: {fin - inicio}") 

