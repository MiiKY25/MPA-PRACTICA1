#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

void OrdenarDecreciente_VP(int n,string* Vnombres,float* Vpesos,float* Vvalores){
    float* Vratios=new float[n+1];
    for (int i = 1; i <=n; i++) {
        Vratios[i]=Vvalores[i]/Vpesos[i];
    }

    //Comparmos el ratio actual con el siguiente
    for (int i = 1; i <n; i++) {
        for (int j = i+1; j <=n; j++) {
            // Si el ratio actual es menor que el siguiente, intercambiamos
            if (Vratios[i]<Vratios[j]){
                float auxRatio=Vratios[i];
                Vratios[i]=Vratios[j];
                Vratios[j]=auxRatio;

                string auxNombre=Vnombres[i];
                Vnombres[i]=Vnombres[j];
                Vnombres[j]=auxNombre;

                float auxPesos=Vpesos[i];
                Vpesos[i]=Vpesos[j];
                Vpesos[j]=auxPesos;

                float auxValores=Vvalores[i];
                Vvalores[i]=Vvalores[j];
                Vvalores[j]=auxValores;
            }   
        }
    }
    delete[] Vratios;
    
}

float* Mochila(int M,int n,string* Vnombres,float* Vpesos,float* Vvalores){
    float* Vfracciones=new float[n+1];
    float peso;
    int i;

    for (int j = 1; j <=n; j++) {
        Vfracciones[j]=0;
    }

    OrdenarDecreciente_VP(n,Vnombres,Vpesos,Vvalores);
    i=1;
    peso=0;

    while (peso<M && i<=n) {
        if (peso + Vpesos[i]<=M){
            Vfracciones[i]=1;
            peso=peso+Vpesos[i];
        }else{
            Vfracciones[i]=(M-peso)/Vpesos[i];
            peso=M;
        }
        i=i+1;
    }
    return Vfracciones;
}

int main(){
    clock_t t_inicio,t_fin;

    int M,n;
    cout<<"Introduce el peso maximo de la furgoneta (M): ";
    cin>>M;
    cout<<"Introduce el numero de cafes disponibles (n): ";
    cin>>n;

    cout<<endl;
    cout<<"Introduce los nombres de los cafes: "<<endl;
    string* Vnombres=new string[n+1];

    for (int i = 1; i <=n; i++) {
         cout<<"Nombre cafe "<<i<<": ";
         cin>>Vnombres[i];
    }

    cout<<endl;
    cout<<"Introduce los pesos (Kg): "<<endl;
    float* Vpesos=new float[n+1];

    for (int i = 1; i <=n; i++) {
         cout<<"Peso cafe "<<i<<": ";
         cin>>Vpesos[i];
    }

    cout<<endl;
    cout<<"Introduce los valores (euros): "<<endl;
    float* Vvalores=new float[n+1];

    for (int i = 1; i <=n; i++) {
         cout<<"Valor cafe "<<i<<": ";
         cin>>Vvalores[i];
    }

    cout<<endl;
    cout<<"Cafes disponibles en el mercado: "<<endl;
    cout<<"===================================="<<endl;
    for (int i = 1; i <=n; i++) {
         cout<<"("<<Vnombres[i]<<", "<<Vpesos[i]<<", "<<Vvalores[i]<<")"<<endl; 
    }

    cout<<endl;
    cout<<"Ejecutando Algoritmo Voraz..."<<endl;

    t_inicio=clock();
    float* Vfracciones=Mochila(M,n,Vnombres,Vpesos,Vvalores);
    t_fin=clock();
    float tiempo=(float)(t_fin-t_inicio) / CLOCKS_PER_SEC * 1000;

    cout<<endl;
    cout<<"Mercancia cargada en la furgoneta:"<<endl;
    cout<<"===================================="<<endl;
    float valorTotal=0;
    for (int i = 1; i <=n; i++) {
         cout<<"("<<Vnombres[i]<<", "<<Vpesos[i]<<", "<<Vvalores[i]<<") --> Comprando al "<<Vfracciones[i]*100<<"%"<<endl; 
         valorTotal = valorTotal + (Vfracciones[i] * Vvalores[i]);
    }

    cout<<endl;
    cout<<"Valor total de la furgoneta: "<<valorTotal<<" euros"<<endl;
    cout<<endl;
    cout<<"Tiempo de ejecucion: "<<tiempo<<" milisegundos"<<endl;
    
    delete[] Vnombres;
    delete[] Vpesos;
    delete[] Vvalores;
    delete[] Vfracciones;

    system("pause");
    return 0;
}