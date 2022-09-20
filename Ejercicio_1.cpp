#include <iostream>

using namespace std;

int main() {

int RES = 0;    //Inicializa que el trabajador no cumple las condiciones

int CLA;    //Clave del trabajador
int CAT;    //Categoría del trabajdor
int ANT;    //Antiguedad del trabajador

cout<<"Ingrese la clave del trabajador:";
cin>>CLA;
cout<<"Ingrese la categoría del trabajador:";
cin>>CAT;
cout<<"Ingrese la antiguedad del trabajador:";
cin>>ANT;

switch(CAT){
    case 0: case 1:
        break;
    case 2:
        if (ANT>7) {
            RES = 1;
        }
        break;
    case 3: case 4:
        if (ANT>5) {
            RES = 1;
        }
        break;
}

if (RES==0) {
    cout<<"El trabajador "<<CLA<< " no reune las condiciones para el puesto.";
}
else {
    cout<<"El trabajador "<<CLA<< " si reune las condiciones para el puesto.";
}

return 0;
}
