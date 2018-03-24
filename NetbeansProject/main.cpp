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

        WINDOW *vin;
    initscr();
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_YELLOW);
    init_pair(3,COLOR_BLUE,COLOR_WHITE); 
    vin=newwin(12,40,13,0);
    wmove(vin,0,5);
    wprintw(vin,"Hello, World.");
    wbkgd(vin,COLOR_PAIR(1));
    wrefresh(vin);
    getch();
    delwin(vin);
    endwin();
    return 0;
    
}

