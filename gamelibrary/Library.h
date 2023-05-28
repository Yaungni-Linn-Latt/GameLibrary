#ifndef LIBRARY_H
#define LIBRARY_H

#include<iostream>
#include <string>
#include <fstream>
#include "Game.h"
#include "gametypes.h"
using namespace std;
#pragma once

class Library
{

public:
    Library();
    Library(const Library& l);
    ~Library();
    void addgame(Game* g);
    void delgame(string gname);
    void search(string s)const;
    void showgenre(string s)const;
    void showgame()const;
    int gamenum();
    bool isin(string s);
    static void showgenre();
    void edit();
    void save(const string &filename) const;
    static Library load(const string &filename);
    void operator+=(Game *g);
    void operator-=(string gname);
private:

    int gameNum;
    Game** pData;

};

#endif