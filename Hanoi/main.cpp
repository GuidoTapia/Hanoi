#include <iostream>
#include<windows.h>
//se importa la libreria windows para poder utilizar la funcion Sleep() para que la animacion sea visible
using namespace std;

const int tamano=7;//7 es el limite antes de que la impresion se descuadre se puede usar cualquier valor
                    //teniendo en cuenta que la animacion no se notaria y que la complejidad del ejercicio es de 2^n
int cont=0;
/*Funcion para mover un solo bloque o ficha considerado en el caso que no exista ninguna ficha sobre ella
se ingresa el caracter de su columna actual, la columna a la cual se debe mover el tamaño o numero de
bloque y la matriz de bloques al final de la funcion se imprime las torres despues de efectuar el movimiento
y se contabiliza el movimiento en una variable global*/
void moverUno(char inicio, char fin, int bloque, int bloques[][tamano]){
    int aux = inicio-65;
    int vAux=0;
    int i=0;
    bool flag= true;
    while (i<tamano && flag){
        if (bloques[aux][i]==bloque){
            vAux=bloques[aux][i];
            bloques[aux][i]=0;
            flag=false;
        }else{
            i++;
        }
    }
    i=0;
    aux = fin-65;
    flag=true;
    while (i<tamano && flag){
        if (bloques[aux][i]==0){
            bloques[aux][i]=vAux;
            flag=false;
        }else{
            i++;
        }
    }
    cont++;
    cout<<"________________________________________________\nMovimiento\n"<<cont<<"\n________________________________________________\n";
    for (int j=tamano-1;j>=0;j--){
        for (int i=0;i<3;i++){
            if(bloques[i][j]==0){
                cout<<"|\t";
            }else{
                for(int k=0;k<bloques[i][j];k++){
                    cout<<bloques[i][j];
                }
                cout<<"\t";
            }
        }
        cout<<"\n";
    }
    Sleep(500);
}
/*Funcion para mover la ficha y todas las superiores a esta, caso base cuando la ficha sea la mas pequeña,
es decir ninguna puede estar sobre ella, se ingresa la torre de inicio, la torre de llegada, el tamaño de la
ficha y la matriz que representa las torres*/
void mover(char inicio, char fin, int bloque, int bloques[][tamano]){
    if(bloque==1){
        moverUno(inicio,fin,bloque,bloques);
    }else{
        char cAux='D';
        if((inicio=='A' && fin=='B') || (inicio=='B' && fin=='A')){
            cAux='C';
        }else if((inicio=='A' && fin=='C') || (inicio=='C' && fin=='A')){
            cAux='B';
        }else{
            cAux='A';
        }
        mover(inicio,cAux,bloque-1,bloques);
        moverUno(inicio,fin,bloque,bloques);
        mover(cAux,fin,bloque-1,bloques);
    }
}
int main(){
    //el algoritmo es flexible asi que permite que se traslade las fichas a cualquiera de las dos torres libres
    char cTorre;
    cout << "Tamaño de la torre: " << tamano<< endl;
    cout << "A que fila desea pasarlo? B o C" << endl;
    cin >> cTorre;
    //cin >> tamano;
    int torres[3][tamano];
    for (int i=0;i<tamano;i++){
        torres[0][i]=tamano-i;
    }
    for (int i=0;i<tamano;i++){
        torres[1][i]=0;
    }
    for (int i=0;i<tamano;i++){
        torres[2][i]=0;
    }
    cout<<"________________________________________________\nTorre Original\n________________________________________________\n";
    for (int j=tamano-1;j>=0;j--){
        for (int i=0;i<3;i++){
            if(torres[i][j]==0){
                cout<<"|\t";
            }else{
                for(int k=0;k<torres[i][j];k++){
                    cout<<torres[i][j];
                }
                cout<<"\t";
            }
        }
        cout<<"\n";
    }
    Sleep(2000);
    mover('A',cTorre,tamano,torres);
    cout<<"________________________________________________\nCOMPLETADO\n________________________________________________\n";
    cout<<"Movimientos totales: " << cont;
    return 0;
}
