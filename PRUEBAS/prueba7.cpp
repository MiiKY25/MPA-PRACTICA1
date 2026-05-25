#include <iostream>
#include <cstdlib>
#include <stack>
#include <ctime>

using namespace std;


int MochilaDiscreta(int M, int* P, int* V, int n) {
    // 1. Reservar memoria para la matriz [n+1][M+1]
    int** Matriz = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        Matriz[i] = new int[M + 1];
    }

    // 2. Rellenar la matriz de Programación Dinámica
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            // Caso base: fila 0 (0 objetos) y columna 0 (mochila de capacidad 0)
            if (i == 0 || j == 0) {
                Matriz[i][j] = 0;
            }
            // Si el objeto actual cabe en la mochila de capacidad 'j'
            else if (P[i] <= j) {
                // Elegimos el máximo entre no meterlo o meterlo
                Matriz[i][j] = max(Matriz[i - 1][j], V[i] + Matriz[i - 1][j - P[i]]);
            }
            // Si el objeto no cabe
            else {
                // Heredamos el valor óptimo sin este objeto
                Matriz[i][j] = Matriz[i - 1][j];
            }
        }
    }

    // 3. El resultado final (valor máximo) está en la esquina inferior derecha
    int valor_maximo = Matriz[n][M];

    // 4. Liberar la memoria de la matriz
    for (int i = 0; i <= n; i++) {
        delete[] Matriz[i];
    }
    delete[] Matriz;

    return valor_maximo;
}

int main(){
    int M,n;
    cout<<"Introduce el peso maximo de la mochila (M): ";
    cin >>M;
    cout<<"Introduce el numero de elementos (n): ";
    cin >>n;

    int* P=new int[n+1];
    int* V=new int[n+1];

    cout << "Introduce los pesos y valores de cada objeto: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << "\t Objeto " << i << " - Peso: ";
        cin >> P[i];
        cout << "\t Objeto " << i << " - Valor: ";
        cin >> V[i];
    }

    cout<<endl;
    cout<<"Pesos y valores "<<endl;
    cout<<"========================================== "<<endl;
    for (int i = 1; i <=n; i++) {
         cout<<"("<<P[i]<<","<<V[i]<<")"<<endl;
    }
    
    cout<<"El valor maximo es: "<<MochilaDiscreta(M,P,V,n)<<endl;
    
    delete[] P;
    delete[] V;
  
    return 0;
}