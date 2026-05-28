#include <iostream>
#include <cstdlib>
#include <stack>
#include <ctime>

using namespace std;

void AjustarPesos(float* P,int n){
    for (int i = 1; i <=n; i++) {
        if (P[i]<10.0) {
            P[i]=P[i]+2.5;
        }
    }
    
}

float BuscarMaximo(float* P, int inicio, int fin) {
    // 1. CASO BASE: Si solo hay un elemento, ese es el máximo
    if (inicio == fin) {
        return P[inicio];
    } 
    // 2. CASO RECURSIVO: Dividir y Vencer
    else {
        int medio = (inicio + fin) / 2; // Partimos por la mitad
        
        // Llamadas recursivas para buscar en ambas mitades
        float max_izq = BuscarMaximo(P, inicio, medio);
        float max_der = BuscarMaximo(P, medio + 1, fin);
        
        // 3. COMBINAR: Devolver el más grande de los dos
        if (max_izq > max_der) {
            return max_izq;
        } else {
            return max_der;
        }
    }
}

void AnalizarPaquetes(float* P,int n){
    float peso_maximo;

    AjustarPesos(P,n);
    peso_maximo=BuscarMaximo(P,1,n);

    cout<<"Analisis completado";
    cout<<"El peso maximo a transportar es: "<<peso_maximo;
}

int main(){
    int n;

    cout<<"Introduce el numero paquetes (n): ";
    cin>>n;

    float* P=new float[n+1];

    for (int i = 1; i <=n; i++) {
        cout<<"Introduce el peso del paquete "<<i<<": ";
        cin>>P[i];
    }

    AnalizarPaquetes(P,n);

    return 0;
}