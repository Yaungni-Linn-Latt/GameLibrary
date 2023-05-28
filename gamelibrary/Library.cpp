#include "Library.h"

Library::Library()
{
    gameNum = 0;
    pData = NULL;
}
Library::Library(const Library &l)
{
    gameNum = l.gameNum;
    pData = new Game *[gameNum];
    for (int i = 0; i < gameNum; i++)
    {
        pData[i] = l.pData[i];
    }
}

Library::~Library()
{
    for(int i=0;i<gameNum;i++)
    {
        delete pData[i];
        pData[i] = NULL;
    }
    delete[] pData;
    pData = NULL;
    gameNum = 0;

}
void Library::addgame(Game *g)
{
    if (isin(g->getname()))
    {
        return;
    }
    Game **temp = new Game *[gameNum + 1];
    for (int i = 0; i < gameNum; i++)
    {
        temp[i] = pData[i];
    }
    temp[gameNum] = g;
    delete[] pData;
    pData = temp;
    gameNum++;
}

void Library::operator+=(Game *g)
{
    addgame(g);
}


bool Library::isin(string s)
{
    for (int i = 0; i < gameNum; i++)
    {
        if (compare(pData[i]->getname(), s))
        {
            return true;
        }
    }
    return false;
}

void Library::delgame(string gname)
{
    if(gameNum==0)
    {
        cerr<<"There is no game to delete in this library!"<<endl;
        return;
    }
    if (!isin(gname))
    {
        cerr << "The game is not in the Library" << endl;
        return;
    }
    Game **temp = new Game *[gameNum - 1];
    for (int i = 0, j = 0; i < gameNum; i++)
    {
        if (!(compare(pData[i]->getname(), gname)))
        {
            temp[j++] = pData[i];
        }
    }
    delete[] pData;
    pData = temp;
    gameNum--;
}

void Library::operator-=(string gname)
{
    delgame(gname);
}

bool contain(string s1, string s2)
{
    lowercase(s1, s2);
    if (s1.find(s2) != string::npos)
    {
        return true;
    }
    return false;
}

void Library::search(string s) const
{
    unsigned int cnt = 0;
    for (int i = 0; i < gameNum; i++)
    {
        if (contain(pData[i]->getname(), s))
        {
            pData[i]->display();
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << "The searched game is not found" << endl;
    }
}

void Library::showgame() const
{
    for (int i = 0; i < gameNum; i++)
    {
        pData[i]->display();
        cout << "------------" << endl;
    }
}

void Library::showgenre(string s) const
{
    for (int i = 0; i < gameNum; i++)
    {
        if (contain(pData[i]->gettype(), s))
        {
            pData[i]->display();
            cout << "------------" << endl;
        }
    }
}

int Library::gamenum()
{
    return gameNum;
}

void Library::showgenre()
{
    cout << "Available Genres are::\nAction, Openworld, RPG, Shooter, MMORPG" << endl;
}

void Library::edit()
{
    string gname;
    cout << "Enter the name of the game to edit" << endl;
    cin.ignore();
    getline(cin, gname);
    if (!isin(gname))
    {
        cerr << "The game is not in the Library" << endl;
        return;
    }
    else
    {
        cout << "Enter the name:";
        string name;
        getline(cin, name);
        cout << "Type:";
        string t;
        cin >> t;
        cout << "Developer:";
        string d;
        cin.ignore();
        getline(cin, d);
        cout << "Day Month Year(Format dd mm yyyy):";
        int day, month, year;
        cin >> day >> month >> year;

        if ((day <= 0 || day > 31) || (month < 1 || month > 12) || year < 1962)
        {
            cerr << "write appropriate date" << endl;
            return;
        }

        int j;
        for (int i = 0; i < gameNum; i++)
        {
            if (contain(pData[i]->getname(), gname))
            {
                j=i;
            }
        }
        delete pData[j];
        if (compare(t, "action"))
        {
            Game* g = new Action(name,d,{day,month,year});
            pData[j] = g;
        }
        else if (compare(t, "openworld"))
        {
            Game* g = new Openworld(name,d,{day,month,year});
            pData[j] = g;  
        }
        else if (compare(t, "RPG"))
        {
            Game* g = new Rpg(name,d,{day,month,year});
            pData[j] = g;  
        }
        else if (compare(t, "Shooter"))
        {
            Game* g = new Shooter(name,d,{day,month,year});
            pData[j] = g;  
        }
        else if (compare(t, "moba"))
        {
             Game* g = new Moba(name,d,{day,month,year});
             pData[j] = g;  
        }
        else
        {
            cerr<<"Choose only from the given types"<<endl;
        }
        
    }
}

void Library::save(const string &filename) const
{
    if (!contain(filename, "bin"))
    {
        throw 415;
    }
    ofstream file(filename, ios::binary);
    if (file)
    {
        file.write(reinterpret_cast<const char *>(&gameNum), sizeof(gameNum));
        for (int i = 0; i < gameNum; i++)
        {
            pData[i]->save(file);
        }
        file.close();
    }
    else
    {
        throw 444;
    }
}

Library Library::load(const string &filename)
{
    Library l;
    ifstream file(filename, ios::binary);
    if (file)
    {
        file.read(reinterpret_cast<char *>(&l.gameNum), sizeof(l.gameNum));
        l.pData = new Game *[l.gameNum];
        for (int i = 0; i < l.gameNum; i++)
        {

            size_t typeSize;
            file.read(reinterpret_cast<char *>(&typeSize), sizeof(typeSize));
            char *typeBuffer = new char[typeSize + 1];
            file.read(typeBuffer, typeSize);
            typeBuffer[typeSize] = '\0';
            string type = typeBuffer;
            delete[] typeBuffer;

            if (type == "action")
            {
                l.pData[i] = new Action();
            }

            if (type == "MOBA")
            {
                l.pData[i] = new Moba();
            }
            if (type == "openworld")
            {
                l.pData[i] = new Openworld();
            }

            if (type == "Rpg")
            {
                l.pData[i] = new Rpg();
            }
            if (type == "Shooter")
            {
                l.pData[i] = new Shooter();
            }

            l.pData[i]->load(file);
        }
        file.close();
    }
    else
    {
        throw 404;
    }
    return l;
}
