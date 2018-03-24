/* 
 * File:   main.cpp
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
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
    g.play();
  
  
    endwin();
        
    return 0;
    
}

