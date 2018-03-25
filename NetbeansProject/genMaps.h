/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genMaps.h
 * Author: Eli Peters 
 *          John Mackin
 *          David Shapiro
 *
 * Created on March 24, 2018, 6:25 PM
 */

#ifndef GENERATEMAPS_H
#define GENERATEMAPS_H

//53 x 19
#include <fstream>
#include <string>
using namespace std;

string myMap[][53] = 
{
    {"########################____#########################"},
    {"#                                                   #"},
    {"#                                                   #"},
    {"#                                                   #"},    
    {"#                                                   #"},    
    {"#                                                   #"},    
    {"#                                                   #"},   
    {"#                                                   #"},    
    {"|                                                   |"},   
    {"|                                                   |"}, 
    {"|                                                   |"}, 
    {"#                                                   #"},
    {"#                                                   #"},
    {"#                                                   #"},
    {"#                                                   #"},
    {"#                                                   #"},
    {"#                                                   #"},
    {"#                                                   #"},
    {"########################____#########################"}
};




string addDoors()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (myMap[25][18] == "_"){a = 1;};
    if (myMap[52][8] == "_"){b = 1;};
    if (myMap[25][0] == "_"){c = 1;};
    if (myMap[0][8] == "_"){d = 1;};
    
    string ret = "";
    ret += a;
    ret += b;
    ret += c;
    ret += d;
    
    return ret;
}

void outputMap()
{
    ofstream myfile("NetbeansProject/rooms1.txt");
    
    int rows = sizeof myMap/ sizeof myMap[0];
    int cols = sizeof myMap[0]/ sizeof(int);
    
    if (myfile.is_open())
    {
        for(int i = 0; i < 53; i++)
        {
            for (int j = 0; j < 19; j++)
            {
                if (((i == 24)||(i == 25)||(i == 26)||(i == 27))&&(j == 0))
                {
                    if (false)//(rand() % 2)
                    {
                        myfile << "_" << endl;
                    }else
                    {
                        myfile << " " << endl;
                    }
                }
                else
                {
                    myfile << myMap[j][i] << endl;
                }
            }
        } 
    }
    
    myfile.close();
}

void addMap()
{
    
}

#endif /* GENERATEMAPS_H */

