#include <iostream>

using namespace std;

// Variables globales para mantener el estado de la mejor solución
double mejorValor = 0;
double mejorPeso = 0;
int* mejorSolucion = nullptr; // 1 si se incluye, 0 si no
int nTotal;

void maleta(int* solucionActual, double* pesos, double* valores, int indice, double pesoActual, double valorActual) {
    // Caso base: se han evaluado todos los objetos
    if (indice == nTotal) {
        if (valorActual > mejorValor) {
            mejorValor = valorActual;
            mejorPeso = pesoActual;
            for (int i = 0; i < nTotal; ++i) mejorSolucion[i] = solucionActual[i];
        }
        return;
    }

    // Opcion 1: Incluir objeto si el peso lo permite
    if (pesoActual + pesos[indice] <= 10.0) {
        solucionActual[indice] = 1;
        maleta(solucionActual, pesos, valores, indice + 1, pesoActual + pesos[indice], valorActual + valores[indice]);
    }

    // Opcion 2: No incluir objeto
    solucionActual[indice] = 0;
    maleta(solucionActual, pesos, valores, indice + 1, pesoActual, valorActual);
}

int main() {
    cout << "Introduce el numero total de objetos: ";
    cin >> nTotal;

    // Reserva de memoria dinámica
    double* pesos = new double[nTotal];
    double* valores = new double[nTotal];
    int* solucionActual = new int[nTotal];
    mejorSolucion = new int[nTotal];

    for (int i = 0; i < nTotal; ++i) {
        cout << "Objeto " << i + 1 << " - Peso y Valor: ";
        cin >> pesos[i] >> valores[i];
    }

    // Verificar datos
    cout << "\nOBJETOS INICIALES:\n";
    for (int i = 0; i < nTotal; ++i)
        cout << i + 1 << ". Peso: " << pesos[i] << " Valor: " << valores[i] << endl;

    // Resolver mediante vuelta atrás
    maleta(solucionActual, pesos, valores, 0, 0, 0);

    // Imprimir resultados
    cout << "\nSOLUCION:\nOBJETOS SELECCIONADOS:\n";
    for (int i = 0; i < nTotal; ++i) {
        if (mejorSolucion[i] == 1)
            cout << "Objeto " << i + 1 << ": Peso " << pesos[i] << " Valor " << valores[i] << endl;
    }

    cout << "\nPeso de la maleta: " << mejorPeso << "\nValor de la maleta: " << mejorValor << "\n";
    
    cout << "OBJETOS QUE QUEDAN FUERA: ";
    for (int i = 0; i < nTotal; ++i) {
        if (mejorSolucion[i] == 0) cout << i + 1 << " ";
    }
    cout << endl;

    // Liberar memoria
    delete[] pesos; delete[] valores; delete[] solucionActual; delete[] mejorSolucion;

    system("pause");
    return 0;
}