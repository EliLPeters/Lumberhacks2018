/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game.h
 * Author: eli
 *
 * Created on March 23, 2018, 7:44 PM
 */

#ifndef GAME_H
#define GAME_H

#include <ncurses.h>

class game
{
public:
    game()
    {
        initscr();
        keypad(stdscr, TRUE);
        printw("hello wordl!\n");
        refresh();
        getch();
    }
    
    void hello()
    {
        
    }
    
    ~game()
    {
        endwin();
    }
};



#endif /* GAME_H */

