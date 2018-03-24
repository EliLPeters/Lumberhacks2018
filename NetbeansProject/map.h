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
        drawBorder2();
        
    }
    
    void drawBorder()
    {
        for (int i = 0; i < LINES; i++)
        {
            move(i,0);
            addch('#');
        }
        for (int i = 0; i < COLS; i++)
        {
            move(0,i);
            addch('#');
        }
        for (int i = 0; i < COLS-1; i++)
        {
            move(LINES-1,i);
            addch('#');
        }
        for (int i = 0; i < LINES; i++)
        {
            move(i,COLS-1);
            addch('#');
        }
    }
    
    void drawBorder2()
    {
        for (int i = 0; i < 20; i++)
        {
            move(i,0);
            addch('#');
        }
        for (int i = 0; i < 20; i++)
        {
            move(0,i);
            addch('#');
        }
        for (int i = 0; i < 19; i++)
        {
            move(19,i);
            addch('#');
        }
        for (int i = 0; i < 20; i++)
        {
            move(i,19);
            addch('#');
        }
    }
    
    void drawObstacles()
    {
        
    }
    
    ~map()
    {
        
    }
};

#endif /* MAP_H */

