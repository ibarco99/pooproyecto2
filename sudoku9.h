//
// Created by Barco on 11/16/18.
//

#ifndef PROYECTO2_SUDOKU9_H
#define PROYECTO2_SUDOKU9_H

#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
using namespace std;


class sudoku9 {
int x;
public:
    void get_numero();
    void facil();
    void normal();
    void dificil();
    void crear();
    int cambiar(int M[9][9], int M1[9][9]);
    bool buscar(int x, int y, int z,int M[9][9]);
    bool buscar3(int x, int y, int z, int M[9][9]);
    bool buscar2(int x, int y, int z,int M[9]);
    void imprimir(int matriz1[9][9]);
    int si(int x, int y);
    bool buscar4(int x,int y, int z, int M[9][9]);
    bool buscar5(int y, int z, int M[9][9]);
    bool buscar6(int x, int z, int M[9]);
};
