#include <iostream>
#include <cstdlib> // Necesaria para usar rand(), srand() y la memoria dinámica
#include <ctime>   // Necesaria para usar clock() y medir el tiempo

using namespace std;

int main() {
    // PASO 1: Pedir datos al usuario y reservar memoria
    int semilla, n;
    int pos_inicial, pos_final;

    // Pedir la semilla y configurar el generador de números aleatorios
    cout << "Semilla inicial para generar numeros aleatorios: ";
    cin >> semilla;
    srand(semilla); // Esta función "planta" la semilla para que rand() funcione bien

    // Pedir el tamaño del vector
    cout << "Introduce tamaño del vector (n): ";
    cin >> n;

    // Pedir el rango de posiciones que queremos imprimir por pantalla
    cout << "Posiciones inicial y final del vector para mostrar" << endl;
    cout << "Inicial: ";
    cin >> pos_inicial;
    cout << "Final: ";
    cin >> pos_final;
    cout << endl; // Un salto de línea extra para que quede limpio

    // Declarar los punteros para los tres vectores
    int *vmejor, *vcualquiera, *vpeor;

    // Reservar la memoria dinámica (igual que en la Práctica 1)
    vmejor = new int[n + 1];
    vcualquiera = new int[n + 1];
    vpeor = new int[n + 1];

    // Comprobación de seguridad
    if (vmejor == NULL || vcualquiera == NULL || vpeor == NULL) {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }

    // (Aquí irá el Paso 2: Rellenar los vectores)

    system("pause");
    return 0;
}