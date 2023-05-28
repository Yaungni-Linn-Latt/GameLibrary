#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<string>
#include<fstream>
#include <algorithm>
using namespace std;
#pragma once

typedef struct date
{
    int day,month,year;
    /* data */
}date;

void lowercase(string &s1, string &s2)
{
    std::transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    std::transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char c)
                   { return std::tolower(c); });
}

bool compare(string s1, string s2)
{
    lowercase(s1, s2);
    if (s1 == s2)
    {
        return true;
    }
    return false;
}

class Game
{
public:
    Game();
    Game(const Game& g);
    Game(string n,string d,date rd);
    virtual void display();
    virtual string getname();
    virtual string gettype();
    virtual void save(ofstream&)
    {
        return;
    }
    virtual void load(istream&)
    {
        return;
    }

    
protected:
    string name;
    string developer;
    date rdate;

};

#endif