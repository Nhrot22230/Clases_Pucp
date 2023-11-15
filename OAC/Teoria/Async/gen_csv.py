import random

def generar_csv_manual(nombre_archivo, filas):
    with open(nombre_archivo, 'w') as archivo_csv:
        # Escribir la primera fila con encabezados
        encabezados = "Codigo,L1,L2,L3,L4,L5,L6,L7,L8,L9,L10,L11,L12,L13,L14,e1,e2"
        archivo_csv.write(encabezados + '\n')

        # Generar datos aleatorios y escribir filas en el archivo CSV
        start = 20230000
        for i in range(filas):
            fila = str(start+i)
            for j in range(16):
                nota = random.randrange(0,20)
                fila += ',' + str(nota)
            archivo_csv.write(fila + '\n')

nombre_archivo = 'datos.csv'
filas = 500

generar_csv_manual(nombre_archivo, filas)

