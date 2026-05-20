#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

double calcular1(double x,int n){
    double r;
    if (n==0){
        r=1;
    }else{
        if(n%2!=0){
            r=x*calcular1(x,n-1);
        }else{
            r=calcular1(x,n/2);
            r=r*r;
        }
    }
    return r;
}

double calcular1_iterativa(double x, int n) {
    stack<int> pila; // Creamos nuestra "pila de platos" vacía
    double r;

    // FASE 1: BAJAR Y APILAR
    // En lugar de llamar a la función de nuevo, guardamos la 'n' en la pila 
    // y la vamos reduciendo hasta llegar a 0.
    while (n > 0) {
        pila.push(n); // Metemos el número actual arriba de la pila
        
        if (n % 2 != 0) { // Si es impar
            n = n - 1;
        } else {          // Si es par
            n = n / 2;
        }
    }

    // RESOLVER EL CASO BASE
    // Cuando el bucle anterior termina, n es 0. 
    // Según el pseudocódigo, si n=0, r=1.
    r = 1;

    // FASE 2: SUBIR Y CALCULAR
    // Ahora vamos sacando los números de la pila uno a uno (del último al primero)
    // y aplicamos las multiplicaciones que se quedaron "pendientes".
    while (!pila.empty()) { // Mientras la pila NO esté vacía
        
        int n_actual = pila.top(); // Miramos qué número hay arriba
        pila.pop();                // Lo sacamos de la pila y lo destruimos

        if (n_actual % 2 != 0) { // Si el número que sacamos era impar
            r = x * r;
        } else {                 // Si el número que sacamos era par
            r = r * r;
        }
    }

    return r; // Devolvemos el resultado final
}

int main(){
    double x;
    int n;

    cout << "Introduce el numero x: ";
    cin >> x;
    cout << "Introduce el numero n: ";
    cin >> n;

    if(n<0){
        cout << "El numero n "<<n<<" no puede ser negativo" << endl;
    }else{
        double resultado_recursivo = calcular1(x, n);
        double resultado_iterativo = calcular1_iterativa(x, n);
        
        cout << "\nRESULTADOS:" << endl;
        cout << "Version Recursiva: " << resultado_recursivo << endl;
        cout << "Version Iterativa: " << resultado_iterativo << endl;
    }
    
    system("pause");
    return 0;
}