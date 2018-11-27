#ifndef PROYECTO2_SUDOKU4_H
#define PROYECTO2_SUDOKU4_H
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
using namespace std;


class sudoku4 {
int x;
public:
    void get_numero();
    void facil();
    bool buscar(int x, int y, int z,int M[4][4]);
    bool buscar3(int x, int y, int z, int M[4][4]);
    bool buscar2(int x, int y, int z,int M[4]);
    void generar();
    int cambiar(int M[4][4], int M1[4][4]);
    int si(int x, int y);
    bool buscar4(int x,int z, int M[4][4]);
    bool buscar5(int y, int z, int M[4][4]);
    void imprimir(int matriz1[4][4]);

};
