#include "Point.hpp"
using namespace std;

class playerOptions
{
	char map[16][16] = {
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{'#', 'S', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#', '#', '.', '#'}, // S - start
	{'#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '#'}, 
	{'#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', '#', '.', '#'}, 
	{'#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '.', '#'}, 
	{'#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#', '.', '#', '#'}, 
	{'#', '#', '#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '#'}, 
	{'#', '.', '#', '.', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '#'}, 
	{'#', '.', '.', '.', '#', '.', '#', '#', '.', '#', '#', '.', '#', '.', '#', '#'}, 
	{'#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', '#'}, 
	{'#', '.', '#', '.', '.', '.', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#'}, 
	{'#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#'}, 
	{'#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#', '.', '#'}, 
	{'#', '#', '#', '.', '#', '.', '.', '.', '#', '.', '#', '.', '.', '#', '.', '#'}, 
	{'#', 'O', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '#'}, // 0 - exit
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} }; 
	Point player;
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
	cout<<map[player.getY()-1][player.getX()-1]<<" ";
	cout<<map[player.getY()-1][player.getX()]<<" ";
	cout<<map[player.getY()-1][player.getX()+1]<<" ";
	cout<<endl;
	cout<<map[player.getY()][player.getX()-1]<<" ";
	// cout i (the player), instead of:
	// "cout<<(player.getX())<<(player.getY());"
	cout<<"i ";
	cout<<map[player.getY()][player.getX()+1]<<" ";
	cout<<endl;
	cout<<map[player.getY()+1][player.getX()-1]<<" ";
	cout<<map[player.getY()+1][player.getX()]<<" ";
	cout<<map[player.getY()+1][player.getX()+1]<<" ";
	cout<<endl;
}

void playerOptions::moveUp()
{
	if(map[player.getY() - 1][player.getX()] != '#')
	{
		player.setY(player.getY() - 1);
		if(map[player.getY()][player.getX()] == 'O')
			cout<<"\nWYGRALES, ZNALAZLESC WYJSCIE!\nWpisz Q, zeby zakonczyc.\n";
	}
}

void playerOptions::moveRight()
{
	if(map[player.getY()][player.getX() + 1] != '#')
	{
		player.setX(player.getX() + 1);
		if(map[player.getY()][player.getX()] == 'O')
			cout<<"\nWYGRALES, ZNALAZLESC WYJSCIE!\nWpisz Q, zeby zakonczyc.\n";
	}
}

void playerOptions::moveLeft()
{
	if(map[player.getY()][player.getX() - 1] != '#')
	{
		player.setX(player.getX() - 1);
		if(map[player.getY()][player.getX()] == 'O')
			cout<<"\nWYGRALES, ZNALAZLESC WYJSCIE!\nWpisz Q, zeby zakonczyc.\n";
	}
}

void playerOptions::moveDown()
{
	if(map[player.getY() + 1][player.getX()] != '#')
	{
		player.setY(player.getY() + 1);
		if(map[player.getY()][player.getX()] == 'O')
			cout<<"\nWYGRALES, ZNALAZLESC WYJSCIE!\nWpisz Q, zeby zakonczyc.\n";
	}
}

int main()
{	
	char movement;
	playerOptions pOptions;
	pOptions.setPlayer(1, 1);
	cout<<endl;
	pOptions.Display();
	cout<<"\ni - Gracz.\n# - Sciana.\nS - Start.\nO - Wyjscie.\n Zeby sie poruszac wpisz A, W, S lub D. A jezeli chcesz wyjsc - Q:";
	do {
	cin>>movement;
	switch(movement)
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
	} while(!((movement == 'Q')||(movement == 'q')));
		return 0;
}