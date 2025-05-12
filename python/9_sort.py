import random

MAX = 5

def burbuja(arr):
    for i in range(MAX):
        for j in range(MAX - 1 - i):
            if arr[j] > arr[j + 1]:
                # Intercambio en Python (sin variable auxiliar)
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def seleccion(arr):
    for j in range(MAX):
        min_idx = j
        for i in range(j + 1, MAX):
            if arr[i] < arr[min_idx]:
                min_idx = i
        # Intercambio
        arr[j], arr[min_idx] = arr[min_idx], arr[j]

def insercion(arr):
    for i in range(1, MAX):
        elem = arr[i]
        j = i
        while j > 0 and arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            j -= 1

def main():
    random.seed()  # Inicializa la semilla aleatoria
    arr = [random.randint(0, 99) for _ in range(MAX)]
    
    print("Arreglo original:")
    print(arr)
    
    # Hacemos una copia para cada ordenamiento
    arr_burbuja = arr.copy()
    arr_seleccion = arr.copy()
    arr_insercion = arr.copy()
    
    burbuja(arr_burbuja)
    print("\n--> burbuja")
    print(arr_burbuja)
    
    seleccion(arr_seleccion)
    print("\n--> seleccion")
    print(arr_seleccion)
    
    insercion(arr_insercion)
    print("\n--> insercion")
    print(arr_seleccion)

if __name__ == "__main__":
    main()