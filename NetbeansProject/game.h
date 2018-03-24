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
        void launch();
        void play();
    }
    
    void hello()
    {
        
    }
    
    void launch()
    {
        initscr();
        clear();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        curs_set(0);
        printw("Welcome to the game.");
        getch();
        clear();
    }
    
    void play()
    {
        char ch;
        int row = 10;
        int col = 10;
        char guy = '@';
        mvaddch(row,col,guy);
        
        while(true)
        {
            ch = getch();
            
            if(ch == 'q')
            {
                clear();
                break;
            }
            else if(ch == 'i')
            {
                clear();
                row--;
                mvaddch(row,col,guy);
            }
            else if(ch == 'k')
            {
                clear();
                row++;
                mvaddch(row,col,guy);
            }
            else if(ch == 'l')
            {
                clear();
                col++;
                mvaddch(row,col,guy);
            }
            else if(ch == 'j')
            {
                clear();
                col--;
                mvaddch(row,col,guy);
            }
            else
            {
                clear();
                printw("yeah");
            }
          
            refresh();
        }
        
        return;
    }
    
    ~game()
    {
        endwin();
    }
};



#endif /* GAME_H */

