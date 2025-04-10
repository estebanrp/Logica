#!/usr/bin/env python3
import os

def insertar_archivo(carpeta, nuevo_nombre, posicion):
    archivos = os.listdir(carpeta)
    archivos = [f for f in archivos if f[0].isdigit()]

    archivos_separados = []
    for archivo in archivos:
        partes = archivo.split(" ", 1)
        if len(partes) == 2 and partes[0].isdigit():
            indice = int(partes[0])
            archivos_separados.append((indice, partes[1]))

    archivos_separados.sort(reverse=True)

    for indice, nombre in archivos_separados:
        if indice >= posicion:
            viejo = os.path.join(carpeta, f"{indice} {nombre}")
            nuevo = os.path.join(carpeta, f"{indice + 1} {nombre}")
            os.rename(viejo, nuevo)

    nuevo_path = os.path.join(carpeta, f"{posicion} {nuevo_nombre}")
    with open(nuevo_path, "w") as f:
        f.write("")

    print(f"✅ Archivo insertado como: {nuevo_path}")

def eliminar_archivo(carpeta, posicion):
    archivos = os.listdir(carpeta)
    archivos = [f for f in archivos if f[0].isdigit()]

    archivos_separados = []
    for archivo in archivos:
        partes = archivo.split(" ", 1)
        if len(partes) == 2 and partes[0].isdigit():
            indice = int(partes[0])
            archivos_separados.append((indice, partes[1]))

    archivos_separados.sort()

    eliminado = False
    for indice, nombre in archivos_separados:
        if indice == posicion:
            ruta = os.path.join(carpeta, f"{indice} {nombre}")
            os.remove(ruta)
            eliminado = True
            print(f"🗑️ Archivo eliminado: {ruta}")
            break

    if not eliminado:
        print(f"⚠️ No se encontró un archivo con índice {posicion}")
        return

    for indice, nombre in archivos_separados:
        if indice > posicion:
            viejo = os.path.join(carpeta, f"{indice} {nombre}")
            nuevo = os.path.join(carpeta, f"{indice - 1} {nombre}")
            os.rename(viejo, nuevo)

def app():
    print("📁 GESTOR DE ARCHIVOS NUMERADOS")
    carpeta = input("📂 Ingrese el path de la carpeta: ").strip()

    while True:
        print("\n¿Qué desea hacer?")
        print("1. Insertar archivo")
        print("2. Eliminar archivo")
        print("3. Salir")
        opcion = input("Opción: ")

        if opcion == "1":
            nombre = input("📝 Nombre del archivo (ej: 'bici.txt'): ")
            pos = int(input("🔢 Posición en la lista: "))
            insertar_archivo(carpeta, nombre, pos)

        elif opcion == "2":
            pos = int(input("🗑️ Posición del archivo a eliminar: "))
            eliminar_archivo(carpeta, pos)

        elif opcion == "3":
            print("👋 ¡Hasta luego!")
            break
        else:
            print("❌ Opción inválida.")

if __name__ == "__main__":
    app()
