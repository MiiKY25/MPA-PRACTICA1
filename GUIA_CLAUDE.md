# 📚 GUÍA COMPLETA: ESTRATEGIAS ALGORÍTMICAS
## Metodología de la Programación y Algoritmia

---

## 🎯 ÍNDICE DE ESTRATEGIAS

1. **Recursividad** - Función que se llama a sí misma
2. **Recursivo → Iterativo** - Eliminar recursión con pilas
3. **Divide y Vencerás** - Dividir problema, resolver subproblemas, combinar
4. **Voraz (Greedy)** - Elegir la mejor opción local en cada paso
5. **Programación Dinámica** - Resolver subproblemas y reutilizar soluciones
6. **Vuelta Atrás (Backtracking)** - Explorar todas las posibilidades, deshacer si no funciona

---

## 1️⃣ RECURSIVIDAD

### 📋 ¿Cuándo usar?
- El problema se puede dividir en casos más pequeños del mismo tipo
- Hay un caso base claro (condición de parada)
- Ejemplos: factorial, Fibonacci, binario, combinaciones

### 🔧 Estructura básica

```cpp
tipo funcion(parametros) {
    // 1. CASO BASE (condición de parada)
    if (condicion_simple) {
        return valor_directo;
    }
    
    // 2. CASO RECURSIVO
    // Llamada a sí misma con problema más pequeño
    return operacion_con(funcion(parametros_reducidos));
}
```

### ✅ Ejemplo: Número en binario

```cpp
void binario(int n) {
    // CASO BASE
    if (n == 0) {
        return;
    }
    
    // CASO RECURSIVO
    binario(n / 2);      // Primero resuelve el problema más pequeño
    cout << n % 2;       // Luego imprime el resto
}
```

### 📊 Tipos de recursividad

| Tipo | Descripción | Ejemplo |
|------|-------------|---------|
| **Simple** | Una sola llamada recursiva | `binario(n/2)` |
| **Múltiple** | Varias llamadas recursivas | `combinaciones(n-1,k-1) + combinaciones(n-1,k)` |
| **Final** | La última instrucción es la llamada | `return factorial(n-1)` |
| **No final** | Hay operaciones después de la llamada | `return n * factorial(n-1)` |

### 🎓 Reglas importantes de la profesora:
- Los vectores empiezan en posición 1 (no en 0)
- Siempre identificar caso base primero
- Para la traza: imprimir número de llamada + parámetros

---

## 2️⃣ RECURSIVO → ITERATIVO

### 📋 ¿Cuándo convertir?
- Para mejorar eficiencia (evitar overhead de llamadas)
- Cuando hay límite de pila (muchas llamadas recursivas)

### 🔧 Método de transformación

#### A) Recursividad FINAL → Bucle while

**Recursivo:**
```cpp
void funcion(int n) {
    if (n == 0) return;
    // operaciones
    funcion(n-1);  // Última instrucción
}
```

**Iterativo:**
```cpp
void funcion(int n) {
    while (n != 0) {
        // operaciones
        n = n - 1;
    }
}
```

#### B) Recursividad NO FINAL → Pila explícita

**Necesitas usar `#include <stack>`**

```cpp
#include <stack>

// Estructura para guardar el estado
struct Estado {
    int parametro1;
    int parametro2;
    // ... todos los parámetros que necesites
};

tipo funcion_iterativa(parametros) {
    stack<Estado> pila;
    
    // Apilar estado inicial
    Estado inicial;
    inicial.parametro1 = valor1;
    pila.push(inicial);
    
    while (!pila.empty()) {
        Estado actual = pila.top();
        pila.pop();
        
        // Procesar según el caso
        if (caso_base) {
            // resolver directamente
        } else {
            // Apilar nuevos estados (en orden inverso)
        }
    }
}
```

### ✅ Ejemplo completo: Potencia iterativa

```cpp
#include <stack>
using namespace std;

struct Estado {
    double x;
    int n;
    int fase;  // 0=antes recursión, 1=después
};

double potencia_iterativa(double x, int n) {
    stack<Estado> pila;
    double resultado = 1.0;
    
    Estado inicial = {x, n, 0};
    pila.push(inicial);
    
    while (!pila.empty()) {
        Estado actual = pila.top();
        pila.pop();
        
        if (actual.n == 0) {
            resultado *= 1;
        } else {
            if (actual.fase == 0) {
                // Antes de la recursión
                Estado nuevo = {actual.x, actual.n - 1, 0};
                pila.push(nuevo);
            }
            resultado *= actual.x;
        }
    }
    return resultado;
}
```

---

## 3️⃣ DIVIDE Y VENCERÁS

### 📋 ¿Cuándo usar?
- El problema se puede dividir en subproblemas independientes
- Los subproblemas son del mismo tipo que el original
- Las soluciones se pueden combinar
- Ejemplos: QuickSort, MergeSort, búsqueda binaria

### 🔧 Estructura básica (3 pasos)

```cpp
tipo DivideVenceras(problema) {
    // 1. CASO BASE (problema pequeño)
    if (tamaño_pequeño) {
        return solucion_directa;
    }
    
    // 2. DIVIDIR
    subproblema1 = dividir_parte1(problema);
    subproblema2 = dividir_parte2(problema);
    
    // 3. RESOLVER RECURSIVAMENTE (VENCER)
    solucion1 = DivideVenceras(subproblema1);
    solucion2 = DivideVenceras(subproblema2);
    
    // 4. COMBINAR
    return combinar(solucion1, solucion2);
}
```

### ✅ Ejemplo: QuickSort

```cpp
void quicksort(int* V, int izq, int der) {
    if (izq >= der) return;  // CASO BASE
    
    // DIVIDIR: Seleccionar pivote y particionar
    int p = seleccionar_pivote(V, izq, der);
    int pivote = V[p];
    
    int i = izq, d = der;
    while (i <= d) {
        while (V[i] < pivote) i++;
        while (V[d] > pivote) d--;
        if (i <= d) {
            intercambiar(V, i, d);
            i++;
            d--;
        }
    }
    
    // VENCER: Resolver subproblemas
    if (izq < d) quicksort(V, izq, d);
    if (i < der) quicksort(V, i, der);
}

// Selección de pivote: mediana de primero, último y centro
int seleccionar_pivote(int* V, int izq, int der) {
    int centro = (izq + der) / 2;
    
    // Ordenar los tres valores y tomar el del medio
    if (V[izq] > V[centro]) intercambiar(V, izq, centro);
    if (V[izq] > V[der]) intercambiar(V, izq, der);
    if (V[centro] > V[der]) intercambiar(V, centro, der);
    
    return centro;  // La mediana está en el centro
}
```

### 🎓 Características del QuickSort según tu profesora:
- Pivote = mediana de (primero, centro, último)
- Usar función `seleccionar_pivote`
- Indices: `izq` y `der`

---

## 4️⃣ VORAZ (GREEDY)

### 📋 ¿Cuándo usar?
- Puedes tomar decisiones locales óptimas
- No necesitas volver atrás
- La solución local lleva a la solución global
- Ejemplos: Mochila fraccionaria, cambio de monedas

### 🔧 Estructura básica

```cpp
Solucion Voraz(problema) {
    // 1. ORDENAR según criterio goloso
    ordenar_por_criterio(elementos);
    
    // 2. INICIALIZAR solución vacía
    Solucion sol = vacia;
    
    // 3. MIENTRAS haya elementos y sea factible
    for (cada elemento en orden) {
        if (añadir_elemento_es_factible(elemento, sol)) {
            añadir(elemento, sol);
        }
    }
    
    return sol;
}
```

### ✅ Ejemplo: Mochila fraccionaria

```cpp
double* Mochila(double M, string* O, double* P, double* V, int n) {
    double* X = new double[n+1];  // Solución
    
    // 1. ORDENAR por valor/peso (decreciente)
    OrdenarDecreciente_VP(O, V, P, n);
    
    // 2. INICIALIZAR
    for (int i = 1; i <= n; i++) {
        X[i] = 0.0;
    }
    
    double peso = 0.0;
    int i = 1;
    
    // 3. LLENAR MOCHILA (greedy loop)
    while (peso < M && i <= n) {
        if (peso + P[i] <= M) {
            // Cabe completo
            X[i] = 1.0;
            peso += P[i];
        } else {
            // Cabe fracción
            X[i] = (M - peso) / P[i];
            peso = M;
        }
        i++;
    }
    
    return X;
}
```

### 🔑 Criterios golosos comunes:

| Problema | Criterio de ordenación |
|----------|------------------------|
| Mochila fraccionaria | Valor/Peso (mayor primero) |
| Cambio de monedas | Denominación (mayor primero) |
| Planificación tareas | Deadline (menor primero) |
| Minimizar tiempo espera | Duración (menor primero) |

### 🎓 Reglas de tu profesora:
- Vectores empiezan en 1
- Usar `string` para nombres de objetos
- Hacer reserva dinámica: `new tipo[n+1]`

---

## 5️⃣ PROGRAMACIÓN DINÁMICA

### 📋 ¿Cuándo usar?
- Hay subproblemas que se repiten
- Se puede construir la solución de abajo hacia arriba
- Propiedad de subestructura óptima
- Ejemplos: Fibonacci, mochila 0/1, caminos en grafo

### 🔧 Estructura básica (2 enfoques)

#### A) Top-Down (Memoización)
```cpp
map<clave, valor> memo;  // Tabla de resultados

tipo resolver(parametros) {
    // 1. YA CALCULADO?
    if (memo.find(clave) != memo.end()) {
        return memo[clave];
    }
    
    // 2. CASO BASE
    if (base) {
        return valor_base;
    }
    
    // 3. CALCULAR y GUARDAR
    tipo resultado = combinar(
        resolver(subproblema1),
        resolver(subproblema2)
    );
    
    memo[clave] = resultado;
    return resultado;
}
```

#### B) Bottom-Up (Tabulación) ⭐ **Más común en tus prácticas**

```cpp
tipo resolver(parametros) {
    // 1. CREAR TABLA
    tipo** tabla = new tipo*[filas];
    for (int i = 0; i < filas; i++) {
        tabla[i] = new tipo[columnas];
    }
    
    // 2. INICIALIZAR CASOS BASE
    for (int i = 0; i < filas; i++) {
        tabla[i][0] = valor_base;
    }
    
    // 3. LLENAR TABLA (orden importante!)
    for (int i = 1; i < filas; i++) {
        for (int j = 1; j < columnas; j++) {
            tabla[i][j] = funcion_de(
                tabla[i-1][j],
                tabla[i][j-1],
                tabla[i-1][j-1]
            );
        }
    }
    
    // 4. SOLUCIÓN en última casilla
    tipo resultado = tabla[filas-1][columnas-1];
    
    // 5. LIBERAR MEMORIA
    for (int i = 0; i < filas; i++) {
        delete[] tabla[i];
    }
    delete[] tabla;
    
    return resultado;
}
```

### ✅ Ejemplo: Mochila 0/1 (discreta)

```cpp
int mochila01(int* P, int* V, int n, int M) {
    // Tabla[i][w] = valor máximo con objetos 1..i y peso máximo w
    int** tabla = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        tabla[i] = new int[M+1];
    }
    
    // Caso base: sin objetos o sin peso
    for (int i = 0; i <= n; i++) tabla[i][0] = 0;
    for (int w = 0; w <= M; w++) tabla[0][w] = 0;
    
    // Llenar tabla
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= M; w++) {
            // No incluir objeto i
            tabla[i][w] = tabla[i-1][w];
            
            // Incluir objeto i (si cabe)
            if (P[i] <= w) {
                int valor_con_i = V[i] + tabla[i-1][w - P[i]];
                if (valor_con_i > tabla[i][w]) {
                    tabla[i][w] = valor_con_i;
                }
            }
        }
    }
    
    int resultado = tabla[n][M];
    
    // Liberar memoria
    for (int i = 0; i <= n; i++) {
        delete[] tabla[i];
    }
    delete[] tabla;
    
    return resultado;
}
```

### 📌 Recuperar solución (qué objetos se eligen)

```cpp
void recuperar_objetos(int** tabla, int* P, int n, int M) {
    int w = M;
    
    for (int i = n; i >= 1; i--) {
        // ¿Se incluyó el objeto i?
        if (tabla[i][w] != tabla[i-1][w]) {
            cout << "Objeto " << i << " incluido" << endl;
            w = w - P[i];  // Reducir peso disponible
        }
    }
}
```

### 🎓 Complejidad según tu profesora:
- Debe ser mejor que O(max(n², M²))
- Típicamente O(n·M) es aceptable

---

## 6️⃣ VUELTA ATRÁS (BACKTRACKING)

### 📋 ¿Cuándo usar?
- Necesitas explorar TODAS las posibilidades
- Cada decisión es binaria o entre opciones limitadas
- Puedes descartar ramas que no cumplen restricciones
- Ejemplos: N-reinas, Sudoku, mochila 0/1, laberintos

### 🔧 Estructura básica

```cpp
// Variables globales para mejor solución
tipo* mejorSolucion;
valor mejorValor;

void backtracking(int nivel, tipo* solActual, valor valorActual,
                  restricciones, datos_problema) {
    
    // 1. CASO BASE: Hemos tomado todas las decisiones
    if (nivel > n) {
        // Verificar si es mejor que lo encontrado
        if (valorActual > mejorValor) {  // o < según el problema
            mejorValor = valorActual;
            copiar(mejorSolucion, solActual, n);
        }
        return;
    }
    
    // 2. PROBAR OPCIÓN 1 (ej: incluir elemento)
    if (es_factible_incluir(nivel, solActual, restricciones)) {
        solActual[nivel] = INCLUIR;
        backtracking(nivel+1, solActual, 
                    valorActual + valor[nivel],
                    nueva_restriccion,
                    datos_problema);
    }
    
    // 3. PROBAR OPCIÓN 2 (ej: no incluir elemento)
    solActual[nivel] = NO_INCLUIR;
    backtracking(nivel+1, solActual, 
                valorActual,
                restricciones,
                datos_problema);
}
```

### ✅ Ejemplo: Mochila 0/1 con backtracking

```cpp
// Variables globales
int* X_mejor;
double mejor_valor;
double mejor_peso;

void Maleta(int i, int* X_actual, double peso_actual, double valor_actual,
            double VMax, int n, double* P, double* V) {
    
    // CASO BASE: Procesamos todos los objetos
    if (i > n) {
        if (valor_actual > mejor_valor) {
            mejor_valor = valor_actual;
            mejor_peso = peso_actual;
            for (int j = 1; j <= n; j++) {
                X_mejor[j] = X_actual[j];
            }
        }
        return;
    }
    
    // OPCIÓN 1: INCLUIR objeto i (si cabe)
    if (peso_actual + P[i] <= VMax) {
        X_actual[i] = 1;
        Maleta(i+1, X_actual, peso_actual + P[i], 
               valor_actual + V[i], VMax, n, P, V);
    }
    
    // OPCIÓN 2: NO INCLUIR objeto i
    X_actual[i] = 0;
    Maleta(i+1, X_actual, peso_actual, valor_actual, 
           VMax, n, P, V);
}
```

### 🚀 Optimización: Poda (Pruning)

```cpp
// Añadir poda para evitar ramas inútiles
void MaletaPoda(int i, int* X_actual, double peso_actual, 
                double valor_actual, double cota_superior,
                double VMax, int n, double* P, double* V) {
    
    if (i > n) {
        if (valor_actual > mejor_valor) {
            mejor_valor = valor_actual;
            // ... guardar solución
        }
        return;
    }
    
    // 🔥 PODA: Si la cota superior no supera el mejor, no seguir
    if (cota_superior <= mejor_valor) {
        return;  // Podar esta rama
    }
    
    // ... resto del código igual
}
```

### 🎓 Patrón de tu profesora:
1. Variables globales para mejor solución
2. Usar `int* X` para arrays de 0/1
3. Referencias `&` para modificar mejor_valor
4. Vectores de 1 a n (no de 0 a n-1)

---

## 📊 COMPARATIVA RÁPIDA

| Estrategia | Explora todo | Óptimo garantizado | Complejidad típica |
|------------|--------------|--------------------|--------------------|
| **Recursividad** | Depende | Depende | Varía |
| **Divide y Vencerás** | Sí | Sí | O(n log n) |
| **Voraz** | No | No siempre | O(n log n) |
| **Prog. Dinámica** | Sí | Sí | O(n·m) |
| **Vuelta Atrás** | Sí | Sí | O(2ⁿ) |

---

## 🔧 PATRONES DE CÓDIGO COMUNES

### Reserva de memoria dinámica (vectores)
```cpp
// Vector de 1 a n
tipo* V = new tipo[n+1];

// Verificación
if (V == NULL) {
    cout << "Error al reservar memoria" << endl;
    return -1;
}

// Al final: liberar
delete[] V;
```

### Reserva de memoria (matrices)
```cpp
// Matriz de filas x columnas (índices 1..filas, 1..columnas)
tipo** M = new tipo*[filas+1];
for (int i = 1; i <= filas; i++) {
    M[i] = new tipo[columnas+1];
    if (M[i] == NULL) {
        cout << "Error" << endl;
        return -1;
    }
}

// Liberar
for (int i = 1; i <= filas; i++) {
    delete[] M[i];
}
delete[] M;
```

### Medición de tiempo
```cpp
#include <ctime>

clock_t tinicio, tfin;
double tiempo;

tinicio = clock();
// ... código a medir
tfin = clock();

tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
cout << "Tiempo: " << tiempo << " ms" << endl;
```

### Números aleatorios
```cpp
#include <cstdlib>
#include <ctime>

srand(semilla);  // o srand(time(NULL)) para semilla aleatoria

int aleatorio = rand() % (b - a + 1) + a;  // Entre a y b
```

---

## ✅ CHECKLIST ANTES DE ENTREGAR

- [ ] Solo uso `#include <iostream>` (+ stack si es recursivo→iterativo)
- [ ] Los vectores empiezan en posición 1, no en 0
- [ ] Hago reserva dinámica con `new tipo[n+1]`
- [ ] Libero memoria con `delete[]` al final
- [ ] Las funciones usan referencias (`&`) cuando modifican parámetros
- [ ] El código sigue las reglas de transformación de pseudocódigo
- [ ] He probado con los casos de ejemplo del PDF
- [ ] La complejidad es adecuada (O especificado en el enunciado)

---

## 🎯 DECISIÓN RÁPIDA: ¿QUÉ ESTRATEGIA USAR?

```
¿El problema pide ÓPTIMO?
│
├─ NO → Usa HEURÍSTICAS o lo que pida el enunciado
│
└─ SÍ → ¿Puedes dividir en subproblemas independientes?
    │
    ├─ SÍ → DIVIDE Y VENCERÁS
    │
    └─ NO → ¿Los subproblemas se repiten?
        │
        ├─ SÍ → PROGRAMACIÓN DINÁMICA
        │
        └─ NO → ¿Decisión local = óptimo global?
            │
            ├─ SÍ → VORAZ
            │
            └─ NO → VUELTA ATRÁS (o probar todas)
```

---

## 📚 RECURSOS ADICIONALES

### Para debuggear
- Imprime el número de llamada recursiva
- Imprime los parámetros en cada paso
- Usa `cout << "DEBUG: ..."` y elimínalos al final

### Para optimizar
- Vuelta atrás: añade podas
- Recursividad: considera memoización
- Greedy: ordena BIEN al principio

### Errores comunes
- ❌ Olvidar reservar n+1 elementos
- ❌ Acceder a posición 0 del vector
- ❌ No liberar memoria
- ❌ No inicializar variables globales
- ❌ Usar librerías no permitidas

---
