/* 
 * File:   main.cpp
 * Authors: Eli Peters 
 *          John Mackin
 *          David Shapiro
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 7:01 PM
 */

#include <stdio.h>
#include <cstdlib>
#include <ncurses.h>
#include "game.h"
#include "battle.h"
#include "genMaps.h"

using namespace std;

/*
 * 
 */

int main() {

    outputMap();
    
    game g = game();
  
    endwin();
        
    return 0;
    
}

