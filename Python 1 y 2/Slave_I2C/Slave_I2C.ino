#include <Wire.h>

#define SLAVE_ADDRESS 0x08

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);
}

void loop() {
  delay(1000);
}

byte data = 0;

//fución que se ejecuta cuando lo requiere el dispositivo maestro
void requestEvent() {
  Wire.write("HOLA MUNDO");
  data++;
}
