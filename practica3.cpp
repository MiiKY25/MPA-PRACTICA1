#include <iostream>
#include <stdlib.h>

using namespace std;

//funcion binario
void binario(int n) {

    string resultado = "";   // Aquí se van acumulando los restos
    int cociente = n;

    while (cociente != 0) {
        int resto = cociente % 2;
        resultado = to_string(resto) + resultado;   // Guarda el resto al final del string
        cociente = cociente / 2;         // El nuevo cociente para la siguiente iteración
    }

    cout << "El numero en binario es: "<< endl;
    cout <<resultado<< endl;
}

void binario_traza(int n) {
    string resultado = "";
    int cociente = n;
    int contador = 1;   // Contador de llamadas

    cout << "La traza es:" << endl;

    while (cociente != 0) {
        int resto = cociente % 2;
        resultado = to_string(resto) + resultado;

        // Imprime la traza de esta "llamada" antes de actualizar el cociente
        cout << contador << ".- binario_traza(" << cociente << ")" << endl;
        contador++;

        cociente = cociente / 2;
    }

    // Imprime el resultado binario al final, igual que en la figura 2
    cout << resultado << endl;
}

int main() {
    int n; // Numero a representar

    //Pedir el numero
    cout << "Introduce numero natural (incluido el 0) ";
    cin >> n;

    binario(n);
    binario_traza(n);

    system("pause");
    return 0;
}