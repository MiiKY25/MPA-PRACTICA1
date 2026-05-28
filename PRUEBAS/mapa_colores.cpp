#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

void ImprimirSolucion(int N, int* colores) {
    cout << "SOLUCION:" << endl;
    for (int i = 1; i <= N; i++) {
        cout << "La region " << i << " se pinta con el color " << colores[i] << endl;
    }
    cout << endl;
}

bool siEsFactible(int nodo,int color,int N,int** grafo,int* colores){
    for (int i = 1; i < nodo; i++) {
        if (grafo[nodo][i]==1 && colores[i]==color){
            return false;
        }
    }
    return true;
}

void ColorearMapa(int nodo,int N,int C,int** grafo,int* colores){
    int color;

    if (nodo>N) {
        ImprimirSolucion(N,colores);
    }else{
        for (color= 1; color <= C; color++) {
            if (siEsFactible(nodo,color,N,grafo,colores)) {
                colores[nodo]=color;
                ColorearMapa(nodo+1,N,C,grafo,colores);
                colores[nodo]=0;
            }
        }
    }
    
}

int main(){
    int N,C;
    cout<<"Introduce el numero de regiones (N): ";
    cin>>N;
    cout<<"Introduce el numero de colores (C): ";
    cin>>C;

    int** grafo=new int*[N+1];
    for (int i = 1; i <= N; i++) {
        grafo[i] = new int[N+1];
    }

    cout<<"Introduce la matriz de adyacencia (0 o 1): "<<endl;
    for (int i = 1; i <=N; i++) {
        cout<<"Fila "<<i<<": ";
        for (int j = 1; j <=N; j++) {
            cin>>grafo[i][j];
        }
    }

    int* colores=new int[N+1];
    for (int i = 1; i <=N; i++) {
        colores[i]=0;
    }
    
    ColorearMapa(1,N,C,grafo,colores);
    
    //Liberar memoria
    for (int i = 1; i <=N; i++) {
        delete[] grafo[i];
    }

    delete[] grafo;
    delete[] colores;

    return 0;
}