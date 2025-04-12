# objetivo.py
import sys
import time

n = int(sys.argv[1])

# Simula un algoritmo O(n^2)
start = time.time()

total = 0
for i in range(n):
    for j in range(n):
        total += i * j

end = time.time()

print(f"Tiempo: {end - start}")
