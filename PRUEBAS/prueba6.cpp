#include <iostream>
#include <cstdlib>
#include <stack>
#include <ctime>

using namespace std;

void OrdenarDecreciente_VP(string* O,double* P,double* V,int n){
    double auxV, auxP;
    string auxO;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            
            // Comparamos la rentabilidad (Valor / Peso)
            if ((V[j] / P[j]) < (V[j+1] / P[j+1])) {
                auxV=V[j];
                V[j]=V[j+1];
                V[j+1]=auxV;

                auxP=P[j];
                P[j]=P[j+1];
                P[j+1]=auxP;

                auxO=O[j];
                O[j]=O[j+1];
                O[j+1]=auxO;
            }
        }
    }
}

double* Mochila(double M,string* O,double* P,double* V,int n){
    double* X=new double[n+1];
    double peso;
    int i;

    for (int j = 1; j <= n; j++) {
        X[j] = 0.0;
    }
    OrdenarDecreciente_VP(O,P,V,n);
    i=1;
    peso=0;
    while (peso<M && i<=n) {
        if (peso + P[i]<=M) {
            X[i]=1;
            peso=peso+P[i];
        }else{
            X[i]=(M-peso)/P[i];
            peso=M;
        }
        i=i+1;
    }
    return X;
}



int main(){
    double M;
    int n;
    cout<<"Introduce el peso maximo de la mochila (M): ";
    cin >>M;
    cout<<"Introduce el numero de elementos (n): ";
    cin >>n;

    string* O=new string[n+1];
    double* P=new double[n+1];
    double* V=new double[n+1];

    cout<<"Introduce los nombres de los objetos: "<<endl;

    for (int i = 1; i <=n; i++) {
        cout<<"\t Nombre objeto "<<i<<": ";
        cin >> O[i];
    }

    cout<<"Introduce los pesos: "<<endl;
    
    for (int i = 1; i <=n; i++) {
        cout<<"\t Peso objeto "<<i<<": ";
        cin >> P[i];
    }

    cout<<"Introduce los valores: "<<endl;

    for (int i = 1; i <=n; i++) {
        cout<<"\t Valor objeto "<<i<<": ";
        cin >> V[i];
    }

    cout<<endl;
    cout<<"Objetos, pesos y valores "<<endl;
    cout<<"========================================== "<<endl;
    for (int i = 1; i <=n; i++) {
         cout<<"("<<O[i]<<","<<P[i]<<","<<V[i]<<")"<<endl;
    }

    double* X=Mochila(M,O,P,V,n);

    cout<<endl;
    cout<<"Objetos introducidos:"<<endl;
    cout<<"========================================== "<<endl;
    
    double valor_total = 0.0;

    for (int i = 1; i <= n; i++) {
        if (X[i] > 0) { // Si hemos metido algo de este objeto
            cout << "(" << O[i] << "," << P[i] << "," << V[i] << ")";
            
            // Si es una fracción, la imprimimos al lado
            if (X[i] < 1.0) {
                cout << " " << X[i];
            }
            cout << endl;
            
            // Sumamos la parte proporcional del valor a nuestra mochila
            valor_total = valor_total + (X[i] * V[i]);
        }
    }

    cout << "\nValor de la mochila: " << valor_total << endl;

    delete[] O;
    delete[] P;
    delete[] V;
    delete[] X;
    return 0;
}