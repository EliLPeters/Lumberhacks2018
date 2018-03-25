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
#include <string>
#include "player.h"
#include "monster.h"
#include "map.h"


using namespace std;

class battle
{
public:
    
    battle(monster &mons, player &playr)
    {
        plr = &playr;
        mon = &mons;
    }

    
    void drawBattleField()
    {
        for (int i = 0; i < COLS-1; i++)
        {
            addch('#');
            move(0,i);
        }
        for (int i = 0; i < COLS-1; i++)
        {
            addch('#');
            move(LINES-1,i);
        }        
        for (int i = 0; i < LINES-1; i++)
        {
            addch('#');
            move(i,0);
        }        
        for (int i = 0; i < LINES-1; i++)
        {
            addch('#');
            move(i,COLS-1);
        }
    }
    
    void moveMonster(int &posX, int &posY,bool &flipX, bool &flipY)
    {
        usleep(70000);
        mvaddch(posY,posX,mon->getSymbol());
        
        //Side to side movement
        
        if (flipX == true)
        {
            if(chaX > posX)
            {
                if(posX < COLS){posX++;}
            }
            else
            {
                if(posX > 0){posX--;}
            }
        }
        else
        {
            if(chaX > posX)
            {
                if(posX > 0){posX--;}
            }
            else
            {
                if(posX < COLS){posX++;}
            }   
        }
        
        //Up and down movement
        if (flipY == true)
        {
           if(chaY > posY)
            {
                if(posY < LINES-2){posY++;}
            }
            else
            {
                if(posY > 0){posY--;}
            } 
        }
        else
        {
            if(chaY > posX)
            {
                if(posY > 0){posY--;}
            }
            else
            {
                if(posY < LINES-2){posY++;}
            }
        }
        
        monsterAttack(posY,posX);
        
    }
    
    void monsterAttack(int posY,int posX)
    {
        if(posY == chaX && posX == chaY)
        {
            atkCtr++;
        }
        if(posY == chaY && posX == chaX)
        {
            atkCtr++;
        }
        
        if(atkCtr > 3)
        {
            plr->damage(mon->getAttack());
            mvaddch(chaX,chaY,'X');
            refresh();
            atkCtr = 0;
        }
        
    }
    
    void moveChar(int &chaX, int &chaY, char &dir )
    {
        char guy = '@';
        char ch = getch();
        
        if(ch == 'i')
            {
                if(chaX > 1) {chaX--;}
                dir = 'u';
                mvaddch(chaX,chaY,guy);
                //m.drawMap();
            }
            else if(ch == 'k')
            {
                if (chaX < LINES-2) {chaX++;}
                dir = 'd';
                mvaddch(chaX,chaY,guy);
                //m.drawMap();
            }
            else if(ch == 'l')
            {
                if (chaY < COLS-2){chaY++;}
                dir = 'r';
                mvaddch(chaX,chaY,guy);
                //m.drawMap();
            }
            else if(ch == 'j')
            {
                if (chaY > 1) {chaY--;}  
                dir = 'l';
                mvaddch(chaX,chaY,guy);
                //m.drawMap();
            }
            else if (ch == 'a')
            {
                playerAttack(dir);
            }
            else
            {
                mvaddch(chaX,chaY,guy);
            }
        
    }
    
    void battleSequence()
    {
        char ch;
        int ctr = 0;
        srand(time(NULL));
        
        while(plr->getHP() > 0 && mon->getHP() > 0)
        {
            ch = getch();
            if(ch == 'q'){break;}
            
            clear();
            bgHelper();
            if(ctr > 50)
            {
                flipX = coinFlip();
                flipY = coinFlip();
            }
            if(ctr > 80)
            {
                flipX = true;
                flipY = true;
                ctr = 0;
            }
            
            drawBattleField();
            displayScore();
            moveMonster(posX,posY,flipX,flipY);
            moveChar(chaX,chaY,dir);
            refresh();
            ctr++;
        }
        
        if (mon->getHP() <= 0)
        {
            clear();
            bgHelper();
            printw("Aw yeah, it super dead");
            getch();
            refresh();
        }
        if (plr->getHP() <= 0)
        {
            clear();
            bgHelper();
            printw("HA! Whata Loser!");
            getch();
            refresh();
        }
        
        return;
    }
    
    bool coinFlip()
    {
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
    
    void playerAttack(char dir)
    {
        int arrwx = chaY, arrwy = chaX;
        
        switch(dir)
        {
            case 'u':
                while(arrwy > 0){
                   usleep(50000);
                    clear();
                    drawBattleField();
                    displayScore();
                    mvaddch(chaX,chaY,'@');
                    mvaddch(posY,posX,mon->getSymbol());
                    mvaddch(arrwy,arrwx,'|');
                    arrwy--;
                    refresh();
                }
                break;
                
            case 'd':
                while(arrwy < LINES){
                   usleep(50000);
                    clear();
                    drawBattleField();
                    displayScore();
                    mvaddch(chaX,chaY,'@');
                    mvaddch(posY,posX,mon->getSymbol());
                    mvaddch(arrwy,arrwx,'|');
                    arrwy++;
                    refresh();
                }
                break;
                
            case 'l':
                while(arrwx > 0){
                   usleep(20000);
                    clear();
                    drawBattleField();
                    displayScore();
                    mvaddch(chaX,chaY,'@');
                    mvaddch(posY,posX,mon->getSymbol());
                    mvaddch(arrwy,arrwx,'-');
                    arrwx--;
                    refresh();
                }
                break;
                
            case 'r':
                while(arrwx < COLS){
                   usleep(20000);
                    clear();
                    drawBattleField();
                    displayScore();
                    mvaddch(chaX,chaY,'@');
                    mvaddch(posY,posX,mon->getSymbol());
                    mvaddch(arrwy,arrwx,'-');
                    arrwx++;
                    refresh();
                }
                break;
        }
        
        if(dir == 'u' || dir == 'd')
        {
            doDamage(arrwx);
        }
        else
        {
            doDamage(arrwy);
        }
        
        return;
        
    }
    
    void doDamage(int prox)
    {
        switch(dir)
        {
            case 'u':
                if(posX == prox && chaX > posY)
                {
                    mvaddch(posY,posX,'X');
                    mon->damage(plr->getAttack());
                }
                break;
                
            case 'd':
                if(posX == prox && chaX < posY)
                {
                    mvaddch(posY,posX,'X');
                    mon->damage(plr->getAttack());
                }
                break;
                
            case 'l':
                if(posY == prox && chaY > posX)
                {
                    mvaddch(posY,posX,'X');
                    mon->damage(plr->getAttack());
                }
                break;
                
            case 'r':
                if(posY == prox && chaY < posX)
                {
                    mvaddch(posY,posX,'X');
                    mon->damage(plr->getAttack());
                }
                break;
                
            default:
                break;
                
        }
        
        return;
    }
    
    void displayScore()
    {
        string ps = plr->getName();
        ps += ": ";
        ps += to_string(plr->getHP());
        string es = mon->getName();
        es += ": ";
        es += to_string(mon->getHP());
        move(1,5);
        printw(ps.c_str());
        move(1,20);
        printw(es.c_str());    
    }
    
    void bgHelper()
    {
        attron(COLOR_PAIR(1));
        for(int i = 0; i < LINES; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                mvaddch(i,j,' ');
            }
        }
    }
    
    
private:
    map m = map();
    player* plr;
    monster* mon;
    int posX = 0;
    int posY = 10;
    int chaX = 10;
    int chaY = 60;
    bool flipX = true;
    bool flipY = true;
    int atkCtr = 0;
    char dir = 'u';
};

#endif /* BATTLE_H */

