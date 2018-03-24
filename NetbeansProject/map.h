/* 
 * File:   map.h
 * Authors: Eli Peters <ADD YOUR NAMES>
 * Project: Lumberhacks 2018 entry
 *
 * Created on March 23, 2018, 9:30 PM
 */

#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class map
{
private:
    
    vector<vector<vector <char> > > _nRooms; // Rooms which can be entered from the North
    vector<vector<vector <char> > > _eRooms; // Rooms which can be entered from the East
    vector<vector<vector <char> > > _sRooms; // Rooms which can be entered from the South
    vector<vector<vector <char> > > _wRooms; // Rooms which can be entered from the West
    
    vector< vector<char> > _cur_room;
    
public:
    map()
    {
        srand(time(NULL));
        ifstream read;
        read.open("NetbeansProject/rooms.txt");
        /*
        while(read.is_open() && read.good())
        {
            string line = "";
            getline(read, line);
            vector<char> curline;
            
            for(int i = 0; i < line.length(); i++)
            {
                curline.push_back(line.at(i));
            }
            _cur_room.push_back(curline);
        }
        */
        
        while(read.is_open() && read.good())
        {
            string directions;
            getline(read, directions);
            
            vector< vector<char> > new_room;
            
            for(int i = 0; i < 19; i++)
            {
                vector<char> cur_line;
                string feed;
                getline(read,feed);
                for(int j = 0; j < feed.length(); j++)
                {
                    cur_line.push_back(feed.at(j));
                }
                
                new_room.push_back(cur_line);
            }
            
            if(directions.at(0) == '1')
            {
                _nRooms.push_back(new_room);
            }
            if(directions.at(1) == '1')
            {
                _wRooms.push_back(new_room);
            }
            if(directions.at(2) == '1')
            {
                _sRooms.push_back(new_room);
            }
            if(directions.at(3) == '1')
            {
                _eRooms.push_back(new_room);
            }
            
            newRoom('e');
        }
        
        read.close();
    }
    
    void drawMap()
    {
        for(int i = 0; i < _cur_room.size(); i++)
        {
            for(int j = 0; j < _cur_room[i].size(); j++)
            {
                switch(_cur_room[i][j])
                {
                    case'#':
                    case '_':
                    case '|':
                        move(i, j);
                        addch(_cur_room[i][j]);
                }
            }
        }
    }
    
    void newRoom(char ch)
    {
        switch(ch)
        {
            case 'n':
                _cur_room = _nRooms[(rand() % _nRooms.size())];
                break;
            case 'e':
                _cur_room = _eRooms[(rand() % _eRooms.size())];
                break;
            case 's':
                _cur_room = _sRooms[(rand() % _sRooms.size())];
                break;
            case 'w':
                _cur_room = _wRooms[(rand() % _eRooms.size())];
                break;
            default:
                _cur_room = _nRooms[0];
        }
    }
    
    vector< vector<char> > getRoom()
    {
        return _cur_room;
    }
    
    bool isWall(int x, int y)
    {
        if(_cur_room[y][x] == '#')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isDoor(int x, int y)
    {
        if(_cur_room[x][y] == '_' || _cur_room[y][x] == '|')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    ~map()
    {
        
    }
};

#endif /* MAP_H */

