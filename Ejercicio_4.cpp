#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//Función para obtener máximos y minimos
float max(float,float);
float min(float,float);

int main () {

	double TEM[24]; //Se define el vector para guardar las temperaturas
	int i;

    //Generar números aleatorios
	srand( (unsigned)time( NULL ) );

	for (i = 0; i < 24; i++) {
		TEM[i] = rand() % 46;
		cout<<"TEM["<<i+1<<"] = "<<TEM[i]<<endl;
	}
	
    //Temperatura promedio en un día
	float suma = 0;
	float promedio;
	
	for(i=0; i<24; i++) {
	    suma = suma + TEM[i];
	}
	promedio = suma/24.0;
	cout<<"La temperatura promedio del día es "<<promedio<<"°C"<<endl;
    
    //Se definen las variables para obtener la temperatura máxima
    int j;
    float comparar;
    float TEM_MAX = 0;
    int hora;
    
    //Temperatura máxima y hora de obtención
    for (i = 0; i < 24; i++) {
        for(j = 1; j < 24; j++) {
            comparar = max(TEM[i], TEM[j]);
            if (TEM_MAX < comparar) {
                TEM_MAX = comparar;
                if (TEM[i] > TEM[j]) {
                    hora = i;
                }
                else {
                    hora = j;
                }
            }
        }
    }
    cout<<"La temperatura máxima es "<<TEM_MAX<<"°C registrada a las "<<hora+1<<" horas"<<endl;
    
    //Se define la variable para obtener la temperatura mínima
    float TEM_MIN = 45;

     //Temperatura mínima y hora de obtención
    for (i = 0; i < 24; i++) {
        for(j = 1; j < 24; j++) {
            comparar = min(TEM[i], TEM[j]);
            if (TEM_MIN > comparar) {
                TEM_MIN = comparar;
                if (TEM[i] < TEM[j]) {
                    hora = i;
                }
                else {
                    hora = j;
                }
            }
        }
    }
    cout<<"La temperatura mínima es "<<TEM_MIN<<"°C registrada a las "<<hora+1<<" horas";
    
    return 0;
}

//Función para obtener el máximo entre 2 números
float max(float num1, float num2) {
    float result;
    
    if (num1>num2) {
        result=num1;
    }
    else {
        result=num2;
    }
    
    return result;
}

//Función para obtener el mínimo entre 2 números
float min(float num1, float num2) {
    float result;
    
    if (num1<num2) {
        result=num1;
    }
    else {
        result=num2;
    }
    
    return result;
}
