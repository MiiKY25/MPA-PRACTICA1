Compilar un programa:
g++ examen.cpp -o examen.exe
Ejecutar programa 
examen.exe

1. RECURSIVIDAD
Concepto: Una función vaga que hace un trocito de trabajo y se llama a sí misma para pasarle el resto a su "clon", pero dándole un problema más pequeño. Obligatorio tener un Caso Base (el freno de mano para que termine) y el Caso Recursivo (la llamada al clon).

Codigo:
void recursiva(int n) {
    if (n == 0) return; // 1. CASO BASE (freno de mano, la función termina aquí)
    
    // 2. CASO RECURSIVO (el clon recibe un problema más pequeño)
    recursiva(n - 1);   
}

2. ITERATIVO
Concepto: Hacer el trabajo tú solo usando un bucle (while o for) en vez de invocar a clones. Repites el mismo bloque de código una y otra vez hasta que se cumple la condición de parada. Si necesitas imitar a una función recursiva, a veces te apoyas en una Pila (stack) para ir guardando los datos pendientes.

Código:

C++
void iterativa(int n) {
    while (n > 0) { // Bucle que repite el trabajo
        // Haces la faena
        n--; // Actualizas la variable para no atraparte en un bucle infinito
    }
}

3. PILAS (STACK) - El comodín para iterativos
Concepto: Estructura LIFO (el último en entrar es el primero en salir, como una pila de platos). Se usa para que el iterativo "recuerde" datos pendientes sin usar recursividad. Hay que incluir la librería #include <stack>.
Métodos: push(x) (mete un dato arriba), pop() (elimina el dato de arriba), top() (copia el dato de arriba sin borrarlo) y empty() (avisa si está vacía).

Código:

C++
#include <stack>
using namespace std;

void ejemploPila() {
    stack<int> p; // Creamos una pila de enteros
    p.push(5);    // Metemos el 5
    p.push(10);   // Metemos el 10 (ahora está arriba)
    
    while (!p.empty()) {       // Mientras queden platos...
        int x = p.top();       // 1. Miramos el de arriba (10)
        p.pop();               // 2. Lo quitamos de la pila
    }
}

4. DIVIDE Y VENCERÁS
Concepto: Partes un problema gigante por la mitad (ej. buscando un pivote en un vector), mandas clones recursivos a resolver cada trocito y listo. Es la técnica estrella para ordenar datos súper rápido (como el Quicksort).

Código (Plantilla Quicksort):

C++
void divideYVenceras(int* V, int izq, int der) {
    if (izq < der) { // Condición para seguir dividiendo
        int pivote = separar(V, izq, der);    // 1. DIVIDIR (buscamos el centro)
        
        // 2. VENCER (mandamos clones a cada mitad)
        divideYVenceras(V, izq, pivote);      // Mitad izquierda
        divideYVenceras(V, pivote + 1, der);  // Mitad derecha
    }
}

5. ALGORITMOS VORACES
Concepto: "Coger lo mejor en cada momento y tirar para adelante sin arrepentirse". Perfecto para problemas donde puedes fraccionar las cosas (ej. cortar un objeto si no cabe). Obligatorio ordenar los datos primero de "mejor a peor" (ej. por rentabilidad) y luego usar un bucle para llenar el límite.

Código (Plantilla Mochila Fraccionaria):

C++
void algoritmoVoraz(int M, int* P, int* V, int n) {
    ordenarPorRentabilidad(P, V, n); // 1. ORDENAR (El paso más importante)
    
    int peso_actual = 0;
    for (int i = 1; i <= n && peso_actual < M; i++) { // 2. BUCLE (Ir metiendo)
        if (peso_actual + P[i] <= M) {
            peso_actual += P[i]; // Si cabe, lo meto entero
        } else {
            peso_actual = M;     // Si no cabe, meto una fracción hasta llenar la mochila
        }
    }
}

6. PROGRAMACIÓN DINÁMICA
Concepto: "El empollón que se hace una tabla para no calcular lo mismo dos veces". Ideal para problemas donde no puedes fraccionar los objetos. Se basa en rellenar una matriz con dos bucles para ir guardando la mejor decisión paso a paso. La respuesta ganadora siempre estará acorralada en la última casilla de abajo a la derecha.

Código (Plantilla Mochila Discreta):

C++
void programacionDinamica(int M, int n, int* P, int* V, int** Matriz) {
    for (int i = 1; i <= n; i++) {           // Filas: Recorremos los objetos
        for (int j = 1; j <= M; j++) {       // Columnas: Probamos capacidades de la mochila
            if (P[i] <= j) { // Si el objeto cabe, nos quedamos con el máximo beneficio (meterlo o no meterlo)
                Matriz[i][j] = max(Matriz[i-1][j], V[i] + Matriz[i-1][j - P[i]]);
            } else {         // Si no cabe, copiamos literalmente la solución de la fila de arriba
                Matriz[i][j] = Matriz[i-1][j];
            }
        }
    }
}

7. VUELTA ATRÁS (BACKTRACKING)
Concepto: "El explorador de universos paralelos". Pruebas un camino (ej. meter un objeto en la maleta), llegas hasta el final, y luego vuelves atrás, lo sacas, y pruebas el camino alternativo (no meterlo). Explora absolutamente todas las combinaciones posibles para guardar la que tenga el récord de puntos.

Código (Plantilla Maleta):

C++
void vueltaAtras(int i, double peso_actual, double valor_actual, double M, int n) {
    if (i <= n) { // MIENTRAS QUEDEN OBJETOS POR MIRAR...
        
        // UNIVERSO A: Lo meto (Solo si físicamente cabe)
        if (peso_actual + P[i] <= M) {
            X_actual[i] = 1;
            vueltaAtras(i + 1, peso_actual + P[i], valor_actual + V[i], M, n);
        }
        
        // UNIVERSO B: No lo meto (¡Ojo! Se prueba SIEMPRE, sin importar si cabía)
        X_actual[i] = 0;
        vueltaAtras(i + 1, peso_actual, valor_actual, M, n);

    } else { // CASO BASE: Hemos llegado al final del camino
        if (valor_actual > mejor_valor) { // Si hemos batido nuestro récord histórico...
            mejor_valor = valor_actual;   // 1. Guardamos los nuevos puntos
            mejor_peso = peso_actual;     // 2. Guardamos el peso
            // 3. (Faltaría el bucle for para copiar X_actual dentro de X_mejor)
        }
    }
}