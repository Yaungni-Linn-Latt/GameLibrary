#ifndef RPG_H
#define RPG_H

#pragma once
#include "Game.h"

class Rpg: public Game
{
public:
    Rpg() {}
    Rpg(string n, string d, date rd):Game(n,d,rd)
    {
        type = "Rpg";
    }
    Rpg(const Rpg &a)
    {
        *this = a;
    }

    void display()
    {
        cout << "The info::\nName::" << name << "\nGenre::" << type << "\nDeveloper::" << developer
             << "\nReleased Date::" << rdate.day << "/" << rdate.month << "/" << rdate.year << endl;
    }
    
    string getname()
    {
        return name;
    }
    string gettype()
    {
        return type;
    }

    void save(ofstream& output)
    {

        size_t typesize = type.size();
        output.write(reinterpret_cast<const char *>(&typesize), sizeof(typesize));
        output.write(type.c_str(), typesize);

        size_t typesize1 = type.size();
        output.write(reinterpret_cast<const char *>(&typesize1), sizeof(typesize1));
        output.write(type.c_str(), typesize1);


        size_t nameSize = name.size();
        output.write(reinterpret_cast<const char *>(&nameSize), sizeof(nameSize));
        output.write(name.c_str(), nameSize);

        size_t developerSize = developer.size();
        output.write(reinterpret_cast<const char *>(&developerSize), sizeof(developerSize));
        output.write(developer.c_str(), developerSize);

        output.write(reinterpret_cast<const char *>(&rdate), sizeof(rdate));
        
    }

    void load(istream& input)
    {
        size_t typeSize;
        input.read(reinterpret_cast<char *>(&typeSize), sizeof(typeSize));
        char *typeBuffer = new char[typeSize + 1];
        input.read(typeBuffer, typeSize);
        typeBuffer[typeSize] = '\0';
        type = typeBuffer;
        delete[] typeBuffer;

        size_t nameSize;
        input.read(reinterpret_cast<char *>(&nameSize), sizeof(nameSize));
        char *nameBuffer = new char[nameSize + 1];
        input.read(nameBuffer, nameSize);
        nameBuffer[nameSize] = '\0';
        name = nameBuffer;
        delete[] nameBuffer;

        size_t developerSize;
        input.read(reinterpret_cast<char *>(&developerSize), sizeof(developerSize));
        char *developerBuffer = new char[developerSize + 1];
        input.read(developerBuffer, developerSize);
        developerBuffer[developerSize] = '\0';
        developer = developerBuffer;
        delete[] developerBuffer;

        input.read(reinterpret_cast<char *>(&rdate), sizeof(rdate));
    }

private:
    string type;
};

#endif