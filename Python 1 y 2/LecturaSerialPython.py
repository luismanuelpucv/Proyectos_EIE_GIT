import serial
import time

try:
	serialArduino = serial.Serial('/dev/ttyACM0', 9600) #abrir el puerto serial
	serialArduino.setDTR(False)
	time.sleep(1)
	serialArduino.flushInput() #limpia el buffer de entrada del puerto serial
	serialArduino.setDTR(True)
	while True:
		dato = serialArduino.readline().decode('ascii') #lee la entrada del puerto serial y la decodifica como string
		print (dato) #imprime la entrada serial en el monitor
except:
    print ("Error, saliendo")

serialArduino.close() #cerrar el puerto serial
