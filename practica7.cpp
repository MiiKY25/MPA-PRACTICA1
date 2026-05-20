#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/**
 * Práctica 7: Programación Dinámica - Mochila Discreta
 * Resuelve el problema y determina los objetos incluidos.
 */
int main() {
    int capacidad, n;

    // Entrada de datos
    cout << "Introduce el peso maximo de la mochila: ";
    cin >> capacidad;
    cout << "Introduce el numero total de objetos: ";
    cin >> n;

    vector<int> pesos(n + 1);
    vector<int> valores(n + 1);

    for (int i = 1; i <= n; ++i) {
        cout << "Introduce peso y valor para el objeto " << i << ": ";
        cin >> pesos[i] >> valores[i];
    }

    // Tabla de programación dinámica (n+1) x (capacidad+1)
    // dp[i][w] almacena el valor maximo con i objetos y capacidad w
    vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));

    // Llenado de la tabla
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacidad; ++w) {
            if (pesos[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], valores[i] + dp[i - 1][w - pesos[i]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // El valor maximo se encuentra en dp[n][capacidad]
    int valorMaximo = dp[n][capacidad];
    cout << "\nValor maximo en la mochila: " << valorMaximo << endl;

    // Reconstrucción de la solución (obtener objetos)
    stack<int> objetos;
    int w = capacidad;
    for (int i = n; i > 0; --i) {
        // Si el valor cambia respecto a la fila anterior, el objeto fue incluido
        if (dp[i][w] != dp[i - 1][w]) {
            objetos.push(i);
            w -= pesos[i];
        }
    }

    // Impresión de objetos ordenados
    cout << "Objetos introducidos: ";
    while (!objetos.empty()) {
        cout << objetos.top() << (objetos.size() > 1 ? ", " : "");
        objetos.pop();
    }
    cout << endl;

    return 0;
}