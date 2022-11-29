# Importamos la paquteria necesaria
import RPi.GPIO as GPIO
import time
import datetime
import random

GPIO.setwarnings(False)

TRIG = 4 #Variable que contiene el GPIO al cual conectamos la señal TRIG del sensor
ECHO = 17 #Variable que contiene el GPIO al cual conectamos la señal ECHO del sensor
ena = 18
in1 = 23
in2 = 24
enb = 19
in3 = 6
in4 = 5

GPIO.setmode(GPIO.BCM)     #Establecemos el modo según el cual nos refiriremos a los GPIO de nuestra RPi
GPIO.setup(TRIG, GPIO.OUT) #Configuramos el pin TRIG como una salida
GPIO.setup(ECHO, GPIO.IN)  #Configuramos el pin ECHO como una entrada
GPIO.setup(ena,GPIO.OUT)
GPIO.setup(enb,GPIO.OUT)
GPIO.setup(in1, GPIO.OUT)
GPIO.setup(in2, GPIO.OUT)
GPIO.setup(in3, GPIO.OUT)
GPIO.setup(in4, GPIO.OUT)
#Define las salidas PWM
pwm_a = GPIO.PWM(ena,500)
pwm_b = GPIO.PWM(enb,500)
#inicializan los PWM con un duty Cicly de cero
pwm_a.start(0)
pwm_b.start(0)
# funciones de movimiento del carro
def  Avanza():
    #Motor derecho
    GPIO.output(in1,False)
    GPIO.output(in2,True)
    pwm_a.ChangeDutyCycle(50)
    #Motor izquierdo
    GPIO.output(in3,True)
    GPIO.output(in4,False)
    pwm_b.ChangeDutyCycle(50)
def Retrocede():
    #Motor derecho
    GPIO.output(in1,True)
    GPIO.output(in2,False)
    pwm_a.ChangeDutyCycle(50)
    #Motor izquierdo
    GPIO.output(in3,False)
    GPIO.output(in4,True)
    pwm_b.ChangeDutyCycle(50)
def Derecha():
    #Motor derecho
    GPIO.output(in1,True)
    GPIO.output(in2,False)
    pwm_a.ChangeDutyCycle(50)
    #Motor izquierdo
    GPIO.output(in3,True)
    GPIO.output(in4,False)
    pwm_b.ChangeDutyCycle(50)
def Izquierda():
    #Motor derecho
    GPIO.output(in1,False)
    GPIO.output(in2,True)
    pwm_a.ChangeDutyCycle(50)
    #Motor izquierdo
    GPIO.output(in3,False)
    GPIO.output(in4,True)
    pwm_b.ChangeDutyCycle(50)
def Para():
    #Motor derecho
    GPIO.output(in1,False)
    GPIO.output(in2,False)
    #Motor izquierdo
    GPIO.output(in3,False)
    GPIO.output(in4,False)


#Contenemos el código principal en un aestructura try para limpiar los GPIO al terminar o presentarse un error
try:
    #Implementamos un loop infinito
    while True:
        # Ponemos en bajo el pin TRIG y después esperamos 0.5 seg para que el transductor se estabilice
        GPIO.output(TRIG, GPIO.LOW)
        time.sleep(0.5)
        #Ponemos en alto el pin TRIG esperamos 10 uS antes de ponerlo en bajo
        GPIO.output(TRIG, GPIO.HIGH)
        time.sleep(0.00001)
        GPIO.output(TRIG, GPIO.LOW)
        # En este momento el sensor envía 8 pulsos ultrasónicos de 40kHz y coloca su pin ECHO en alto
        # Debemos detectar dicho evento para iniciar la medición del tiempo
        while True:
            pulso_inicio = time.time()
            if GPIO.input(ECHO) == GPIO.HIGH:
                break   
        # El pin ECHO se mantendrá en HIGH hasta recibir el eco rebotado por el obstáculo. 
        # En ese momento el sensor pondrá el pin ECHO en bajo.
        # Prodedemos a detectar dicho evento para terminar la medición del tiempo
        while True:
            pulso_fin = time.time()
            if GPIO.input(ECHO) == GPIO.LOW:
                break
        #while GPIO.input(ECHO)==0:
            #pulso_inicio = time.time()
        #while GPIO.input(ECHO)==1:
            #pulso_fin = time.time()   
        # Tiempo medido en segundos
        duracion = pulso_fin - pulso_inicio
        #Obtenemos la distancia considerando que la señal recorre dos veces la distancia a medir y que la velocidad del sonido es 343m/s
        distancia = round(34300 * duracion, 2)
        # Imprimimos resultado
        print( "Distancia: %.2f cm" % distancia)
        #Logartmo de esquivación
        if distancia > 0: #hay espacio
            print("avanza")
            Avanza()
            if distancia < 50:
                Para()
                time.sleep(1)
                Retrocede()
                time.sleep(1)
                Para()
                Girar = random.randint(0, 1)
                if Girar == 0:
                    print("der")
                    Derecha()
                    time.sleep(4)
                    Para()
                    time.sleep(2)
                elif Girar == 1:
                    print("izq")
                    Izquierda()
                    time.sleep(4)
                    Para()
                    time.sleep(2)
except KeyboardInterrupt:
    # Reiniciamos todos los canales de GPIO.
    GPIO.cleanup()
    pwm_a.stop()
    pwm_b.stop()