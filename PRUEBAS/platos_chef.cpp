#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

void ImprimirSolucion(int n,int* asignaciones,int** dificultad){
    cout<<">>> SOLUCION ENCONTRADA <<<"<<endl;
    for (int i = 1; i <=n; i++) {
        cout<<"Plato "<<i<<" servido a la Mesa "<<asignaciones[i]<<" (Tiempo "<<dificultad[i][asignaciones[i]]<<" min)"<<endl;
    }
}

bool esFactible(int plato,int mesa,int tiempoActual,int tiempoObjetivo,int n,int** dificultad,int* asignaciones){
    for (int i = 1; i <plato; i++) {
        if (asignaciones[i]==mesa) {
            return false;
        }
    }
    if (tiempoActual + dificultad[plato][mesa]>tiempoObjetivo){
        return false;
    }
    
    return true;
}

void AsignarMesas(int plato,int tiempoActual,int n,int tiempoObjetivo,int** dificultad,int* asignaciones){
    int mesa;

    if (plato>n && tiempoActual==tiempoObjetivo) {
        ImprimirSolucion(n,asignaciones,dificultad);
    }else {
        if (plato<=n) {
            for (mesa = 1; mesa <= n; mesa++) {
                if (esFactible(plato,mesa,tiempoActual,tiempoObjetivo,n,dificultad,asignaciones)) {
                    asignaciones[plato]=mesa;
                    AsignarMesas(plato+1,tiempoActual+dificultad[plato][mesa],n,tiempoObjetivo,dificultad,asignaciones);
                    asignaciones[plato]=0;
                }
            }
        }
    }
}

int main(){
    clock_t tiempo_inicio,tiempo_fin;

    int n,tiempoObjetivo;
    srand(time(NULL));//Para que genere numeros aleatorios siempre que se ejecute

    cout<<"Introduce el numero de platos y mesas (n): ";
    cin>>n;
    cout<<"Introduce el tiempo objetivo a alcanzar (minutos): ";
    cin>>tiempoObjetivo;

    cout<<"Generando tiempos de preparacion aleatorios... "<<endl;
    cout<<"OBJETIVO DEL CHEF: Clavar exactamente "<<tiempoObjetivo<<" minutos."<<endl;

    int** dificultad=new int*[n+1];

    for (int i = 1; i <=n; i++) {
        dificultad[i]=new int[n+1];
        for (int j = 1; j <=n; j++) {
            dificultad[i][j]=rand()% 11 + 1;//Generar numeros random del 1 al 10
        }
    }

    cout<<"MATRIZ DIFICULTADES (Minutos): "<<endl;
    for (int i = 1; i <=n; i++) {
        cout<<"\t Mesa "<<i;
    }
    cout<<endl;
    cout<<"-------------------------------------- "<<endl;
    for (int i = 1; i <=n; i++) {
        cout<<"Plato "<<i<<" |";
        for (int j = 1; j <=n; j++) {
            cout<<"\t"<<dificultad[i][j];
        }
        cout<<endl;
    }

    int* asignaciones=new int[n+1];

    tiempo_inicio=clock();
    AsignarMesas(1,0,n,tiempoObjetivo,dificultad,asignaciones);

    tiempo_fin=clock();
    double tiempoTrancurrido=(double)(tiempo_fin-tiempo_inicio) / CLOCKS_PER_SEC*1000;
    cout<<"Tiempo de ejecucion: "<<tiempoTrancurrido<<" milisegundos."<<endl;

    for (int i = 1; i <=n; i++) {
        delete[] dificultad[i];
    }
    delete[] dificultad;
    delete[] asignaciones;
    
    system("pause");
    return 0;

}