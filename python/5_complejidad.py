# analizador.py
import subprocess
import matplotlib.pyplot as plt
import time

# Valores de entrada que se probarán
tamaños = [100, 200, 300, 400, 500]
tiempos = []

for n in tamaños:
    print(f"Probando con n = {n}...")
    
    # Ejecuta objetivo.py con el parámetro n
    resultado = subprocess.run(
        ['python', 'objetivo.py', str(n)],
        capture_output=True,
        text=True
    )
    
    # Extrae el tiempo del output
    for linea in resultado.stdout.splitlines():
        if "Tiempo:" in linea:
            t = float(linea.split(":")[1].strip())
            tiempos.append(t)
            break

# Grafica los resultados
plt.plot(tamaños, tiempos, marker='o')
plt.title("Estimación de complejidad temporal")
plt.xlabel("Tamaño de entrada (n)")
plt.ylabel("Tiempo de ejecución (segundos)")
plt.grid(True)
plt.show()
