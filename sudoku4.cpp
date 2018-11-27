#include "sudoku4.h"

void sudoku4::generar() {
    random_device rand;
    int M[4][4]={0};
    int Mcheck[4][4]={0};
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            int a=rand()%4+1;
            while (M[i][j]==0){
                cambiar(M,Mcheck);
                if (buscar4(i,a,M)== false&&buscar5(j,a,M)== false) {
                    M[i][j]=a;
                } else{
                    a=rand()%4+1;
                }
            }
        }
        if (M[0][0]==4)
            M[1][0]=M[0][0]-1;
        else
            M[1][0]=M[0][0]+1;
    }
    sudoku4::imprimir(M);
}

int sudoku4::cambiar(int (*M)[4], int (*M1)[4]) {
    int a=0;
    int b=0;
    int c=0;
    int d=0;

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (i < 2 && j < 2) {  //1
                M1[0][a] = M[i][j];
                a++;
            } else if (i < 2 && j > 1 && j < 4) {
                M1[1][b] = M[i][j];
                b++;
            } else if (i > 1 && i < 4 && j < 2) {   //3*
                M1[2][c] = M[i][j];
                c++;
            } else if (i > 1 && i < 4 && j > 1 && j < 4) {   //4
                M1[3][d] = M[i][j];
                d++;
            }
        }
    }
    return 0;
}

int sudoku4::si(int x, int y) {
    int a=0;
    if(x-1<2&&y-1<2)
        a=0;
    else if (x-1<2&&y-1>1&&y-1<4)
        a=1;
    else if (x-1>1&&x-1<4&&y-1<2)
        a=2;
    else if (x-1>1&&x-1<4&&y-1<4&&y-1>1)
        a=3;
    return a;
}

bool sudoku4::buscar4(int x, int z, int (*M)[4]) {
    for (int i=0;i<4;i++) {
        if (M[x][i] == z)
            return true;
    }

    return false;
}

bool sudoku4::buscar5(int y, int z, int (*M)[4]) {
    for (int i=0;i<4;i++) {
        if (M[i][y] == z){
            return true;
        }
    }
    return false;
}

void sudoku4::imprimir(int matriz1[4][4]) {
    for (int i=0; i<9; i++){
        cout << "#";
    }
    cout << endl;
    for (int i=0; i<4;++i){
        for(int j=0;j<4; ++j){
            if (j==1||j==3) {
                if (matriz1[i][j] != 0) {
                    cout << matriz1[i][j] << "#";
                } else {
                    cout << " " << "#";
                }
            }else if (j==0){
                if (matriz1[i][j] != 0)
                    cout << "#" << matriz1[i][j] << "|";
                else
                    cout << "#" << " " << "|";
            }
            else
                if (matriz1[i][j]!=0)
                    cout << matriz1[i][j]<<"|";
                else
                    cout<<" "<<"|";
        }
        cout<<endl;
        if (i==1||i==3) {
            for (int i=0; i<9; i++) {
                cout << "#";
            }
            cout << endl;
        } else{
            cout << "#" << "-+-" << "#" << "-+-" << "#"<<endl;
        }
    }
}

void sudoku4::get_numero() {
    int a=0;
    cout<<"Presione 1 para jugar un sudoku existente"<<endl<<
          "Presione 2 para generar uno"<<endl;
    cin>>a;
    if (a==1)
        sudoku4::facil();
    else if (a==2)
        sudoku4::generar();
}

void sudoku4::facil() {
    int a=rand()%7;
    int matriz1[4][4]={0};
    if (a==0){
        int matriz2[4][4]={0, 2, 4, 1,
                           1, 4, 0, 3,
                           0, 3, 1, 0,
                           2, 1, 0, 4};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==1){
        int matriz2[4][4]={0, 1, 2, 3,
                       2, 3, 0, 0,
                       0, 4, 0, 2,
                       1, 0, 3, 4};
        for (int i=0;i<9;i++) {
            for (int j = 0; j < 9; j++) {
                matriz1[i][j] = matriz2[i][j];
            }
        }
    } else if (a==2){
        int matriz2[4][4]={0, 4, 0, 2,
                           2, 0, 4, 0,
                           1, 0, 0, 4,
                           0, 2, 0, 1};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==3){
        int matriz2[4][4]={2, 0, 0, 4,
                           4, 0, 3, 0,
                           0, 2, 4, 1,
                           1, 4, 0, 3};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==4){
        int matriz2[4][4]={2, 3, 1, 0,
                           4, 0, 0, 3,
                           1, 4, 3, 2,
                           0, 2, 4, 0};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==5){
        int matriz2[4][4]={0, 3, 4, 2,
                           2, 4, 0, 1,
                           4, 0, 1, 3,
                           3, 1, 2, 0};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==6){
        int matriz2[4][4]={0, 4, 3, 0,
                           3, 2, 1, 4,
                           2, 0, 0, 1,
                           4, 1, 2, 3};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    }
    int matrizchec[4][4];
    sudoku4::imprimir(matriz1);
    for (int i=0; i<4;i++) {
        for (int j = 0; j < 4; j++) {
            while (matriz1[i][j] == 0) {
                int x = 0;
                int y = 0;
                int z=0;
                cout<< "Igrese que fila desea cambiar(1-9)" << endl;
                cin >> x;
                cout << "Igrese que columna desea cambiar(1-9)" << endl;
                cin >> y;
                cout<<"Ingrese el valor por el cual lo quiera remplazar"<<endl;
                cin>>z;
                sudoku4::cambiar(matriz1,matrizchec);
                if (sudoku4::buscar(x,y,z,matriz1)== true ||sudoku4::buscar2(x,y,z,matrizchec[sudoku4::si(x,y)])==true||sudoku4::buscar3(x,y,z,matriz1)) {
                    cout<<endl;
                }
                else matriz1[x-1][y-1]=z;
                sudoku4::imprimir(matriz1);
            }
        }
    }
    cout<<"Completaste el sudoku!";

}

bool sudoku4::buscar(int x, int y, int z, int M[4][4]) {
    for (int i=0;i<4;i++) {
        if (M[x - 1][i] == z){
            cout<<"Numero no valido"<<endl;
            cout<<"Error en fila en punto ("<<x<<";"<<i+1<<")";
            return true;
        }
    }
    return false;
}

bool sudoku4::buscar3(int x, int y, int z, int M[4][4]) {
    for (int i=0;i<4;i++) {
        if (M[i][y - 1] == z){
            cout<<"Numero no valido"<<endl;
            cout<<"Error en columna en punto ("<<i+1<<";"<<y<<")";
            return true;
        }
    }
    return false;
}

bool sudoku4::buscar2(int x, int y, int z, int M[4]) {
    for(int i=0;i<4;i++) {
        if (M[i] == z) {
            cout<<"Error en cuadrante";
            return true;
        }
    }
    return false;
}

