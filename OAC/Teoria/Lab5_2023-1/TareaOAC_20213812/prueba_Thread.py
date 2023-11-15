import threading
import time
import concurrent.futures
import random

tiempo_ini = 5
tiempo_fin = 10


menu = ["Aji de Gallina", "Pollo a la brasa", "Tallarin Saltado", "Chifa 5 Sabores", "Arroz con Pollo", "Tallarin con Carne", "Maki acevichado", "Pollo con Verduras", "Carapulcra con Sopa Seca"]
pedidos_sin_cocinar = []
pedidos_sin_enviar = []

lock_service = threading.Lock()

def toma_pedidos():
    while True:
        print("Esperando pedido... (min 1 : max 9)")
        plato = -1
        try:
            plato = (int(input()) - 1)%9
        except:
            print("Escribe Bien OE!")
            plato = -1
        
        if(plato < 0): continue
        pedidos_sin_cocinar.append(menu[plato])

def mesero():
    while True:
        #print("Revisando platillos...")
        if(not pedidos_sin_enviar):
            #print("Sin platillos")
            time.sleep(1)
        else:
            platillo = pedidos_sin_enviar[0]
            pedidos_sin_enviar.pop(0)
            print(f"Enviando...{platillo}")
            time.sleep(random.randint( tiempo_ini, tiempo_fin))
            print(f"{platillo} Enviado!")

def chef():
    while True:
        #print("Recibiendo pedido...")
        if(not pedidos_sin_cocinar):
            #print("Sin pedidos")
            time.sleep(1)
        else:
            pedido = pedidos_sin_cocinar[0]
            pedidos_sin_cocinar.pop(0)
            print(f"Cocinando...{pedido}")
            time.sleep(random.randint( tiempo_ini, tiempo_fin))
            print(f"{pedido} listo para enviar!!")
            pedidos_sin_enviar.append(pedido)


def main():
    Pedro = threading.Thread(target=toma_pedidos, args=())

    Pedro.start()

    with concurrent.futures.ThreadPoolExecutor(max_workers=2000) as pollos_maycol:
        for i in range(1000):
            pollos_maycol.submit(chef)
            pollos_maycol.submit(mesero)
    
    Pedro.join()

if __name__ == "__main__":
    main()