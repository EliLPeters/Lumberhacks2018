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

using namespace std;

class game
{
private:
    bool _terminate = false;
    
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
        printw("Welcome to the game.");
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

