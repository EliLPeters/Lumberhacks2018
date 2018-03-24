/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: eli
 *
 * Created on March 23, 2018, 7:01 PM
 */

#include <stdio.h>
#include <cstdlib>
#include <ncurses.h>
#include "game.h"

using namespace std;

/*
 * 
 */

int main() {

    game g = game();
    g.launch();
    g.play();
  
  
    endwin();
        
    return 0;
    
}

