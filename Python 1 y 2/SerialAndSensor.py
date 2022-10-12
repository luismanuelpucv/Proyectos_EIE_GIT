import serial
import time
from w1thermsensor import W1ThermSensor

sensor = W1ThermSensor()

try:
	serialArduino = serial.Serial('/dev/ttyACM0', 9600) #abrir el puerto serial
	serialArduino.setDTR(False)
	time.sleep(1)
	serialArduino.flushInput() #limpia el buffer de entrada del puerto serial
	serialArduino.setDTR(True)
	while True:
		dato = serialArduino.readline().decode('ascii') #lee la entrada del puerto serial y la decodifica como string
		print ("Lectura serial:", dato) #imprime la entrada serial en el monitor
		temperature = sensor.get_temperature() #Obtenemos la temperatura en centígrados
		print ("Temperatura:", temperature, "°C\n") #Imprimimos el resultado
		time.sleep(1)
except:
    print ("Error, saliendo")

serialArduino.close() #cerrar el puerto serial