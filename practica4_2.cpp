#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

int calcular2(int x,int y){
    if (x<=4){
        return x + y;
    }
    else{
        x=x-4;
        y=y/3;
        return calcular2(x,y) + x*y;
    }
}

int calcular2_iterativa(int x,int y){
    stack<int> pilax;
    stack<int> pilay;

    while (x>4) {
        x=x-4;
        y=y/3;

        pilax.push(x);
        pilay.push(y);
    }

    int resultado = x + y;

    while (!pilax.empty()) {
        int x_actual = pilax.top();
        int y_actual = pilay.top();

        pilax.pop();
        pilay.pop();
        resultado = resultado + (x_actual * y_actual); 
    }
    
    return resultado;
}

int main(){
    int x,y;

    cout << "Introduce el numero x ";
    cin >> x;
    cout << "Introduce el numero y ";
    cin >> y;

    cout << "El resultado recursivo es "<< calcular2(x,y) <<endl;
    cout << "El resultado iterativo es "<< calcular2_iterativa(x,y) <<endl;

    system("pause");
    return 0;

}