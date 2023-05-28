#include "Game.h"

Game::Game(){}

Game::Game(const Game& g)
{
    *this = g;
}
Game::Game(string n,string d,date rd):name(n),developer(d),rdate(rd){}

void Game::display()
{
    // cout<<"The info::\nName::"<<name<<"\nDeveloper::"<<developer
    //     <<"\nReleased Date::"<<rdate.day<<"/"<<rdate.month<<"/"<<rdate.year<<endl;
    return;
}


string Game::getname()
{
    return 0;
}

string Game::gettype()
{
    return 0;
}