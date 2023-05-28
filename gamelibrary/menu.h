#include "Library.h"
#include "Library.cpp"
#include "Game.h"
#include "Game.cpp"
#include "gametypes.h"
#include <iostream>
#include <stdexcept>
#include<limits>

void addgame(Library &lib)
{
	string n;
	string t;
	string d;
	int day, month, year;
	Library::showgenre();
	cout << "Enter info about the game:" << endl;
	cout << "Name:";
	cin.ignore(); // to ignore white space after cin
	getline(cin, n);
	cout << "Type:";
	cin >> t;
	cout << "Developer:";
	cin.ignore();
	getline(cin, d);
	cout << "Day Month Year(Format dd mm yyyy):";
	cin >> day >> month >> year;

	if ((day <= 0 || day > 31) || (month < 1 || month > 12) || year < 1962)
	{
		cerr << "write appropriate date" << endl;
		return;
	}

	if (compare(t, "action"))
	{
		// lib.addgame(new Action(n,d,{day,month,year}));
		lib += new Action(n, d, {day, month, year});
	}
	else if (compare(t, "openworld"))
	{
		// lib.addgame(new Openworld(n,d,{day,month,year}));
		lib += new Openworld(n, d, {day, month, year});
	}
	else if (compare(t, "RPG"))
	{
		// lib.addgame(new Rpg(n,d,{day,month,year}));
		lib += new Rpg(n, d, {day, month, year});
	}
	else if (compare(t, "Shooter"))
	{
		// lib.addgame(new Shooter(n,d,{day,month,year}));
		lib += new Shooter(n, d, {day, month, year});
	}
	else if (compare(t, "moba"))
	{
		// lib.addgame(new Moba(n,d,{day,month,year}));
		lib += new Moba(n, d, {day, month, year});
	}
	else
	{
		cerr << "Choose only from the given types" << endl;
	}
}

void deleteGame(Library &lib)
{
	string s;
	cout << "Enter the name of the game to delete" << endl;
	cin.ignore();
	getline(cin, s);
	// lib.delgame(s);
	lib -= s;
}

void search(const Library &lib)
{
	string s;
	cout << "Enter the name of the game to search" << endl;
	cin.ignore();
	getline(cin, s);
	lib.search(s);
}
void showGenre(const Library &lib)
{
	string s;
	cout << "Enter the type of the game to search" << endl;
	cin >> s;
	lib.showgenre(s);
}

void Menu(Library &lib)
{
	int in;
	cout << "Welcome From the Game Library" << endl;
	while (1)
	{
		cout << "\nPress 0 to exit the library\n"
			 << "Press 1 to add game\n"
			 << "Press 2 to delete game\n"
			 << "Press 3 to search game\n"
			 << "Press 4 to show all the games\n"
			 << "Press 5 to show the game of the search genre\n"
			 << "Press 6 to edit the game" << endl;
		cin >> in;
		if (std::cin.fail())
		{
			std::cin.clear();
    		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cerr<<"Type only the number shown on the menu."<<endl;
		}
		else
		{
			switch (in)
			{
			case (0):
				return;
				break;
			case (1):
				addgame(lib);
				break;
			case (2):
				deleteGame(lib);
				break;
			case (3):
				search(lib);
				break;
			case (4):
				lib.showgame();
				break;
			case (5):
				showGenre(lib);
				break;
			case (6):
				lib.edit();
				break;
			default:
				cerr << "Enter number according to the Menu" << endl;
			}
		}
	}
}