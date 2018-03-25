/* 
 * File:   player.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 9:25 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "unit.h"
#include "monster.h"

using namespace std;

class player : public unit
{
public:
    // Constructor
    player()
    {
        _symbol = '@';
        _HP = 20;
        _attack = 5;
        _name = "test";
        _X = 10;
        _Y = 10;
    }
    player(string sName)
    {
        _symbol = '@';
        _HP = 100;
        _attack = 5;
        _name = sName;
        _X = 10;
        _Y = 10;
    }
    
    // Destructor
    ~player()
    {
        
    }
    
    void damage(int dam)
    {
        _HP -= dam;
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

