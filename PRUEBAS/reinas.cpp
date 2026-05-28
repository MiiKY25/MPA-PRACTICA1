#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

void imprimirSolucion(int N,int** Tablero){
    cout <<"Solucion Tablero: "<<endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <=N; j++) {
            if (Tablero[i][j]==1) {
                cout <<"En la columna "<<j<<" fila "<<i<<" hay una dama"<<endl;
            }
        }
    }
}

void imprimirSolucion2(int N,int** Tablero){
    cout <<"Solucion Tablero: "<<endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <=N; j++) {
            if (Tablero[i][j]==1) {
                cout <<"X\t";
            }else{
                cout <<"0\t";
            }
        }
        cout <<"\n";
    }
    cout<<endl;
}

bool esFactible(int fila,int col,int N,int** Tablero){
    //Solo miramos las filas y columnas por encima de la actual,porque las posteriores no puede haber nunca nada
    //Por eso en la condicion del bucle se pone solo < y no el <=,para que no lea la fila actual
    for (int i = 1; i <fila; i++){
        for (int j = 1; j <=N; j++) {
            //Se comprueba si hay alguna reina y si esta en la misma columna o esta en su diagonal
            if (Tablero[i][j]==1 && (j==col || abs(fila - i) == abs(col - j))) {
                return false;
            }
        }
        
    }

    return true;
}

void ResolverNReinas(int fila,int N,int** Tablero){
    int col;

    if (fila>N) {
        imprimirSolucion(N,Tablero);
        imprimirSolucion2(N,Tablero);
    }else {
        for (col = 1; col <=N; col++) {
            if (esFactible(fila,col,N,Tablero)){
                Tablero[fila][col]=1;
                ResolverNReinas(fila+1,N,Tablero);
                Tablero[fila][col]=0;
            }
        }
    }
}

int main(){
    int N;
    cout <<"Introduce el tamanio del tablero N: ";
    cin >>N;

    int** Tablero=new int*[N+1];
    for (int i = 1; i <=N; i++) {
        Tablero[i]=new int[N+1];

        //Inicializar el tablero vacio (Poner 0)
        for (int j = 1; j <=N; j++) {
            Tablero[i][j]=0;
        }
        
    }

    ResolverNReinas(1,N,Tablero);

    //Borrar la matriz
    for (int i = 1; i <=N; i++) {
        delete[] Tablero[i];
    }
    
    delete[] Tablero;

    return 0;
}