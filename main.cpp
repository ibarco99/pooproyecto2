#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
#include "menu.h"
#include "sudoku9.h"
#include "sudoku4.h"

using namespace std;


int main(){
    menu s1;
    int a=s1.menuu();
    if (a==1){
        sudoku9 juego;
        juego.get_numero();
    } else if(a==2){
        sudoku4 juego;
        juego.get_numero();
    } else
        return 0;
}
