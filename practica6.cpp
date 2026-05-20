#include <iostream>
#include <string>

using namespace std;

// Función para ordenar los vectores según la relación valor/peso (de mayor a menor)
void OrdenarDecreciente_VP(string O[], double V[], double P[], int n) {
    // Implementación de un método de ordenación sencillo (Bubble Sort)
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            double ratio1 = V[j] / P[j];
            double ratio2 = V[j+1] / P[j+1];
            
            if (ratio1 < ratio2) {
                // Intercambiar Nombres (O)
                string tempO = O[j];
                O[j] = O[j+1];
                O[j+1] = tempO;
                
                // Intercambiar Valores (V)
                double tempV = V[j];
                V[j] = V[j+1];
                V[j+1] = tempV;
                
                // Intercambiar Pesos (P)
                double tempP = P[j];
                P[j] = P[j+1];
                P[j+1] = tempP;
            }
        }
    }
}

// Función que resuelve el problema de la mochila aplicando estrategia voraz
double* Mochila(double M, string O[], double P[], double V[], int n) {
    // Se reserva un vector para las proporciones introducidas, tamaño n+1
    double* X = new double[n + 1];
    
    // Inicializar a 0 (X <- 0)
    for (int k = 1; k <= n; k++) {
        X[k] = 0.0;
    }
    
    // Ordenar Decreciente VP (O, V, P)
    OrdenarDecreciente_VP(O, V, P, n);
    
    int i = 1;
    double peso = 0.0;
    
    // mientras peso < M y i <= n hacer
    while (peso < M && i <= n) {
        if (peso + P[i] <= M) {
            X[i] = 1.0;
            peso = peso + P[i];
        } else {
            X[i] = (M - peso) / P[i];
            peso = M; // La mochila se llena
        }
        i = i + 1;
    }
    
    return X;
}

int main() {
    double M;
    int n;
    
    cout << "Introduce peso maximo de la mochila (M): ";
    cin >> M;
    
    cout << "Introduce numero de elementos (n): ";
    cin >> n;
    
    // Reserva de memoria dinámica (tamaño n + 1 para que empiecen en el índice 1)
    string* O = new string[n + 1];
    double* P = new double[n + 1];
    double* V = new double[n + 1];
    
    cout << "Introduce nombres de los objetos:\n";
    for (int i = 1; i <= n; i++) {
        cout << "nombre objeto " << i << ": ";
        cin >> O[i];
    }
    
    cout << "Introduce pesos:\n";
    for (int i = 1; i <= n; i++) {
        cout << "peso objeto " << i << ": ";
        cin >> P[i];
    }
    
    cout << "Introduce valores:\n";
    for (int i = 1; i <= n; i++) {
        cout << "valor objeto " << i << ": ";
        cin >> V[i];
    }
    
    cout << "\nObjetos, pesos y valores\n";
    for (int i = 1; i <= n; i++) {
        cout << "(" << O[i] << "," << P[i] << "," << V[i] << ")\n";
    }
    
    // Resolución del problema
    double* X = Mochila(M, O, P, V, n);
    
    // Mostrar salida idéntica al ejemplo
    cout << "\nObjetos introducidos:\n";
    cout << "====\n";
    double valor_mochila = 0.0;
    
    for (int i = 1; i <= n; i++) {
        if (X[i] > 0.0) {
            cout << "(" << O[i] << "," << P[i] << "," << V[i] << ")";
            if (X[i] < 1.0) {
                cout << " " << X[i]; // Muestra la fracción si no está completo
            }
            cout << "\n";
            valor_mochila += X[i] * V[i];
        }
    }
    
    cout << "Valor de la mochila: " << valor_mochila << "\n";
     
    // Es obligatorio liberar la memoria dinámica asignada con "new"
    delete[] O;
    delete[] P;
    delete[] V;
    delete[] X;

    
    system("pause");
    return 0;
}