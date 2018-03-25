/* 
 * File:   player.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 9:25 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "monster.h"

using namespace std;

class player : public unit
{
public:
    // Constructor
    player(string sName)
    {
        _symbol = '@';
        _name = sName;
        _X = 10;
        _Y = 10;
    }
    
    // Destructor
    ~player()
    {
        
    }
    
    void attack(monster& enemy)
    {
        enemy.changeHP(0);
        changeHP(enemy.damage());
    }
    
    void move(int ch)
    {
        switch(ch)
        {
            case 'i':
                _Y -= 1;
                break;
            case 'j':
                _X -= 1;
                break;
            case 'k':
                _Y += 1;
                break;
            case 'l':
                _X += 1;
                break;
        }
            
    }
    
    void relocate(int x, int y)
    {
        _X = x;
        _Y = y;
    }
};


#endif /* PLAYER_H */

