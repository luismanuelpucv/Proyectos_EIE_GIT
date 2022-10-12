import smbus
import time

I2C_ADDRESS = 0X08

bus = smbus.SMBus(1)

while True:
    try:
        value =bus.read_i2c_block_data(I2C_ADDRESS,4)
    except:
        continue
    string = ""
    for i in range(0,10):
        string += chr(value[i])
    print (string) 
    time.sleep(1)
    
    