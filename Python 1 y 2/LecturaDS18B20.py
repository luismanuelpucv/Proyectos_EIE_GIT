import time #Importamos la librería time
from w1thermsensor import W1ThermSensor #Importamos la librería W1ThermSensor

sensor = W1ThermSensor() #Creamos el objeto sensor

while True:
    temperature = sensor.get_temperature() #Obtenemos la temperatura en centígrados
    print("Temperatura:", temperature, "°C") #Imprimimos el resultado
    time.sleep(1) #Esperamos un segundo antes de terminar el ciclo