
#include "sudoku9.h"

void sudoku9::get_numero() {
    int x;
    cout << "Elija el nivel que quiera jugar:" << endl <<
         "1    Facil" << endl <<
         "2    Normal" << endl <<
         "3    Dificil" << endl <<
         "4    Generar uno" << endl;
    cin >> x;
    if (x == 1) {
        sudoku9::facil();
    } else if (x == 2)
        sudoku9::normal();
    else if (x == 3)
        sudoku9::dificil();
    else if (x==4)
        sudoku9::crear();
}

void sudoku9::facil() {
    int a=rand()%3;
    int matrizchec[9][9];
    int matriz1[9][9]={0};
    if (a==0){
        int matriz2[9][9]={0, 0, 6, 0, 0, 2, 3, 0, 4,
                           9, 0, 4, 7, 5, 0, 0, 8, 2,
                           0, 0, 8, 0, 0, 6, 0, 0, 5,
                           0, 0, 3, 0, 0, 0, 0, 4, 0,
                           2, 0, 0, 4, 0, 0, 8, 3, 0,
                           4, 0, 7, 5, 0, 0, 0, 0, 0,
                           0, 0, 0, 6, 0, 0, 0, 0, 8,
                           7, 0, 0, 0, 2, 0, 4, 5, 3,
                           0, 0, 0, 3, 7, 0, 0, 6, 9};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==1){
        int matriz2[9][9]={0,0,2,8,0,0,0,7,0,
                           6,0,9,0,7,4,0,2,3,
                           4,0,8,0,0,3,0,5,0,
                           0,0,5,0,8,0,0,3,0,
                           0,0,0,0,0,0,7,4,0,
                           0,2,7,0,3,0,0,8,5,
                           0,0,0,3,6,0,0,0,0,
                           0,0,0,5,1,7,4,0,8,
                           0,0,0,2,0,8,0,9,0};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==2){
        int matriz2[9][9]={0,0,0,0,2,8,5,0,0,
                           0,0,0,6,0,0,0,0,7,
                           0,8,6,0,0,5,3,4,0,
                           8,6,9,2,3,0,0,0,0,
                           5,1,2,0,0,7,0,0,0,
                           4,0,0,5,0,0,0,0,2,
                           0,2,8,0,6,0,0,0,0,
                           0,0,5,0,4,0,2,7,0,
                           0,0,4,0,0,0,6,3,9};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    }
    sudoku9::imprimir(matriz1);
    for (int i=0; i<9;i++) {
        for (int j = 0; j < 9; j++) {
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
                sudoku9::cambiar(matriz1,matrizchec);
                if (sudoku9::buscar(x,y,z,matriz1)== true ||sudoku9::buscar2(x,y,z,matrizchec[sudoku9::si(x,y)])==true||sudoku9::buscar3(x,y,z,matriz1)) {
                    cout<<endl;
                }
                else matriz1[x-1][y-1]=z;
                sudoku9::imprimir(matriz1);
            }
        }
    }
    cout<<"Completaste el sudoku!";
    }

void sudoku9::normal() {
     int a=rand()%3;
    int matrizchec[9][9];
     int matriz1[9][9]={0};
     if (a==0){
         int matriz2[9][9]={0, 0, 0, 0, 0, 0, 0, 8, 4,
                            5, 0, 0, 0, 4, 2, 6, 0, 0,
                            0, 0, 4, 0, 0, 0, 0, 2, 0,
                            0, 4, 0, 0, 6, 3, 7, 0, 0,
                            0, 0, 0, 0, 0, 1, 0, 0, 3,
                            6, 3, 0, 9, 5, 7, 2, 0, 0,
                            0, 5, 0, 0, 0, 9, 0, 0, 6,
                            3, 2, 0, 8, 0, 0, 1, 0, 9,
                            0, 0, 9, 5, 0, 0, 8, 0, 0};
         for (int i=0;i<9;i++){
             for (int j=0;j<9;j++){
                 matriz1[i][j]=matriz2[i][j];
             }
         }
     } else if (a==1){
         int matriz2[9][9]={0, 0, 8, 9, 0, 0, 7, 2, 0,
                            0, 0, 9, 0, 1, 0, 0, 4, 0,
                            0, 1, 4, 0, 0, 2, 5, 0, 0,
                            0, 0, 0, 0, 0, 6, 0, 0, 0,
                            0, 4, 7, 0, 0, 0, 0, 0, 0,
                            6, 0, 3, 5, 4, 0, 9, 0, 2,
                            0, 0, 5, 0, 9, 3, 2, 0, 0,
                            0, 0, 6, 0, 2, 0, 0, 7, 0,
                            0, 0, 0, 6, 7, 5, 0, 0, 4};
         for (int i=0;i<9;i++){
             for (int j=0;j<9;j++){
                 matriz1[i][j]=matriz2[i][j];
             }
         }
     } else if (a==2){
         int matriz2[9][9]={0, 0, 0, 3, 0, 7, 0, 0, 0,
                            0, 8, 3, 0, 5, 0, 0, 0, 0,
                            9, 0, 0, 0, 0, 0, 3, 2, 4,
                            0, 0, 7, 8, 6, 2, 0, 3, 0,
                            0, 4, 0, 9, 0, 0, 0, 0, 0,
                            3, 5, 2, 0, 0, 0, 0, 0, 6,
                            0, 0, 0, 0, 9, 3, 8, 6, 0,
                            5, 0, 0, 7, 8, 0, 0, 4, 0,
                            0, 6, 0, 0, 4, 0, 0, 0, 3};
         for (int i=0;i<9;i++){
             for (int j=0;j<9;j++){
                 matriz1[i][j]=matriz2[i][j];
             }
         }
     }
    sudoku9::imprimir(matriz1);
    for (int i=0; i<9;++i) {
        for (int j = 0; j < 9; ++j) {
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
                sudoku9::cambiar(matriz1,matrizchec);
                if (sudoku9::buscar(x,y,z,matriz1)== true ||sudoku9::buscar2(x,y,z,matrizchec[sudoku9::si(x,y)])==true||sudoku9::buscar3(x,y,z,matriz1)) {
                    cout<<endl;
                }
                else matriz1[x-1][y-1]=z;
                sudoku9::imprimir(matriz1);
            }
        }
    }
    cout<<"Completaste el sudoku!";
}

void sudoku9::dificil() {
    int a=rand()%3;
    int matrizchec[9][9];
    int matriz1[9][9]={0};
    if (a==0){
        int matriz2[9][9]={0,0,0,0,0,0,0,1,0,
                           1,3,6,9,5,8,0,0,4,
                           0,0,0,0,0,0,0,0,8,
                           0,0,0,0,0,6,9,0,0,
                           7,1,0,0,0,2,8,0,0,
                           8,6,0,0,0,0,0,0,0,
                           3,0,0,0,1,0,0,0,2,
                           6,4,1,0,0,0,3,0,7,
                           0,0,7,6,0,0,0,5,0};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==1){
        int matriz2[9][9]={0,5,0,0,0,1,0,0,0,
                           0,0,0,0,0,6,0,7,0,
                           3,0,9,0,4,0,0,6,5,
                           0,0,8,9,1,4,0,0,0,
                           0,0,0,0,6,7,8,2,9,
                           0,9,7,0,0,0,0,0,4,
                           0,0,4,1,0,0,0,0,0,
                           0,7,0,0,0,0,6,9,1,
                           0,3,5,0,0,0,2,0,0};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    } else if (a==2){
        int matriz2[9][9]={0,0,0,8,0,0,7,4,0,
                           5,0,9,0,0,0,0,0,0,
                           0,8,0,0,0,7,0,9,6,
                           0,0,4,6,0,0,8,5,0,
                           0,1,0,5,0,0,9,0,0,
                           8,0,0,9,2,0,0,0,4,
                           0,0,5,7,0,0,0,0,9,
                           0,9,0,0,4,0,0,8,5,
                           0,0,0,0,0,5,6,0,2};
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                matriz1[i][j]=matriz2[i][j];
            }
        }
    }
sudoku9::imprimir(matriz1);
    for (int i=0; i<9;++i) {
        for (int j = 0; j < 9; ++j) {
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
                sudoku9::cambiar(matriz1,matrizchec);
                if (sudoku9::buscar(x,y,z,matriz1)== true ||sudoku9::buscar2(x,y,z,matrizchec[sudoku9::si(x,y)])==true||sudoku9::buscar3(x,y,z,matriz1)==
                                                                                                                        true) {
                    cout<<endl;
                }
                else matriz1[x-1][y-1]=z;
                sudoku9::imprimir(matriz1);
            }
        }
    }
    cout<<"Completaste el sudoku!";
}

int sudoku9::cambiar(int M[9][9], int M1[9][9]) {
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int g=0;
    int h=0;
    int k=0;

     for (int i=0;i<9;i++){
          for (int j=0;j<9;j++){
                  if (i < 3 && j < 3) {  //1
                      M1[0][a] = M[i][j];
                      a++;
                  } else if (i < 3 && j > 2 && j < 6) {
                      M1[1][b] = M[i][j];
                      b++;
                  } else if (i < 3 && j > 5 && j < 9) {   //3*
                      M1[2][c] = M[i][j];
                      c++;
                  } else if (i > 2 && i < 6 && j < 3) {   //4
                      M1[3][d] = M[i][j];
                      d++;
                  } else if (i > 2 && i < 6 && j > 2 && j < 6) {   //5
                      M1[4][e] = M[i][j];
                      e++;
                  } else if (i > 2 && i < 6 && j > 5 && j < 9) {    //6
                      M1[5][f] = M[i][j];
                      f++;
                  } else if (i > 5 && i < 9 && j < 3) {   //7
                      M1[6][g] = M[i][j];
                      g++;
                  } else if (i > 5 && i < 9 && j > 2 && j < 6) {   //8
                      M1[7][h] = M[i][j];
                      h++;
                  } else if (i > 5 && i < 9 && j > 5 && j < 9) {    //9
                      M1[8][k] = M[i][j];
                      k++;
                  }
          }
     }
     return 0;
}

bool sudoku9::buscar(int x, int y, int z,int M[9][9]) {
     for (int i=0;i<9;i++) {
          if (M[x - 1][i] == z){
              cout<<"Numero no valido"<<endl;
              cout<<"Error en fila en punto ("<<x<<";"<<i+1<<")";
               return true;
          }
     }
     return false;
}

void sudoku9::imprimir(int matriz1[9][9]) {
    for (int i=0; i<19; i++){
        cout << "#";
    } cout<<endl;
    for (int i=0; i<9;++i){
        for(int j=0;j<9; ++j) {
                if (j == 2 || j == 5 || j == 8) {
            if (matriz1[i][j] != 0) {
                cout << matriz1[i][j] << "#";
            } else {
                cout << " " << "#";
            }
                }else if (j==0) {
            if (matriz1[i][j] != 0)
                cout << "#" << matriz1[i][j] << "|";
            else
                cout << "#" << " " << "|";

        } else
            if (matriz1[i][j]!=0)
                cout << matriz1[i][j]<<"|";
            else
                cout<<" "<<"|";

        }
        cout<<endl;
        if (i==2||i==5||i==8) {
            for (int i=0; i<19; i++) {
                cout << "#";
            }
            cout << endl;
        } else{
            cout << "#" << "-+-+-" << "#" << "-+-+-" << "#"<< "-+-+-" << "#"<<endl;
        }
    }
}

bool sudoku9::buscar2(int x, int y, int z, int M[9]) {
    for(int i=0;i<9;i++) {
        if (M[i] == z) {
            cout<<"Error en cuadrante";
            return true;
        }
    }
    return false;
}

int sudoku9::si(int x, int y) {
    int a=0;
    if(x-1<3&&y-1<3)
        a=0;
    else if (x-1<3&&y-1>2&&y-1<6)
        a=1;
    else if (x-1<3&&y-1>6&&y-1<9)
        a=2;
    else if (x-1>2&&x-1<6&&y-1<3)
        a=3;
    else if (x-1>2&&x-1<6&&y-1>2&&y-1<6)
        a=4;
    else if (x-1>2&&x-1<6&&y-1<9&&y-1>6)
        a=5;
    else if (x-1>5&&x-1<9&&y-1<3)
        a=6;
    else if (x-1>5&&x-1<9&&y-1>2&&y-1<6)
        a=7;
    else if (x-1>5&&x-1<9&&y-1<9&&y-1>6)
        a=8;
    return a;
}

bool sudoku9::buscar3(int x, int y, int z, int (*M)[9]) {
    for (int i=0;i<9;i++) {
        if (M[i][y - 1] == z){
            cout<<"Numero no valido"<<endl;
            cout<<"Error en columna en punto ("<<i+1<<";"<<y<<")";
            return true;
        }
    }
    return false;
}

void sudoku9::crear() {
    random_device rand;
    int M[9][9]={0};
    int Mcheck[9][9]={0};
    for(int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            int a=rand()%9+1;
            while (M[i][j]==0){
                sudoku9::cambiar(M,Mcheck);
                if (sudoku9::buscar4(i,j,a,M)== false&&sudoku9::buscar6(i+1,a,Mcheck[sudoku9::si(i,j)])== false) {
                    M[i][j]=a;
                } else{
                    a=rand()%9+1;
                }
            }
        }
    }
    sudoku9::imprimir(M);
}

bool sudoku9::buscar4(int x,int y, int z, int M[9][9]) {
    for (int j=0;j<9;j++){
        for (int k=0;k<9;k++)
            cout<<M[j][k];
        cout<<endl;
    }
    for (int i=0;i<9;i++) {
        if (M[x][i] == z)
            return true;
    }
    for (int j=0;j<9;j++) {
        if (M[j][y] == z)
            return true;
    }
    return false;
}

bool sudoku9::buscar5(int y, int z, int M[9][9]) {
    for (int i=0;i<9;i++) {
        if (M[i][y - 1] == z){
            return true;
        }
    }
    return false;
}

bool sudoku9::buscar6(int x, int z, int M[9]) {
    for (int j=0;j<9;j++){
            cout<<M[j];

    } cout <<endl;
    for(int i=0;i<9;i++) {
        if (M[i] == z) {
            return true;
        }
    }
    return false;
}
