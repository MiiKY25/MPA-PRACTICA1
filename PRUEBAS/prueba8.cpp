#include <iostream>
#include <cstdlib>
#include <stack>
#include <ctime>

using namespace std;

void Maleta(int i, double peso_actual, double valor_actual, double VMax, int n, double* P, double* V, int* X_actual, int* X_mejor, double &mejor_valor, double &mejor_peso) {
    if (i<=n) {
        if (peso_actual + P[i]<=VMax) {
            X_actual[i]=1; //Si que lo meto
            Maleta(i+1,peso_actual+P[i],valor_actual+V[i],VMax,n,P,V,X_actual,X_mejor,mejor_valor,mejor_peso);

        }
        X_actual[i]=0; //No lo meto
        Maleta(i+1,peso_actual,valor_actual,VMax,n,P,V,X_actual,X_mejor,mejor_valor,mejor_peso);

    }else{
        // 1. Comprobamos si el botín de este camino supera nuestro récord histórico
        if (valor_actual>mejor_valor) {

            // 2. Actualizamos los récords
            mejor_valor=valor_actual;
            mejor_peso=peso_actual;

            // 3. Hacemos una copia de seguridad de la combinación ganadora
            for (int j = 1; j <=n; j++) {
                X_mejor[j]=X_actual[j];
            }
        }
        return;
    }
}

int main(){
    double VMax = 10.0;
    int n;
   
    cout <<"Introduce el numero total de objetos: ";
    cin >>n;
 
    double* P=new double[n+1];
    double* V=new double[n+1];

    cout <<"PESOS:"<<endl;
    for (int i = 1; i <=n; i++) {
        cout <<"\tObjeto "<<i<<": ";
        cin>>P[i];
    }

    cout <<endl;
    cout <<"VALORES:"<<endl;
    for (int i = 1; i <=n; i++) {
        cout <<"\tObjeto "<<i<<": ";
        cin>>V[i];
    }

    cout <<endl;
    cout <<"OBJETOS INICIALES: "<<n<<endl;
    for (int i = 1; i <=n; i++) {
        cout <<"\t"<<i<<". Peso: "<<P[i]<<"\tValor: "<<V[i]<<endl;
    }
    cout <<endl;
    cout <<"SOLUCION"<<endl;
    cout <<"---------------------"<<endl;
    cout <<endl;

    // Creamos los vectores de control para las combinaciones
    int* X_actual = new int[n + 1];
    int* X_mejor = new int[n + 1];

    // Los inicializamos a 0 (vacíos)
    for (int j = 1; j <= n; j++) {
        X_actual[j] = 0;
        X_mejor[j] = 0;
    }

    // Creamos las variables para guardar el récord definitivo
    double mejor_valor = 0.0;
    double mejor_peso = 0.0;

    // Llamada inicial al algoritmo de Vuelta Atrás
    Maleta(1, 0.0, 0.0, VMax, n, P, V, X_actual, X_mejor, mejor_valor, mejor_peso);

    cout <<"OBJETOS SELECCIONADOS:"<<endl;
    for (int i = 1; i <=n; i++) {
        if (X_mejor[i]==1) {
            cout <<"\t"<<i<<". Peso: "<<P[i]<<"\tValor: "<<V[i]<<endl;    
        }
    }
    
    cout << "\n\tPeso total: " << mejor_peso << endl;
    cout << "\tValor total: " << mejor_valor << endl;

    cout <<endl;
    cout <<"OBJETOS QUE QUEDAN FUERA: ";

    for (int i = 1; i <=n; i++) {
        if (X_mejor[i]==0) {
            cout<<" "<<i;
        }
        
    }

    delete[] X_actual;
    delete[] X_mejor;
    delete[] P;
    delete[] V;

    return 0;

}