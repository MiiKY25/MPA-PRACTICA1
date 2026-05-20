#include <iostream>
#include <stdlib.h>

using namespace std;

// =========================================================================
// FUNCIÓN PARA SELECCIONAR EL PIVOTE (Mediana de 3)
// =========================================================================
int seleccionar_pivote(int *V, int izq, int der) {
    // Si el subvector tiene 1 elemento o menos, no hay pivote válido (0)
    if (izq >= der) {
        return 0;
    }

    int centro = (izq + der) / 2;
    
    int a = V[izq];
    int b = V[centro];
    int c = V[der];

    // Lógica para encontrar cuál de los tres valores es la mediana
    // Si 'b' (centro) está en medio de 'a' y 'c'
    if ((a <= b && b <= c) || (c <= b && b <= a)) return centro;
    
    // Si 'a' (izq) está en medio de 'b' y 'c'
    if ((b <= a && a <= c) || (c <= a && a <= b)) return izq;
    
    // Si no es ninguno de los anteriores, la mediana es 'c' (der)
    return der;
}

// =========================================================================
// ALGORITMO QUICKSORT CON TRAZA (Actividad 2)
// =========================================================================
// Pasamos el contador de 'llamada' por referencia (&) para que no se reinicie
void quicksort_traza(int *V, int izq, int der, int &llamada) {
    int i, d, p;
    int pivote;

    // Buscamos la posición del pivote
    p = seleccionar_pivote(V, izq, der);

    // Si p > 0 significa que hay un pivote válido y podemos ordenar
    if (p > 0) {
        pivote = V[p];
        
        // Imprimimos la traza tal y como pide el PDF
        cout << llamada << ".- quicksort_traza(V, " << izq << ", " << der 
             << ") -> Posicion pivote: " << p << ", Pivote: " << pivote << endl;
        llamada++; // Aumentamos el contador para la siguiente llamada

        i = izq;
        d = der;

        // Bucle principal de partición
        while (i <= d) {
            // Avanzamos por la izquierda mientras los números sean menores que el pivote
            while (V[i] < pivote) {
                i = i + 1;
            }
            // Avanzamos por la derecha mientras los números sean mayores que el pivote
            while (V[d] > pivote) {
                d = d - 1;
            }

            // Si se cruzan o se igualan, los intercambiamos
            if (i <= d) {
                int temp = V[i];
                V[i] = V[d];
                V[d] = temp;
                
                i = i + 1;
                d = d - 1;
            }
        }

        // Llamadas recursivas para ordenar la sub-mitad izquierda y la derecha
        if (izq < d) {
            quicksort_traza(V, izq, d, llamada);
        }
        if (i < der) {
            quicksort_traza(V, i, der, llamada);
        }
    }
}

// =========================================================================
// PROGRAMA PRINCIPAL
// =========================================================================
int main() {
    int n;

    // 1. Pedir tamaño del vector
    cout << "Introduce el tamano del vector: ";
    cin >> n;

    // Control de errores básico
    if (n <= 0) {
        cout << "El tamano debe ser mayor que 0." << endl;
        return -1;
    }

    // 2. Reservar memoria (Regla de la posición 0 vacía)
    int *V = new int[n + 1];

    // 3. Pedir los elementos del vector
    cout << "Introduce los " << n << " elementos del vector:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> V[i];
    }

    // 4. Imprimir vector ANTES de ordenar
    cout << "\nVector original: ";
    for (int i = 1; i <= n; i++) {
        cout << V[i] << " ";
    }
    cout << "\n\n";

    // 5. Llamada a la función con traza
    cout << "--- TRAZA DE LLAMADAS ---" << endl;
    int numero_llamada = 1;
    quicksort_traza(V, 1, n, numero_llamada);
    cout << "-------------------------\n" << endl;

    // 6. Imprimir vector DESPUÉS de ordenar
    cout << "Vector ordenado: ";
    for (int i = 1; i <= n; i++) {
        cout << V[i] << " ";
    }
    cout << "\n\n";

    // 7. Liberar memoria
    delete[] V;

    system("pause");
    return 0;
}