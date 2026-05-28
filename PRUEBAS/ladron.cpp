#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

// Funcion auxiliar casera para esquivar la restriccion de librerias
int maximo(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int MochilaDiscreta(int M, int n, int* P, int* V) {
    // 1. Reserva de memoria corregida
    int** tabla = new int*[n+1];
    for (int x = 0; x <= n; x++) { // El bucle va de 0 a n (las filas)
        tabla[x] = new int[M+1];   // Cada fila tiene M+1 columnas
    }
    
    int i, j;
    int respuesta;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) { // CORRECCIÓN: j <= M
            
            // Si no hay joyas o la mochila tiene capacidad 0, el valor es 0
            if (i == 0 || j == 0){
                tabla[i][j] = 0;
            } else {
                // Si la joya cabe en la capacidad actual 'j'
                if (P[i] <= j) {
                    // CORRECCIÓN: Usar [i][j] y la funcion casera maximo()
                    tabla[i][j] = maximo(tabla[i-1][j], tabla[i-1][j - P[i]] + V[i]);
                } else {
                    // CORRECCIÓN: Usar [i][j]
                    tabla[i][j] = tabla[i-1][j];
                }
            }
        }
    }
    
    // El resultado final está en la última celda de la matriz
    respuesta = tabla[n][M]; // CORRECCIÓN: Usar [n][M]
    
    // ---------------------------------------------------
    // ¡MUY IMPORTANTE ANTES DEL RETURN! Liberar la matriz
    for (int x = 0; x <= n; x++) {
        delete[] tabla[x];
    }
    delete[] tabla;
    // ---------------------------------------------------

    return respuesta; 
}


int main() {
    int M, n;
    
    cout << "Introduce la capacidad maxima de la mochila (M): ";
    cin >> M;
    cout << "Introduce el numero de joyas (n): ";
    cin >> n;

    cout << endl;
    cout << "Introduce los pesos de las joyas:" << endl;
    int* P = new int[n+1];
    for (int i = 1; i <= n; i++) {
         cout << "Peso joya " << i << ": ";
         cin >> P[i];
    }

    cout << endl;
    cout << "Introduce los valores de las joyas (euros):" << endl;
    int* V = new int[n+1];
    for (int i = 1; i <= n; i++) {
         cout << "Valor joya " << i << ": ";
         cin >> V[i];
    }

    cout << endl;
    cout << "Calculando botin maximo con Programacion Dinamica..." << endl;

    // Arrancamos el reloj
    clock_t t_inicio = clock();
    
    // Llamada a tu funcion
    int botinMaximo = MochilaDiscreta(M, n, P, V);
    
    // Paramos el reloj
    clock_t t_fin = clock();
    double tiempo = (double)(t_fin - t_inicio) / CLOCKS_PER_SEC * 1000;

    cout << "\n>>> EL BOTIN MAXIMO ES: " << botinMaximo << " euros." << endl;
    cout << "\nTiempo de ejecucion: " << tiempo << " milisegundos." << endl;

    // Liberamos los vectores de datos
    delete[] P;
    delete[] V;

    system("pause");
    return 0;
}