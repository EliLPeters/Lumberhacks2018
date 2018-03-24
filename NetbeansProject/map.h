/* 
 * File:   map.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 9:30 PM
 */

#ifndef MAP_H
#define MAP_H

using namespace std;

class map
{
public:
    map()
    {
        void drawMap();
    }
    
    void drawMap()
    {
        for (int i = 0; i < LINES; i++)
        {
            addch('#');
            move(i,0);
        }
        for (int i = 0; i < COLS; i++)
        {
            addch('#');
            move(0,i);
        }
        for (int i = 0; i < COLS-1; i++)
        {
            addch('#');
            move(LINES-1,i);
        }
        for (int i = 0; i < LINES; i++)
        {
            addch('#');
            move(i,COLS-1);
        }
        
        
    }
    
    ~map()
    {
        
    }
};

#endif /* MAP_H */

