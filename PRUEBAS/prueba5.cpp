#include <iostream>
#include <cstdlib>
#include <stack>
#include <ctime>

using namespace std;

int seleccionar_pivote(int* V,int izq,int der){
    int centro=(izq+der)/2;

    //Izquierda
    if ((V[izq] > V[centro] && V[izq] < V[der]) || (V[izq] < V[centro] && V[izq] > V[der])) {
        return izq;
    }

    //Derecha
    if ((V[der] > V[centro] && V[der] < V[izq]) || (V[der] < V[centro] && V[der] > V[izq])) {
        return der;
    }

    //Centro
    if ((V[centro] > V[izq] && V[centro] < V[der]) || (V[centro] < V[izq] && V[centro] > V[der])) {
        return centro;
    }

    return 0;//Si todos son iguales
}

void intercambiar(int* V,int i,int d){
    int aux=V[i];
    V[i]=V[d];
    V[d]=aux;
}

void quicksort(int* V,int izq,int der){
    int i,d,p;
    int pivote;

    p=seleccionar_pivote(V,izq,der);
    if (p>0) {
        pivote=V[p];
        i=izq;
        d=der;
        while (i<=d) {
            while (V[i]<pivote) {
                i=i+1;
            }
            while (V[d]>pivote) {
                d=d-1;
            }
            if (i<=d) {
                intercambiar(V,i,d);
                i=i+1;
                d=d-1;
            }
        }
        if (izq<d) {
            quicksort(V,izq,d);
        }
        if (i<der) {
            quicksort(V,i,der);
        }
    }
}

// 1. Añadimos & a npaso y añadimos el parámetro nivel
void quicksort_traza(int* V, int izq, int der, int &npaso, int nivel) {
    int i, d, p;
    int pivote;
    p = seleccionar_pivote(V, izq, der);

    cout << "\n";
    
    // 2. Imprimimos los espacios en blanco según la profundidad del nivel
    for (int k = 0; k < nivel; k++) {
        cout << "    "; 
    }

    cout << npaso << ".- quicksort_traza(izq: " << izq << ", der: " << der << ") | Posicion Pivote: " << p << " | Valor Pivote: ";
    
    // 3. Protegemos el acceso a V[0]
    if (p > 0) {
        cout << V[p];
    } else {
        cout << "N/A";
    }
    
    npaso++;

    if (p > 0) {
        pivote = V[p];
        i = izq;
        d = der;
        while (i <= d) {
            while (V[i] < pivote) {
                i = i + 1;
            }
            while (V[d] > pivote) {
                d = d - 1;
            }
            if (i <= d) {
                intercambiar(V, i, d);
                i = i + 1;
                d = d - 1;
            }
        }
        if (izq < d) {
            // Pasamos npaso y aumentamos el nivel en 1
            quicksort_traza(V, izq, d, npaso, nivel + 1);
        }
        if (i < der) {
            // Pasamos npaso y aumentamos el nivel en 1
            quicksort_traza(V, i, der, npaso, nivel + 1);
        }
    }
}

void mostrarVector(int* V,int n){
    for (int i = 1; i <=n; i++) {
        cout<<V[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Introduce el tamanio del vector: ";
    cin >>n;

    int* V=new int[n+1];

    if (V==NULL) {
        cout<<"ERROR:No se pudo crear el vector ";
        return -1;
    }

    for (int i = 1; i <= n; i++) {
        cout<<"Introduce el elemento del vector "<<i<<": ";
        cin>>V[i];
    }

    mostrarVector(V,n);
    
    // Al pasar npaso por referencia, necesitamos instanciarlo primero en una variable
    int paso_inicial = 1;
    quicksort_traza(V, 1, n, paso_inicial, 0); // Arrancamos en el nivel 0
    
    cout << "\n\nVector ordenado: \n";
    mostrarVector(V, n);
    cout << endl;

    delete[] V;
    return 0;
}