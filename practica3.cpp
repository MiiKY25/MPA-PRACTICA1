#include <iostream>
#include <stdlib.h>

using namespace std;

//funcion binario recursiva
void binario(int n) {

    if(n < 0){
        cout << "Error: El numero debe ser mayor o igual a 0." << endl;
        return; //Para salir de la funcion
    }

    // Si el número es 0 o 1, su binario es simplemente él mismo (0 o 1).
    if (n < 2) {
        cout << n;
    }else {
        // Primero, nos llamamos a nosotros mismos con la mitad del número.
        // Esto hace que el programa "baje" hasta llegar al caso base.
        binario(n/2);

        // Cuando las llamadas anteriores terminan, el programa "sube" 
        // imprime el resto de la división por 2. ¡Esto los imprime en el orden correcto!
        cout << n % 2;
    }
}

// Le pasamos 'contador' con un valor por defecto de 1. 
// Así, la primera vez que la llames desde el main() no hace falta que le pases el 1.
void binario_traza(int n, int contador = 1) {
    
    // Control de errores (por si meten un negativo)
    if (n < 0) return; 

    // 1. Imprimimos la traza NADA MÁS ENTRAR. (Esto ocurre al "bajar" en la recursividad)
    cout << contador << ".- binario_traza(" << n << ")" << endl;

    // 2. CASO BASE
    if (n < 2) {
        cout << n;
    } 
    // 3. CASO RECURSIVO
    else {
        // Llamamos a la función con la mitad de 'n' y le SUMAMOS 1 al contador
        binario_traza(n / 2, contador + 1);
        
        // Imprimimos el resto. (Esto ocurre al "subir" de vuelta de la recursividad)
        cout << n % 2;
    }
}

//funcion binario iterativo
/*void binario(int n) {

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
}*/

int main() {
    int n; // Numero a representar

    //Pedir el numero
    cout << "Introduce numero natural (incluido el 0) ";
    cin >> n;

    // Imprimir el texto ANTES de llamar a la función
    cout << "\nEl numero en binario es:\n";
    binario(n); // Esto imprimirá "1100" (si metes 12)
    cout << "\n\n"; // Saltos de línea al terminar
    
    // Llamada a la función con traza
    if (n >= 0) { // Solo imprimimos el texto si el número es válido
        cout << "La traza es:\n";
        binario_traza(n); 
        cout << "\n\n";
    }

    system("pause");
    return 0;
}