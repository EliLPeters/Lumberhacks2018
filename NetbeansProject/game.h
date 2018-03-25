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
#include "battle.h"

using namespace std;

class game
{
private:
    bool _terminate = false;
    map m = map();
    int roomcount;
    int score;
    player p;
    
    vector<monster> _monster_vector;
    
public:
    game()
    {
        srand(time(NULL));
        initscr();
        clear();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
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
        }
    }
    
    void mainMenu()
    {
        int choice = 0;
        while(_terminate == false)
        {
            move(0,0);
            printw("  Play");
            move(2,0);
            printw("  About");
            move(4,0);
            printw("  Quit");
            mvaddch((choice * 2), 0, '>');
            refresh();
            int ch = getch();
            if(ch == KEY_UP)
            {
                if(choice > 0)
                {
                    choice--;
                }
            }
            else if(ch == KEY_DOWN)
            {
                if(choice < 2)
                {
                    choice ++;
                }
            }
            
            else if(ch == 10)
            {
                switch(choice)
                {
                    case 0:
                        play();
                    case 2:
                        _terminate = true;
                        return;
                    case 3:
                        player pl = player("Dave");
                        monster w = troll();
                        battle b = battle(w,pl);
                        break;
                }
            }
        }
    }
    
    void printInfo()
    {
        move(19,0);
        printw("Name: ");
        printw(p.getName().c_str());
        printw("\tScore: ");
        string temp = to_string(score);
        printw(temp.c_str());
    }
    
    void play()
    {
        p = player("test");
        
        roomcount = 1;
        score = 0;
        
        mvaddch(p.getY(), p.getX(), p.getSymbol());
        m.drawMap();
        spawnMonsters();
        int ch = getchar();
        while(true)
        {
            switch(ch)
            {
                case 'x':
                    clear();
                    refresh();
                    return;
                case 'i':
                    if(!m.isWall(p.getX(), (p.getY() - 1)) && !m.isDoor(p.getX(), (p.getY() - 1)))
                    {
                        p.move(ch);
                    }
                    else if(m.isDoor(p.getX(), (p.getY() - 1)))
                    {
                        m.newRoom('n');
                        p.relocate(p.getX(), 17);
                        roomcount++;
                        spawnMonsters();
                    }
                    break;
                case 'j':
                    if(!m.isWall((p.getX() - 1), p.getY()) && !m.isDoor((p.getX() - 1), p.getY()))
                    {
                        p.move(ch);
                    }
                    else if(m.isDoor((p.getX() - 1), p.getY()))
                    {
                        m.newRoom('w');
                        p.relocate(51, p.getY());
                        roomcount++;
                        spawnMonsters();
                    }
                    break;
                case 'k':
                    if(!m.isWall(p.getX(), (p.getY() + 1)) && !m.isDoor(p.getX(), (p.getY() + 1)))
                    {
                        p.move(ch);
                    }
                    else if(m.isDoor(p.getX(), (p.getY() + 1)))
                    {
                        m.newRoom('s');
                        p.relocate(p.getX(), 1);
                        roomcount++;
                        spawnMonsters();
                    }
                    break;
                case 'l':
                    if(!m.isWall((p.getX() + 1), p.getY()) && !m.isDoor((p.getX() + 1), p.getY()))
                    {
                        p.move(ch);
                    }
                    else if(m.isDoor((p.getX() + 1), p.getY()))
                    {
                        m.newRoom('e');
                        p.relocate(1, p.getY());
                        roomcount++;
                        spawnMonsters();
                    }
                    break;
            }            
            clear();
            mvaddch(p.getY(), p.getX(), p.getSymbol());
            for(int i = 0; i < _monster_vector.size(); i++)
            {
                if(_monster_vector[i].isDead() == false)
                {
                    _monster_vector[i].moveWorld(p);
                    mvaddch(_monster_vector[i].getY(), _monster_vector[i].getX(), _monster_vector[i].getSymbol());
                    move(0,0);
                }
                if(_monster_vector[i].getX() == p.getX() && _monster_vector[i].getY() == p.getY())
                {
                    battle b = battle(_monster_vector[i], p);
                    b.battleSequence();
                }
            }
            m.drawMap();
            printInfo();
            refresh();
            ch = getchar();
        }
        
        return;
    }
    
    void spawnMonsters()
    {
        _monster_vector.clear();
        _monster_vector.resize(0);
        
        int numOfEnemies = (rand() % 3) + 1;
        for (int i = 0; i < numOfEnemies; i++)
        {
            int randEnemy = (rand() % 3) + 1;
            
            if(randEnemy == 1)
            {
                monster temp1 = wolf();
                _monster_vector.push_back(temp1);
            }
            else if(randEnemy == 2)
            {
                monster temp = troll();
                _monster_vector.push_back(temp);
            }
            else if(randEnemy == 3)
            {
                monster temp = snake();
                _monster_vector.push_back(temp);
            }
        }
        
        for(int i = 0; i < _monster_vector.size(); i++)
        {
            int monX = (rand() % 53);
            int monY = (rand() % 19);
            
            _monster_vector[i].relocate(monX, monY);
            
            while(m.isWall(monX, monY) || m.isDoor(monX, monY))
            {
                monX = (rand() % 53);
                monY = (rand() % 19);
            }
            
            _monster_vector[i].relocate(monX, monY);
        }
        
    }
    
    ~game()
    {
        endwin();
    }
};



#endif /* GAME_H */

