#include <iostream>
#include <cmath>

using namespace std;

int main() {

float S;    //Numero de sonidos
float CE;   //Grados celcius

cout<<"Ingrese la cantidad de sonidos en 1 minuto:";
cin>>S;

CE = (S + 32)/36;   //Formula para obtener los grados celsuis

cout<<"La temperatura en grados celcius es: "<<CE<<"°C.";

return 0;
}
