/* 
 * File:   unit.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 9:24 PM
 */

#ifndef UNIT_H
#define UNIT_H

#include <string>

using namespace std;

class unit
{
protected:
    
    int _HP = 0;
    int _DEX = 0;
    int _STR = 0;
    
    int _X = 0;
    int _Y = 0;
    
    string _name = "";
    
public:
    // Constructor
    unit()
    {
        
    }
    
    // Destructor
    ~unit()
    {
        
    }
    
    int getHP()
    {
        return _HP;
    }
    
    int changeHP(int change)
    {
        _HP -= change;
    }
    
    string getName()
    {
        return _name;
    }
    
    virtual void move(char ch)
    {
        
    }
    
    int getDEX()
    {
        return _DEX;
    }
    
    int getSTR()
    {
        return _STR;
    }
    
    int getX()
    {
        return _X;
    }
    
    int getY()
    {
        return _Y;
    }
};


#endif /* UNIT_H */

