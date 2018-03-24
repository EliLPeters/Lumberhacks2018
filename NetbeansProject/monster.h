/* 
 * File:   monster.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 9:25 PM
 */

#ifndef MONSTER_H
#define MONSTER_H

using namespace std;

class monster : public unit
{
public:
    monster(string sName, int sHP)
    {
        _name = sName;
        _HP = sHP;
    }
    
    ~monster()
    {
        
    }
    
    int damage()
    {
        
    }
};


#endif /* MONSTER_H */

