/* 
 * File:   game.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 7:44 PM
 */

#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>

#include "map.h"
#include "unit.h"
#include "monster.h"
#include "player.h"
#include "battle.h"

using namespace std;

class game
{
private:
    bool _terminate = false;
    map m = map();
    int roomcount;
    int score;
    player p;
    
    bool endgame;
    
    vector<monster> _monster_vector;
    
public:
    game()
    {
        srand(time(NULL));
        initscr();
        clear();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        nodelay(stdscr, FALSE);
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_RED, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        curs_set(0);
        //refresh();
        while(_terminate == false)
        {
            mainMenu();
        }
    }
    
    void mainMenu()
    {
        int choice = 0;
        string welcome = "Welcome! press any key to continue!";
        move(0,((COLS / 2) - (welcome.length() / 2)));
        attron(COLOR_PAIR(1));
        printw(welcome.c_str());
        refresh();
        getch();
        clear();
        bgHelper();
        while(_terminate == false)
        {
            move(0,0);
            printw("  Play");
            move(2,0);
            printw("  High Scores");
            move(4,0);
            printw("  About");
            move(6,0);
            printw("  Quit");
            mvaddch((choice * 2), 0, '>');
            refresh();
            int ch = getch();
            if(ch == 'i')
            {
                if(choice > 0)
                {
                    choice--;
                }
            }
            else if(ch == 'k')
            {
                if(choice < 3)
                {
                    choice ++;
                }
            }
            
            else if(ch == 10)
            {
                switch(choice)
                {
                    case 0:
                        createPlayer();
                        play();
                        break;
                    case 1:
                        getHigh();
                        break;
                    case 2:
                        getInfo();
                        break;
                    case 3:
                        _terminate = true;
                        return;
                        break;
                }
            }
        }
    }
    
    void printInfo()
    {
        
        attron(COLOR_PAIR(2));
        move(19,0);
        printw("Name: ");
        printw(p.getName().c_str());
        printw("\tScore: ");
        string temp = to_string(score);
        printw(temp.c_str());
        printw("\tHP: ");
        temp = to_string(p.getHP());
        printw(temp.c_str());
        attron(COLOR_PAIR(1));
        refresh();
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
    
    void play()
    {
        roomcount = 1;
        score = 0;
        
        mvaddch(p.getY(), p.getX(), p.getSymbol());
        m.drawMap();
        spawnMonsters();
        refresh();
        int ch = getchar();
        endgame = false;
        while(endgame == false)
        {
            switch(ch)
            {
                case 'x':
                    clear();
                    bgHelper();
                    refresh();
                    terminate();
                    return;
                case 'i':
                    if(!m.isWall(p.getX(), (p.getY() - 1)) && !m.isDoor(p.getX(), (p.getY() - 1)))
                    {
                        p.move(ch);
                    }
                    else if(m.isDoor(p.getX(), (p.getY() - 1)))
                    {
                        m.newRoom('n');
                        p.relocate(p.getX(), 17);
                        spawnMonsters();
                    }
                    break;
                case 'j':
                    if(!m.isWall((p.getX() - 1), p.getY()) && !m.isDoor((p.getX() - 1), p.getY()))
                    {
                        p.move(ch);
                    }
                    else if(m.isDoor((p.getX() - 1), p.getY()))
                    {
                        m.newRoom('w');
                        p.relocate(51, p.getY());
                        spawnMonsters();
                    }
                    break;
                case 'k':
                    if(!m.isWall(p.getX(), (p.getY() + 1)) && !m.isDoor(p.getX(), (p.getY() + 1)))
                    {
                        p.move(ch);
                    }
                    else if(m.isDoor(p.getX(), (p.getY() + 1)))
                    {
                        m.newRoom('s');
                        p.relocate(p.getX(), 1);
                        spawnMonsters();
                    }
                    break;
                case 'l':
                    if(!m.isWall((p.getX() + 1), p.getY()) && !m.isDoor((p.getX() + 1), p.getY()))
                    {
                        p.move(ch);
                    }
                    else if(m.isDoor((p.getX() + 1), p.getY()))
                    {
                        m.newRoom('e');
                        p.relocate(1, p.getY());
                        spawnMonsters();
                    }
                    break;
            }            
            clear();
            bgHelper();
            attron(COLOR_PAIR(3));
            mvaddch(p.getY(), p.getX(), p.getSymbol());
            attron(COLOR_PAIR(1));
            int live = 0;
            bool killed = false;
            for(int i = 0; i < _monster_vector.size(); i++)
            {
                if(_monster_vector[i].isDead() == false)
                {
                    live++;
                    _monster_vector[i].moveWorld(p);
                    attron(COLOR_PAIR(4));
                    mvaddch(_monster_vector[i].getY(), _monster_vector[i].getX(), _monster_vector[i].getSymbol());
                    attron(COLOR_PAIR(1));
                    if(_monster_vector[i].getX() == p.getX() && _monster_vector[i].getY() == p.getY())
                    {
                        battle b = battle(_monster_vector[i], p);
                        b.battleSequence();
                        nodelay(stdscr, FALSE);
                        if(p.isDead())
                        {
                            terminate();
                        }
                        else{
                            killed == true;
                            score++;
                            live--;
                        }
                    }
                }
                
            }
            if(live == 0 && killed == true)
            {
                roomcount++;
            }
            m.drawMap();
            printInfo();
            refresh();
            ch = getchar();
        }
        
        return;
    }
    
    void spawnMonsters()
    {
        _monster_vector.clear();
        _monster_vector.resize(0);
        
        int numOfEnemies = (rand() % 3) + 1;
        for (int i = 0; i < numOfEnemies; i++)
        {
            int randEnemy = (rand() % 3) + 1;
            
            if(randEnemy == 1)
            {
                monster temp1 = wolf();
                _monster_vector.push_back(temp1);
            }
            else if(randEnemy == 2)
            {
                monster temp = troll();
                _monster_vector.push_back(temp);
            }
            else if(randEnemy == 3)
            {
                monster temp = snake();
                _monster_vector.push_back(temp);
            }
        }
        
        for(int i = 0; i < _monster_vector.size(); i++)
        {
            int monX = (rand() % 53);
            int monY = (rand() % 19);
            
            _monster_vector[i].relocate(monX, monY);
            
            while(m.isWall(monX, monY) || m.isDoor(monX, monY))
            {
                monX = (rand() % 53);
                monY = (rand() % 19);
            }
            
            _monster_vector[i].relocate(monX, monY);
        }
        
    }
    
    void terminate()
    {
        clear();
        endgame = true;
        exitHelper();
    }
    
    void createPlayer()
    {
        clear();
        bgHelper();
        move(0,0);
        printw("Enter your name: ");
        refresh();
        int ch = 0;
        string temp;
        while(ch != 10 && ch != 13 && ch != KEY_ENTER)
        {
            ch = getchar();
            
            if(ch != 10 && ch != 13 && ch != KEY_ENTER)
            {
                char c = ch;
                temp += c;
                addch(ch);
                refresh();
            }
        }
        
        p = player(temp);
    }
    
    void getHigh()
    {
        ifstream in;
        in.open("highscores.txt");
        
        string hName = "";
        int hScore = 0;
        
        string hRoom = "";
        
        if(in.is_open() && in.good())
        {
            getline(in, hName);
        }
        while(in.is_open() && in.good())
        {
            string tempName;
            getline(in, tempName);
            string tempScore;
            getline(in, tempScore);
            string tempRoom;
            getline(in, tempRoom);
            if(stoi(tempScore) > hScore)
            {
                hName = tempName;
                hScore = stoi(tempScore);
                hRoom = tempRoom;
            }
        }
        
        clear();
        bgHelper();
        move(0,0);
        printw("High Score: ");
        printw(hName.c_str());
        string temp = to_string(hScore);
        move(1,0);
        printw(temp.c_str());
        printw(" points");
        move(2,0);
        printw(hRoom.c_str());
        printw(" rooms cleared");
        getch();
        clear();
        bgHelper();
        
        in.close();
    }
    
    void getInfo()
    {
        clear();
        bgHelper();
        move(0,0);
        printw("Objective is to kill as many monsters as possible.");
        move(1,0);
        printw("Use IJKL to move.  When in combat use A to shoot.");
        move(2,0);
        printw("Bullets will travel in last direction you moved.");
        getch();
        clear();
        bgHelper();
    }
    
    void exitHelper()
    {
        ofstream out;
        out.open("highscores.txt", ios::app);
        
        out << endl << p.getName() << endl << score << endl << roomcount;
        
        out.close();
    }
    
    ~game()
    {
        endwin();
    }
};



#endif /* GAME_H */

