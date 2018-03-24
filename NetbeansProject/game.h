/* 
 * File:   game.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 7:44 PM
 */

#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include "map.h"

using namespace std;

class game
{
private:
    bool _terminate = false;
    map m = map();
    
public:
    game()
    {
        void launch();
        //while(_terminate == false)
        //{
            mainMenu();
            //if(_terminate == false)
            //{
                void play();
            //{
        //}
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
        getch();
        clear();
    }
    
    void mainMenu()
    {
        // TODO: fill in, give a way to set _terminate to true
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
                if(row > 1) {row--;}
                   
                
                mvaddch(row,col,guy);
                //m.drawMap();
            }
            else if(ch == 'k')
            {
                clear();
                if (row < LINES-2) {row++;}
                
                mvaddch(row,col,guy);
                //m.drawMap();
            }
            else if(ch == 'l')
            {
                clear();
                if (col < COLS-2){col++;}
                
                mvaddch(row,col,guy);
                //m.drawMap();
            }
            else if(ch == 'j')
            {
                clear();
                if (col > 1) {col--;}  
                
                mvaddch(row,col,guy);
                //m.drawMap();
            }
            else
            {
                
            }
            m.drawMap();
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

