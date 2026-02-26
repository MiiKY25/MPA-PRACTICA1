#include <iostream>
#include <stdlib.h>

using namespace std;

int Contar(int *V, int n, int x) {
    int i, nveces; // Declaramos las variables locales
    
    nveces = 0; // Inicializamos el contador a 0
    
    // Bucle para recorrer el vector desde 1 hasta n
    for (i = 1; i <= n; i++) {
        // Si el elemento actual es igual al valor que buscamos (x)
        if (V[i] == x) {
            nveces = nveces + 1; // Sumamos 1 al contador
        }
    }
    
    return nveces; // Devolvemos el resultado final
}

int main() { 
    int x; // Valor a buscar
    int n; // Tamaño del vector

    //Pedir los valores x y n
    cout << "Introduce valor a buscar (x): ";
    cin >> x;

    cout << "Introduce n.elementos del vector (n): ";
    cin >> n;
    
    //Crear los vectores -- El * es para decirle que es un puntero
    int *vpeor;
    int *vmejor;
    int *vcualquiera;

    // Reservar memoria dinámica para n+1 elementos
    vpeor = new int[n + 1];
    vmejor = new int[n + 1];
    vcualquiera = new int[n + 1];

    // Comprobar si la memoria se reservó correctamente
    if (vpeor == NULL || vmejor == NULL || vcualquiera == NULL) {
        cout << "Error al reservar memoria" << endl;
        return -1; 
    }

    //Rellenar los vectores
    int i;

    //----VPEOR----
    for (i = 1; i <= n; i++) {
        vpeor[i] = x;
    }

    // Imprimir el vector vpeor
    cout << "\nVector vpeor:" << endl;
    for (i = 1; i <= n; i++) {
        cout << vpeor[i] << " "; // Imprime cada número con un espacio 
    }
    cout << endl; // Salto de línea al terminar de imprimir el vector

    //---VMEJOR----
    for (i = 1; i <= n; i++) {
        // Al sumarle 'i' a 'x', nos aseguramos de que sean números diferentes a 'x'
        vmejor[i] = x + i; 
    }

    // Imprimir el vector vmejor
    cout << "\nVector vmejor:" << endl;
    for (i = 1; i <= n; i++) {
        cout << vmejor[i] << " "; // Imprime cada número con un espacio 
    }
    cout << endl; // Salto de línea al terminar de imprimir el vector

    // --- CASO CUALQUIERA ---
    // Mezcla: la mitad de elementos iguales a x y el resto distintos
    for (i = 1; i <= n; i++) {
        if (i <= n / 2) {
            vcualquiera[i] = x; // Primera mitad igual a x
        } else {
            vcualquiera[i] = x + i; // Segunda mitad diferente de x
        }
    }

    // Imprimir el vector vcualquiera
    cout << "\nVector vcualquiera:" << endl;
    for (i = 1; i <= n; i++) {
        cout << vcualquiera[i] << " ";
    }
    cout << endl << endl;

    cout << "CASO PEOR" << endl;
    // Llamamos a la función pasándole el vector vpeor, el tamaño n y el valor x
    cout << "Numero veces: " << Contar(vpeor, n, x) << endl << endl;

    cout << "CASO MEJOR" << endl;
    // Hacemos lo mismo pero con el vector vmejor
    cout << "Numero veces: " << Contar(vmejor, n, x) << endl << endl;

    cout << "OTRO CASO" << endl;
    // Y por último con el vector vcualquiera
    cout << "Numero veces: " << Contar(vcualquiera, n, x) << endl << endl;

    system("pause");
    return 0;
}