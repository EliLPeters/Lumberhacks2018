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
#include <vector>

#include "map.h"
#include "unit.h"
#include "monster.h"
#include "player.h"

using namespace std;

class game
{
private:
    bool _terminate = false;
    map m = map();
    
    vector<monster> _monster_vector;
    
public:
    game()
    {
        initscr();
        clear();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        curs_set(0);
        string temp = "Welcome! Press any key to continue.";
        move(0,((COLS / 2) - (temp.length() / 2)));
        printw(temp.c_str());
        getch();
        clear();
        //while(_terminate == false)
        //{
            mainMenu();
            //if(_terminate == false)
            //{
                void play2();
            //{
        //}
    }
    
    void hello()
    {
        
    }
    
    void launch()
    {
        
        
    }
    
    void mainMenu()
    {
        bool play = false;
        int choice = 0;
        while(_terminate == false && play == false)
        {
            move(0,0);
            printw("  Play");
            move(2,0);
            printw("  Quit");
            mvaddch(choice, 0, '>');
            refresh();
            int ch = getch();
            if(ch == KEY_UP)
            {
                choice = 0;
            }
            else if(ch == KEY_DOWN)
            {
                choice = 2;
            }
            else if(ch == 10)
            {
                switch(choice)
                {
                    case 0:
                        play = true;
                        break;
                    case 2:
                        _terminate = true;
                        break;
                }
            }
        }
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
    
    void play2()
    {
        player p = player("test");
        
        mvaddch(p.getX(), p.getY(), p.getSymbol());
        m.drawMap();
        while(true)
        {
            char ch = getchar();
            
            p.move(ch);
            
            mvaddch(p.getX(), p.getY(), p.getSymbol());
            
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

