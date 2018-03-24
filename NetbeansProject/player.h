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
    // Constructor
    player(string sName)
    {
        _name = sName;
    }
    
    // Destructor
    ~player()
    {
        
    }
    
    void attack(monster enemy)
    {
        enemy.changeHP(0);
        changeHP(enemy.damage());
    }
};


#endif /* PLAYER_H */

