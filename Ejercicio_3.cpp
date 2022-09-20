#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {

	int NUM[256];
	int i;

    //Generar números aleatorios
	srand( (unsigned)time( NULL ) );

	for (i = 0; i < 256; i++) {
		NUM[i] = rand() % 256;
		cout<<"NUM["<<i+1<<"] = "<<NUM[i]<<endl;
	}
    
    int NUM_BIN[256][8]; //Definir un arreglo de 256x8 para guardar los números binarios
    int j;

    //Conversión de decimal a binario
	for (i = 0; i < 256; i++) {
	    for (j=7; j>=0; j--) {
	        NUM_BIN[i][j] = NUM[i] % 2;
	        NUM[i] = NUM[i]/2;
	    }
	    cout<<"NUM_BIN["<<i+1<<"] = ";
	    for (j=0; j<8; j++){
	        cout<<NUM_BIN[i][j];
	    }
	    cout<<endl;
	}
    
	//Lectura de los números binarios con LEDs	
    for (i = 0; i < 256; i++) {
        cout<<"LED["<<i+1<<"] : ";
	    for (j=7; j>=0; j--) {
	        if (NUM_BIN[i][j]==0){
	            cout<<"off ";
	        }
	        else {
	            cout<<"on ";
	        }
	    }
	    cout<<endl;
    }
    
    return 0;
}
