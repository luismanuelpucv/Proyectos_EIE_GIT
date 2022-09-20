#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main () {
    int n;
    float varianza=0, media=0, ds=0, moda=0; //definimos nuestras variables a utilizar, utilizamos float para tambien considerar los decimales
    cout << "Escriba la cantidad de calificaciones: "; //solicitamos al usuario que escriba
    cin>>n;
    int ALU[n];
  
    for(int i=0; i<n; i++)
    {
        cout<<endl;
        cout<<"Escriba la calificacion N° "<<i+1<<": "; //definimos de i+1 para que la parta desde la calificacion numero 1 y no desde la 0
        cin>>ALU[i];
    }

    cout<<endl<<"Las calificaciones son: "; //dando registro de las calificaciones 
    for(int i=0; i<n; i++) {
        cout<<ALU[i]<<" ";
    }
    cout<<endl;
    
    //Cálculo de la media aritmética
    for(int i=0;i<n;i++) {
        media+=ALU[i];
    }
    media=media/n; //valor de la media aritmética expresada en formula
    cout << "La media es: "<<media<<endl;

    //Cálculo de la varianza
    for(int i=0;i<n;i++) {
        varianza=(varianza+pow((ALU[i]-media),2))/(n-1); //valor de la varianza expresada en formula
    }
    cout << "La varianza es: "<<varianza<<endl;

    //Cálculo de la desviación estandar
    ds=sqrt(varianza); //valor de la desviacion estandar expresada en formula
    cout << "La desviacion estandar es: "<<ds<<endl;

    //Cálculo de la moda
    int j;
    int repeticiones_a, repeticiones_b=0;
    
    int i;
    for (int i=0; i<n; i++) {
        repeticiones_a = 0;
        for (j=0; j<n; j++) {
            if (ALU[i]==ALU[j] && i != j) {
                repeticiones_a = repeticiones_a + 1;
            }
        }
        if (repeticiones_a>=repeticiones_b) {
            repeticiones_b = repeticiones_a;
            moda = ALU[i];
        }
    }
    cout << "La moda es: "<<moda<<endl;
    
return 0;
}
