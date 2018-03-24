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
#include <string>

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
        string welcome = "Welcome! press any key to continue!";
        move(0,((COLS / 2) - (welcome.length() / 2)));
        printw(welcome.c_str());
        refresh();
        getch();
        clear();
        while(_terminate == false)
        {
            mainMenu();
            if(_terminate == false)
            {
                clear();
                play();
            }
        }
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
        player p = player("test");
        
        mvaddch(p.getX(), p.getY(), p.getSymbol());
        m.drawMap();
        while(true)
        {
            char ch = getchar();
            if(ch == 'x')
            {
                clear();
                refresh();
                return;
            }
            
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

