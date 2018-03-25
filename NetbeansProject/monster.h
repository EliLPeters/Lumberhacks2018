/* 
 * File:   monster.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 9:25 PM
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "unit.h"

using namespace std;

class monster : public unit
{
public:
    
    void relocate(int x, int y)
    {
        _X = x;
        _Y = y;
    }
    
    bool isDead()
    {
        if(_HP <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void damage(int dam)
    {
        _HP -= dam;
    }
    
    monster()
    {
        
    }
    
    ~monster()
    {
        
    }
    
    void attack(unit &player)
    {
        //player.changeHP(_damage);
    }
    
    virtual void moveRand(unit myMonster)
    {
        int direction;
        
            int row = 10;
            int col = 10;
            char guy = myMonster.getSymbol();
            mvaddch(row,col,guy);
            direction = (rand() % 4 + 1);
            
            
            if(direction == 1)
            {
                clear();
                if(row > 1) {row--;}
                   
                
                mvaddch(row,col,guy);
                //m.drawMap();
            }
            else if(direction == 2)
            {
                clear();
                if (row < LINES-2) {row++;}
                
                mvaddch(row,col,guy);
                //m.drawMap();
            }
            else if (direction == 3)
            {
                clear();
                if (col < COLS-2){col++;}
                
                mvaddch(row,col,guy);
                //m.drawMap();
            }
            else if(direction == 4)
            {
                clear();
                if (col > 1) {col--;}  
                
                mvaddch(row,col,guy);
                //m.drawMap();
            }
            else
            {
                
            }
            refresh();
    }
    
    
};

class wolf : public monster
{
public:
    wolf()
    {
        _HP = 25;
        _attack = 10;
        _symbol = 'W';
        _name = "Wolf";

    }
};

class troll : public monster
{
public:
    troll()
    {
        _HP = 15;
        _attack = 5;
        _symbol = 'T';
        _name = "Troll";
    }
    
};

class snake : public monster
{
public:
    snake()
    {
        _HP = 20;
        _attack = 20;
        _symbol = 'S';
        _name = "Snake";

    }
    
};

#endif /* MONSTER_H */