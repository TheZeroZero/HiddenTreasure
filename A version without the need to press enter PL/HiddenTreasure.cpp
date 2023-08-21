#include "Point.hpp"
#include <conio.h>

using namespace std;

class playerOptions
{
	char map[16][16] = {
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{'#', 'S', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'}, // S - start
	{'#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
	{'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#'}, 
	{'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', '#'}, 
	{'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#'}, 
	{'#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#'}, 
	{'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '$'}, //8th floor
	{'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#'}, 
	{'#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#'}, 
	{'#', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', '#'}, 
	{'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'}, 
	{'#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'}, 
	{'#', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#'}, 
	{'#', 'O', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, // 0 - exit
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} }; 
	Point player;
	bool hasSecret = false;
public:
	void setPlayer(int initX, int initY);
	void Display();
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
};

void playerOptions::setPlayer(int initX, int initY)
{
	player.setX(initX);
	player.setY(initY);
}

void playerOptions::Display()
{
	int fov = 1; // 1 is the default
	for(int y = -fov; y <= fov; y++)
	{
		for(int x = -fov; x <= fov; x++)
		{
			if(y != 0 || x !=0)
				cout<<map[player.getY()+y][player.getX()+x]<<" ";
			else
				cout<<"i ";
		}
		cout<<endl;
	}

}

void playerOptions::moveUp()
{
	if(map[player.getY() - 1][player.getX()] != '#')
	{
		player.setY(player.getY() - 1);
		if(map[player.getY()][player.getX()] == 'O')
		{
			cout<<"\nWYGRALES, ZNALAZLESC WYJSCIE!\nWpisz Q, zeby zakonczyc.\n";
			if(hasSecret == true)
				cout<<"Dodatkowo udalo ci sie odnalesc ukryty skarb! Brawo! :)\n";
		}
	}
}

void playerOptions::moveRight()
{
	if(map[player.getY()][player.getX() + 1] != '#' || (player.getY() == 7 && player.getX() == 13))
	{
		player.setX(player.getX() + 1);
		if(map[player.getY()][player.getX()] == 'O')
		{
			cout<<"\nWYGRALES, ZNALAZLESC WYJSCIE!\nWpisz Q, zeby zakonczyc.\n";
			if(hasSecret == true)
				cout<<"Dodatkowo udalo ci sie odnalesc ukryty skarb! Brawo! :)\n";
		}
		if(map[player.getY()][player.getX()] == '$')
		{
			cout<<"Znalazles tajemnicza monete.\n";
			hasSecret = true;
		}
	}
}

void playerOptions::moveLeft()
{
	if(map[player.getY()][player.getX() - 1] != '#' || (player.getY() == 7 && player.getX() == 15))
	{
		player.setX(player.getX() - 1);
		if(map[player.getY()][player.getX()] == 'O')
		{
			cout<<"\nWYGRALES, ZNALAZLESC WYJSCIE!\nWpisz Q, zeby zakonczyc.\n";
			if(hasSecret == true)
				cout<<"Dodatkowo udalo ci sie odnalesc ukryty skarb! Brawo! :)\n";
		}
	}
}

void playerOptions::moveDown()
{
	if(map[player.getY() + 1][player.getX()] != '#')
	{
		player.setY(player.getY() + 1);
		if(map[player.getY()][player.getX()] == 'O')
		{
			cout<<"\nWYGRALES, ZNALAZLESC WYJSCIE!\nWpisz Q, zeby zakonczyc.\n";
			if(hasSecret == true)
				cout<<"Dodatkowo udalo ci sie odnalesc ukryty skarb! Brawo! :)\n";
		}
	}
}

int main()
{	
	char input;
	playerOptions pOptions;
	pOptions.setPlayer(1, 1);
	cout<<endl;
	pOptions.Display();
	cout<<"\ni - Gracz.\n# - Sciana.\nS - Start.\nO - Wyjscie.\n Zeby sie poruszac wpisz A, W, S lub D. A jezeli chcesz wyjsc - Q:";
	do {
	input = _getch();
	switch(input)
		{
		case 'W':
		case 'w':
			pOptions.moveUp();
			pOptions.Display();
			break;
		case 'D':
		case 'd':
			pOptions.moveRight();
			pOptions.Display();
			break;
		case 'S':
		case 's':
			pOptions.moveDown();
			pOptions.Display();
			break;
		case 'A':
		case 'a':
			pOptions.moveLeft();
			pOptions.Display();
			break;
		case 'Q':
		case 'q':
			cout<<"\nGra zostala wylaczona.\n";
			break;
		default:
			cout<<"Nie ma takiej opcji. Sprobuj ponownie.\n";
		}
	} while(!((input == 'Q')||(input == 'q')));
		return 0;
}