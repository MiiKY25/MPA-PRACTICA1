#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

void Imprimir(int n,int** tablero){
    cout<<">>> SOLUCION ENCONTRADA <<<"<<endl;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=n; j++) {
            if (tablero[i][j]==1) {
                 cout<<"En la fila "<<i<<", columna "<<j<<" hay un Canciller"<<endl;
            }
        }
    }
}

bool factible(int fila,int col,int n,int** tablero){
    for (int i = 1; i <fila; i++) {
        for (int j = 1; j <=n; j++) {
            if (tablero[i][j]==1) {
                if (col==j ||((abs(fila-i)==2 && abs(col-j)==1) ||(abs(fila-i)==1 && abs(col-j)==2))){
                    return false;
                }
            }
        }
    }
    return true;
}

bool NCancilleres(int fila,int n,int** tablero){
    int col;
    bool exito;

    if (fila>n) {
        Imprimir(n,tablero);
        return true;
    }else{
        exito=false;
        col=1;
        while (col<=n && !exito) {
            if (factible(fila,col,n,tablero)) {
                tablero[fila][col]=1;
                exito=NCancilleres(fila+1,n,tablero);
                if (!exito) {
                    tablero[fila][col]=0;
                }
            }
            col++;
        }
        return exito;
    }
}

int main(){
    int n;
    cout<<"Introduce el tamanio del tablero (n): ";
    cin>>n;

    int** tablero=new int*[n+1];
    for (int i = 1; i <=n; i++) {
        tablero[i]=new int[n+1];
        for (int j = 1; j <=n; j++) {
            tablero[i][j]=0;
        }
    }
    
    clock_t t_inicio,t_fin;
    t_inicio=clock();
    bool solucion=NCancilleres(1,n,tablero);
    t_fin=clock();
    float tiempo=(float)(t_fin-t_inicio)/CLOCKS_PER_SEC * 1000;
    cout<<"El tiempo de ejecucion ms ha sido de: "<<tiempo<<endl;

    for (int i = 1; i <=n; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
    
    system("pause");
    return 0;
}