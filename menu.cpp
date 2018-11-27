#include "menu.h"

int menu::menusudoku() {
    int b=0;
    cout<<"Presione 1 para jugar en el tabletro tradicional"<<endl<<
        "Presione 2 para jugar en tablero de 2*2"<<endl;
    cin>>b;
    if (b==1){
        return 1;
    } else if(b==2){
        return 2;
    } else if(b>2)
        menu::menusudoku();
}

int menu::menuu() {
    int a=0;
    cout<<"Precione 1 para jugar"<<endl<<
        "Precione 2 para dibujar el tablero"<<endl<<
        "Precione 3 para salir"<<endl;
    cin>>a;
    cout<<endl;
    if (a==1){
        return menusudoku();
    } else if (a==2){
        menudibujar();
        menu::menuu();
    } else if(a==3){
        return 0;
    }
    else
        menu::menuu();
}

void menu::menudibujar() {
    int a =0;
    cout<<"Precione 1 para dibujar el tablero tradicional"<<endl<<
        "Precione 2 para dibujar tavlero de 2*2"<<endl;
    cin>>a;
    if (a==1){
        dibujar3();
        return;
    } else if(a==2){
        dibujar2();
        return;
    }else
        menudibujar();
}

void menu::dibujar2() {
    char x=0;
    cout << "Ingresar un borde: " << endl;
    cin >> x;
    for (int i=0; i<9; i++){
        cout << x;
    }
    cout << endl;
    for (int i=0; i<4;++i){
        for(int j=0;j<4; ++j){

            if (j==1||j==3)
                cout  << ' ' << x;
            else if (j==0)
                cout  << x <<' ' <<"|";
            else
                cout  << ' ' << "|";
        }
        cout<<endl;
        if (i==1||i==3) {
            for (int i=0; i<9; i++) {
                cout << x;
            }
            cout << endl;
        } else{
            cout << x << "-+-" << x << "-+-" << x<<endl;
        }
    }
}

void menu::dibujar3() {
    char x=0;
    cout << "Ingresar un borde: " << endl;
    cin >> x;
    for (int i=0; i<19; i++){
        cout << x;
    }
    cout << endl;
    for (int i=0; i<9;++i){
        for(int j=0;j<9; ++j){

            if (j==2||j==5||j==8)
                cout  << ' ' << x;
            else if (j==0)
                cout  << x <<' ' <<"|";
            else
                cout  << ' ' << "|";
        }
        cout<<endl;
        if (i==2||i==5||i==8) {
            for (int i=0; i<19; i++) {
                cout << x;
            }
            cout << endl;
        } else{
            cout << x << "-+-+-" << x << "-+-+-" << x<< "-+-+-" << x<<endl;
        }
    }
}
