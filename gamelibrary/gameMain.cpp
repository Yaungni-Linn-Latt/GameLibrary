#include"menu.h"

int main()
{
	
	try
	{
		Library lib=Library::load("data.bin");
		Menu(lib);
		lib.save("data.bin");
	}
	catch(int x)
	{
		if(x==404)
		{
			cerr<<"The file is not found";
		}
		if(x==415)
		{
			cerr<<"The file type is not allowed";
		}
		if(x=444)
		{
			cerr<<"Error saving file";
		}
	}
	
	
	return 0;

	
}