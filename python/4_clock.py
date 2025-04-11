# reloj_digital.py

import time
import os

def reloj():
    try:
        while True:
            ahora = time.strftime("%H:%M:%S")
            os.system('cls' if os.name == 'nt' else 'clear')  # Limpia la pantalla
            print("⏰ Reloj digital\n")
            print(f"    {ahora}")
            time.sleep(1)
    except KeyboardInterrupt:
        print("\nReloj detenido.")

if __name__ == "__main__":
    reloj()
