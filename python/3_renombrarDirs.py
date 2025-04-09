import os

def insertar_archivo(carpeta, nuevo_nombre, posicion):
    archivos = os.listdir(carpeta)
    
    # Filtrar solo archivos que empiezan con números
    archivos = [f for f in archivos if f[0].isdigit()]
    
    # Separar índice y nombre
    archivos_separados = []
    for archivo in archivos:
        partes = archivo.split(" ", 1)
        if len(partes) == 2 and partes[0].isdigit():
            indice = int(partes[0])
            archivos_separados.append((indice, partes[1]))

    # Ordenar por índice descendente (¡importante para evitar sobreescrituras!)
    archivos_separados.sort(reverse=True)

    # Renombrar: sumamos 1 a todos los archivos >= posición
    for indice, nombre in archivos_separados:
        if indice >= posicion:
            viejo = os.path.join(carpeta, f"{indice} {nombre}")
            nuevo = os.path.join(carpeta, f"{indice + 1} {nombre}")
            os.rename(viejo, nuevo)

    # Insertar nuevo archivo (crear o mover uno existente)
    nuevo_path = os.path.join(carpeta, f"{posicion} {nuevo_nombre}")
    with open(nuevo_path, "w") as f:
        f.write("")  # o podrías mover un archivo existente aquí

    print(f"Archivo insertado como: {nuevo_path}")

# Ejemplo de uso
insertar_archivo("/home/esteban/Cosas_de_Esteban/Papeles/obsidiana/Libreta/UNLu/1 Analisis I", "crayones.txt", 2)

