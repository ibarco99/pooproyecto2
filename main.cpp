#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
#include "menu.h"
#include "sudoku9.h"

using namespace std;


int main(){
    menu s1;
    if (s1.menuu()==1){
        sudoku9 juego;
        juego.get_numero();
        }

    return 0;
}
