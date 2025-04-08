import random

def adivinador():
    numero_secreto = random.randint(1, 100)
    intentos = 0
    adivinado = False

    print("🔢 Estoy pensando en un número del 1 al 100... ¿Podés adivinar cuál es?")

    while not adivinado:
        try:
            intento = int(input("Tu intento: "))
            intentos += 1

            if intento < numero_secreto:
                print("📉 Muy bajo.")
            elif intento > numero_secreto:
                print("📈 Muy alto.")
            else:
                print(f"🎉 ¡Correcto! El número era {numero_secreto}. Lo adivinaste en {intentos} intentos.")
                adivinado = True

        except ValueError:
            print("❌ Por favor, ingresá un número válido.")

adivinador()
