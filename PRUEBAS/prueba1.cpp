#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

int contar(int* V,int n,int x){
    int i,nveces;
    nveces=0;

    for (i = 1; i <= n; i++){
        if (V[i]==x){
            nveces=nveces+1;
        }
    }
    return nveces;
}

int main(){
    int x,n;
    cout << "Introduce el valor a buscar (x): " ;
    cin >> x;

    cout << "Introduce el tamanio del vector (n): ";
    cin >> n;

    int* Vpeor = new int[n+1];
    int* Vmejor = new int[n+1];
    int* Vcualquiera = new int[n+1];

    // Comprobación obligatoria según la Práctica 1
    if (Vpeor == NULL || Vmejor == NULL || Vcualquiera == NULL) {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }

    //Vpeor
    for (int i = 1; i <=n; i++) {
        Vpeor[i]=x;
    }

    cout << "\nVector Vpeor: " <<endl;
    for (int i = 1; i <=n; i++) {
        cout << Vpeor[i] << " ";
    }
    cout <<endl;

    //Vmejor
    for (int i = 1; i <=n; i++) {
        Vmejor[i]=x+i;
    }

    cout << "\nVector Vmejor: " <<endl;
    for (int i = 1; i <=n; i++) {
        cout << Vmejor[i] << " ";
    }
     cout <<endl;

    //Vcualquiera
    for (int i = 1; i <=n; i++) {
        if (i<=n/2){
            Vcualquiera[i]=x;
        }else{
            Vcualquiera[i]=x+i;
        }
    }

    cout << "\nVector Vcualquiera: " <<endl;
    for (int i = 1; i <=n; i++) {
        cout << Vcualquiera[i] << " ";
    }

    cout <<endl;

    cout << "\nCASO PEOR: " <<endl;
    cout << "NUMERO VECES: "<< contar(Vpeor,n,x)<<endl;

    cout << "\nCASO MEJOR: " <<endl;
    cout << "NUMERO VECES: "<< contar(Vmejor,n,x)<<endl;

    cout << "\nCASO CUALQUIERA: " <<endl;
    cout << "NUMERO VECES: "<< contar(Vcualquiera,n,x)<<endl;

    // Liberación de memoria
    delete[] Vpeor;
    delete[] Vmejor;
    delete[] Vcualquiera;

    //system("pause");
    return 0;
}