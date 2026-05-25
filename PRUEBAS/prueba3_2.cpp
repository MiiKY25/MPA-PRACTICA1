#include <iostream>

using namespace std;

// 1. Función matemática pura (Pseudocódigo traducido directamente)
int combinaciones(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return combinaciones(n - 1, k - 1) + combinaciones(n - 1, k);
    }
}

// 2. Función con traza
// TRUCO 1: Pasamos 'num_llamada' por referencia (&) para que todas las ramas 
// del árbol recursivo compartan y actualicen la misma variable en memoria.
// TRUCO 2: Pasamos 'nivel' por valor para saber cuántos espacios imprimir.
int combinaciones_traza(int n, int k, int &num_llamada, int nivel) {
    
    // Guardamos el número actual y sumamos 1 para la siguiente función que se ejecute
    int llamada_actual = num_llamada;
    num_llamada++;

    // Imprimir tabulaciones (4 espacios por cada nivel extra de profundidad)
    for (int i = 1; i < nivel; i++) {
        cout << "    ";
    }

    // Imprimimos la línea de la traza
    cout << llamada_actual << ".- combinaciones_traza(" << n << "," << k << ")" << endl;

    // Lógica recursiva
    if (k == 0 || k == n) {
        return 1;
    } else {
        // Ejecutamos las dos ramas aumentando el nivel de profundidad en +1
        int resultado1 = combinaciones_traza(n - 1, k - 1, num_llamada, nivel + 1);
        int resultado2 = combinaciones_traza(n - 1, k, num_llamada, nivel + 1);
        
        return resultado1 + resultado2;
    }
}

int main() {
    int n, k;
    
    cout << "Introduce total de elementos (n): ";
    cin >> n;
    cout << "Introduce tamaño del grupo (k): ";
    cin >> k;

    // Primera ejecución: Solo cálculo
    cout << "\nEl numero de grupos es: " << combinaciones(n, k) << "\n\n";

    // Segunda ejecución: Cálculo y Traza
    cout << "La traza es:" << endl;
    
    int contador_llamadas = 1; // Empezamos en la llamada 1
    int nivel_inicial = 1;     // Empezamos sin tabulación (nivel 1)
    
    int resultado_traza = combinaciones_traza(n, k, contador_llamadas, nivel_inicial);

    cout << "\nEl numero de grupos es: " << resultado_traza << endl;

    return 0;
}