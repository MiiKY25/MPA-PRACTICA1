#include <iostream>
#include <cstdlib> // Necesario para rand() y srand()
#include <ctime>   // Necesario para clock() y clock_t

using namespace std;

// -------------------------------------------------------------------------
// ALGORITMO DE INSERCIÓN (Traducido del pseudocódigo)
// Nota: Pasamos el vector V como puntero (*V) igual que en la práctica 1.
// -------------------------------------------------------------------------
void Insercion(int *V, int n) {
    int i, j, x;
    
    // Bucle para: desde 2 hasta n (porque la posición 0 no se usa y asumimos que V[1] está "ordenado")
    for (i = 2; i <= n; i++) {
        x = V[i];
        j = i - 1;
        
        // Bucle mientras: desplaza los elementos mayores que 'x' hacia la derecha
        while (j > 0 && V[j] > x) {
            V[j + 1] = V[j];
            j = j - 1;
        }
        V[j + 1] = x;
    }
}

// Función auxiliar para no repetir código al imprimir los vectores.
// Solo imprime desde la posición 'inicial' hasta 'final' que diga el usuario.
void imprimirVector(int *V, int inicial, int final) {
    for (int i = inicial; i <= final; i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}

int main() {
    int semilla, n, inicial, final;

    // --- ENTRADA DE DATOS ---
    cout << "Semilla inicial para generar numeros aleatorios: ";
    cin >> semilla;
    cout << "Introduce tamano del vector (n): ";
    cin >> n;
    cout << "Posiciones inicial y final del vector para mostrar" << endl;
    cout << "Inicial: ";
    cin >> inicial;
    cout << "Final: ";
    cin >> final;
    cout << endl;

    // Inicializamos el generador de números aleatorios con la semilla
    srand(semilla);

    // --- RESERVA DE MEMORIA ---
    // Recordamos la regla de oro: tamaño n + 1
    int *vmejor = new int[n + 1];
    int *vcualquiera = new int[n + 1];
    int *vpeor = new int[n + 1];

    if (vmejor == NULL || vcualquiera == NULL || vpeor == NULL) {
        cout << "Error de memoria." << endl;
        return -1;
    }

    // --- INICIALIZACIÓN DE LOS VECTORES ---
    for (int i = 1; i <= n; i++) {
        vmejor[i] = i;              // CASO MEJOR: Ya está ordenado ascendentemente (1, 2, 3...)
        vpeor[i] = (n - i) + 1;     // CASO PEOR: Está ordenado al revés (n, n-1, n-2...)
        vcualquiera[i] = rand();    // CASO CUALQUIERA: Números aleatorios
    }

    cout << "ALGORITMO DE INSERCION\n" << endl;

    // Variables para medir el tiempo
    clock_t tinicio, tfin;
    double tiempo;

    // ==========================================
    // CASO MEJOR
    // ==========================================
    cout << "CASO MEJOR" << endl;
    cout << "--------------------" << endl;
    cout << "Vector a ordenar: ";
    imprimirVector(vmejor, inicial, final);

    // Medimos el tiempo justo antes y justo después de llamar a la función
    tinicio = clock();
    Insercion(vmejor, n);
    tfin = clock();

    // Fórmula del PDF para calcular los milisegundos
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000.0;

    cout << "Vector ordenado:  ";
    imprimirVector(vmejor, inicial, final);
    cout << "Tiempo de ejecucion (ms): " << tiempo << "\n\n";

    // ==========================================
    // CASO CUALQUIERA
    // ==========================================
    cout << "CASO CUALQUIERA" << endl;
    cout << "--------------------" << endl;
    cout << "Vector a ordenar: ";
    imprimirVector(vcualquiera, inicial, final);

    tinicio = clock();
    Insercion(vcualquiera, n);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000.0;

    cout << "Vector ordenado:  ";
    imprimirVector(vcualquiera, inicial, final);
    cout << "Tiempo de ejecucion (ms): " << tiempo << "\n\n";

    // ==========================================
    // CASO PEOR
    // ==========================================
    cout << "CASO PEOR" << endl;
    cout << "--------------------" << endl;
    cout << "Vector a ordenar: ";
    imprimirVector(vpeor, inicial, final);

    tinicio = clock();
    Insercion(vpeor, n);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000.0;

    cout << "Vector ordenado:  ";
    imprimirVector(vpeor, inicial, final);
    cout << "Tiempo de ejecucion (ms): " << tiempo << "\n\n";

    // --- LIBERAR MEMORIA (¡El camión de la basura!) ---
    delete[] vmejor;
    delete[] vcualquiera;
    delete[] vpeor;

    system("pause");
    return 0;
}