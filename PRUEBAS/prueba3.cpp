#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

void binario(int n){
    if (n<2) {
        cout <<n;
    }else{
        binario(n/2);
        cout<<n%2;
    }
}

void binario_traza(int n,int i){
    if (n<2) {
        cout << i << ".- binario_traza("<<n<<") "<<endl;
        cout <<n;
    }else{
        cout << i << ".- binario_traza("<<n<<") "<<endl;
        binario_traza(n/2,i+1);
        cout<<n%2;

    }
}

int main(){
    int n;
    cout <<"Introduce el numero natural (incluido el 0): ";
    cin >>n;

    if (n<0){
        cout <<"ERROR: El numero "<<n <<" tiene que ser positivo";
        return -1;
    }

    binario(n);

    int i=1;
    cout <<"\n\nLa traza es "<<endl;
    binario_traza(n,i);
    
    return 0;
}
