/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   battle.h
 * Author: melanos
 *
 * Created on March 24, 2018, 11:06 AM
 */

#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include "player.h"
#include "monster.h"
#include "map.h"


using namespace std;

class battle
{
public:
    

    battle(monster mons, player playr)
    {
        plr = playr;
        mon = mons;
    }
    
    void drawBattleField()
    {
        
        m.drawBorder();
    }
    
    void moveMonster(int &posX, int &posY,bool &flipX, bool &flipY)
    {
        usleep(50000);
        mvaddch(posX,posY,'$');
        
        //Side to side movement
        
        if (flipX == true)
        {
            if(chaX > posX)
            {
                posX++;
            }
            else
            {
                posX--;
            }
        }
        else
        {
            if(chaX > posX)
            {
                posX--;
            }
            else
            {
                posX++;
            }   
        }
            
        if (posY > COLS)
        {
            flipX = false;
        }
        if (posY < 1)
        {
            flipX = true;
        }
        
        //Up and down movement
        if (flipY == true)
        {
            posX++;
            
        }
        else
        {
            posX--;
        }
            
        if (posX > LINES-1)
        {
            flipY = false;
        }
        if (posX < 1)
        {
            flipY = true;
        }
        
        
    }
    
    void moveChar(int &chaX, int &chaY)
    {
        char guy = '@';
        
        char ch = getch();
        
        if(ch == 'i')
            {
                if(chaX > 1) {chaX--;}
                   
                
                mvaddch(chaX,chaY,guy);
                //m.drawMap();
            }
            else if(ch == 'k')
            {
                if (chaX < LINES-2) {chaX++;}
                
                mvaddch(chaX,chaY,guy);
                //m.drawMap();
            }
            else if(ch == 'l')
            {
                if (chaY < COLS-2){chaY++;}
                
                mvaddch(chaX,chaY,guy);
                //m.drawMap();
            }
            else if(ch == 'j')
            {
                if (chaY > 1) {chaY--;}  
                
                mvaddch(chaX,chaY,guy);
                //m.drawMap();
            }
            else
            {
                mvaddch(chaX,chaY,guy);
            }
        
        
    }
    
    void battleSequence()
    {
        char ch;
        int ctrA = 0, ctrB = 0;
        posX = randGen();
        posY = randGen();
        
        while(true)
        {
            ch = getch();
            if(ch == 'q')
            {
                break;
            }
            
            if(ctrA > randGen())
            {
                flipX = coinFlip();
                ctrA = 0;
            }
            else if(ctrB > randGen())
            {
                flipY = coinFlip();
                ctrB = 0;
            }
            
            clear();
            drawBattleField();
            moveMonster(posX,posY,flipX,flipY);


            moveChar(chaX,chaY);
            ctrA++;
            ctrB++;
            refresh();
        }
        
        return;
    }
    
    bool coinFlip()
    {
        srand(time(NULL));
        int flipTimes = rand() % 20;
        int coinFlip;
        
        for(int i = 0; i < flipTimes; i++)
        {
            coinFlip = rand() % 2 + 1;
        }
        
        if (coinFlip == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    int randGen()
    {
       srand (time(NULL));
       
       int rnum = rand() % 20 + 1;
       rnum = rand() % rnum + 1;
       rnum = rand() % rnum + 1;
       
       return rnum;
    }
    
    
private:
    map m = map();
    player plr = player();
    monster mon = monster();
    int posX = 5;
    int posY = 5;
    int chaX = 5;
    int chaY = 7;
    bool flipX = true;
    bool flipY = true;
};

#endif /* BATTLE_H */

