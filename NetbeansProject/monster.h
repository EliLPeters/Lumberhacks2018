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
    
    monster()
    {
        
    }
    
    ~monster()
    {
        
    }
    
    void attack(unit &player)
    {
        player.changeHP(_damage);
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
        _damage = 10;
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
        _damage = 5;
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
        _damage = 20;
        _symbol = 'S';
        _name = "Snake";

    }
    
};

void createEnemies(vector<monster>& enemies)
{
    srand(time(NULL));
        int numOfEnemies = rand() % 3 + 1;
        for (int i = 0; i < numOfEnemies; i++)
        {
            int randEnemy = rand() % 3 + 1;
            
            if (randEnemy == 1)
            {
                monster temp = wolf();
                enemies.push_back(temp);
            }
            else if (randEnemy == 2)
            {
                monster temp = troll();
                enemies.push_back(temp);
            }
            else if (randEnemy == 3)
            {
                monster temp = snake();
                enemies.push_back(temp);
            }
        }
}

#endif /* MONSTER_H */