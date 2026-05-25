#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

void Inserccion(int *V,int n){
    int i,j,x;
    for (i = 2; i <=n; i++){
        x=V[i];
        j=i-1;
        while (j > 0 && V[j] > x){
            V[j+1]=V[j];
            j=j-1;
        }
        V[j+1]=x;
    }
}

void leerVector(int* V,int inicial, int final){
    for (int i = inicial; i <=final; i++) {
        cout << V[i] <<" ";
    }
}

int main(){
    int semilla,n,inicial,final;
    clock_t tinicio, tfin;

    cout <<"Semilla inicial para generar numero aleatorios: ";
    cin >> semilla;
    cout <<"Introduce el tamanio del vector (n): ";
    cin >> n;
    cout <<"Posiciones inicial y final del vector para mostar "<<endl;
    cout <<"Inicial: ";
    cin >> inicial;
    cout <<"Final: ";
    cin >> final;

    int* vmejor = new int[n+1];
    int* vcualquiera = new int[n+1];
    int* vpeor = new int[n+1];

    if (vmejor==NULL || vcualquiera==NULL || vpeor==NULL) {
        cout <<" ERROR AL CREAR LOS VECTORES ";
        return -1;
    }

    // Inicializamos el generador de números aleatorios con la semilla
    srand(semilla);

    for (int i = 1; i <=n; i++) {
        vmejor[i]=i;
        vpeor[i]=n-i+1; //Ej 10-1 +1=10
        vcualquiera[i]=rand();
    }

    

    cout <<"ALGORITMO DE INSERCION "<<endl;

    //CASO MEJOR
    cout <<"CASO MEJOR ";
    cout <<"---------------------"<<endl;
    cout <<"Vector a ordenar: ";
    leerVector(vmejor,inicial,final);
    
    // 1. Empezamos a contar el tiempo
    tinicio = clock();

    // 2. Ejecutamos el algoritmo
    Inserccion(vmejor, n);

    // 3. Paramos el reloj
    tfin = clock();

    // 4. Calculamos los milisegundos
    double tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;

    cout <<"\nVector ordenado: ";
    leerVector(vmejor,inicial,final);
    cout <<"\nTiempo de ejecucion (ms): "<<tiempo <<endl;

    //CASO CUALQUIERA
    cout <<"CASO CUALQUIERA ";
    cout <<"---------------------"<<endl;
    cout <<"Vector a ordenar: ";
    leerVector(vcualquiera,inicial,final);
    
    // 1. Empezamos a contar el tiempo
    tinicio = clock();

    // 2. Ejecutamos el algoritmo
    Inserccion(vcualquiera, n);

    // 3. Paramos el reloj
    tfin = clock();

    // 4. Calculamos los milisegundos
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;

    cout <<"\nVector ordenado: ";
    leerVector(vcualquiera,inicial,final);
    cout <<"\nTiempo de ejecucion (ms): "<<tiempo <<endl;

    //CASO PEOR
    cout <<"CASO PEOR ";
    cout <<"---------------------"<<endl;
    cout <<"Vector a ordenar: ";
    leerVector(vpeor,inicial,final);
    
    // 1. Empezamos a contar el tiempo
    tinicio = clock();

    // 2. Ejecutamos el algoritmo
    Inserccion(vpeor, n);

    // 3. Paramos el reloj
    tfin = clock();

    // 4. Calculamos los milisegundos
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;

    cout <<"\nVector ordenado: ";
    leerVector(vpeor,inicial,final);
    cout <<"\nTiempo de ejecucion (ms): "<<tiempo <<endl;

    delete[] vmejor;
    delete[] vcualquiera;
    delete[] vpeor;

    return 0;
}