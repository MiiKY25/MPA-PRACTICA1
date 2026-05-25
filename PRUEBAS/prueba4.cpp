#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

double calcular1(double x,int n){
    double r;
    if (n==0) {
        r=1;
    }else{
        if (n%2!=0){
            r=x*calcular1(x,n-1);
        }else{
            r=calcular1(x,n/2);
            r=r*r;
        }
    }
    return r;
}

double calcular1_iterativa(double x, int n) {
    stack<int> pila;
    double r;
    while (n>0){
        pila.push(n);
        if (n%2!=0){
            n=n-1;
        }else{
            n=n/2;
        }        
    }

    r=1;
    while (!pila.empty()) {
        n = pila.top();
        pila.pop();

        if (n%2!=0){
            r=x*r;
        }else{
            r=r*r;
        }        
    }
    return r;
}

int calcular2(int x,int y){
    if (x<=4){
        return x + y;
    }else{
        x=x-4;
        y=y/3;
        return calcular2(x,y) + x*y;
    }
} 

int calcular2_iterativa(int x,int y){
    stack<int> pilax; //Se crean las pilas de las varibles que cambian
    stack<int> pilay;
    int r; //Se crea la variable para almacenar el resultado

    while (x>4){  //Se cambia la condicion al contrario que en la recursiva 
        pilax.push(x); //Se almacenan los valores de cada variable
        pilay.push(y);
        x=x-4; //Se hacen los cambios de variables de la funcion iterativa(Aqui no se cambia nada)
        y=y/3;
    }

    r=x+y; //Se pone lo mismo que cuando ya para la forma recursiva (si se cumle el if)

    while (!pilax.empty()) { //Se comprueba que no este vacia la pila
        x=pilax.top(); //Se coge el valor mas alto de la pila
        pilax.pop(); //Se borra porque ya tenemos su valor almacenado 
        y=pilay.top();
        pilay.pop();

        r=r + x*y; //Se hace la operacion que se hacia en la forma recursiva
    }
    return r;
    
}

int main(){
    cout <<"-----------ACTIVIDAD 1 ---------------"<<endl;
    cout <<endl;

    double x1;
    int n;
    cout <<"Introduce el numero x: ";
    cin >>x1;

    cout <<"Introduce el numero n: ";
    cin >>n;

    if (n<0){
        cout <<"ERROR: El numero "<<n<<" no puede ser negativo.";
        return -1;
    }

    cout <<"Resultado de Calcular1 (RECURSIVO): "<<calcular1(x1,n)<<endl;
    cout <<"Resultado de Calcular1 (ITERATIVO): "<<calcular1_iterativa(x1,n);
    
      cout <<endl;
    cout <<"-----------ACTIVIDAD 2 ---------------"<<endl;
    cout <<endl;

    int x2;
    int y;
    cout <<"Introduce el numero x: ";
    cin >>x2;

    cout <<"Introduce el numero y: ";
    cin >>y;

    cout <<"Resultado de Calcular2 (RECURSIVO): "<<calcular2(x2,y)<<endl;
    cout <<"Resultado de Calcular2 (ITERATIVO): "<<calcular2_iterativa(x2,n);

    return 0;
}


//1.2
/*función calcular1_iterativo(x:real, n:natural U {0}):real
    r: real
    p: pila de enteros

    // 1. FASE DE BAJADA (Guardamos el estado)
    mientras n > 0 hacer
        apilar(p, n)
        si impar(n)
            n <- n - 1
        si no
            n <- n / 2
        fsi
    fmientras

    // 2. RESOLVER CASO BASE
    r <- 1

    // 3. FASE DE SUBIDA (Recuperamos estado y operamos)
    mientras no_vacia(p) hacer
        n <- desapilar(p) // Sacamos el tope y lo borramos de la pila
        si impar(n)
            r <- x * r
        si no
            r <- r * r
        fsi
    fmientras

    devolver r
ffunción*/

//2.2
/*
función calcular2_iterativo(x:entero, y:entero):entero
    r: entero
    px: pila de enteros
    py: pila de enteros

    // 1. FASE DE BAJADA (Guardamos el estado de las dos variables)
    mientras x > 4 hacer
        apilar(px, x)
        apilar(py, y)
        x <- x - 4
        y <- y / 3
    fmientras

    // 2. RESOLVER CASO BASE
    r <- x + y

    // 3. FASE DE SUBIDA (Recuperamos el estado y operamos)
    mientras no_vacia(px) hacer
        x <- desapilar(px)
        y <- desapilar(py)
        
        r <- r + (x * y)
    fmientras

    devolver r
ffunción
*/