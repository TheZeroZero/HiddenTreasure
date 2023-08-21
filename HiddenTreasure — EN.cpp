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
			cout<<"\nYOU WON, YOU FOUND THE EXIT!\nType Q to exit.";
	}
}

void playerOptions::moveRight()
{
	if(map[player.getY()][player.getX() + 1] != '#')
	{
		player.setX(player.getX() + 1);
		if(map[player.getY()][player.getX()] == 'O')
			cout<<"\nYOU WON, YOU FOUND THE EXIT!\nType Q to exit.";
	}
}

void playerOptions::moveLeft()
{
	if(map[player.getY()][player.getX() - 1] != '#')
	{
		player.setX(player.getX() - 1);
		if(map[player.getY()][player.getX()] == 'O')
			cout<<"\nYOU WON, YOU FOUND THE EXIT!\nType Q to exit.";
	}
}

void playerOptions::moveDown()
{
	if(map[player.getY() + 1][player.getX()] != '#')
	{
		player.setY(player.getY() + 1);
		if(map[player.getY()][player.getX()] == 'O')
			cout<<"\nYOU WON, YOU FOUND THE EXIT!\nType Q to exit.";
	}
}

int main()
{	
	char movement;
	playerOptions pOptions;
	pOptions.setPlayer(1, 1);
	cout<<endl;
	pOptions.Display();
	cout<<"\ni - Player.\n# - Wall.\nS - Start.\nO - Exit.\nTo nove type A, W, S or D. And if you want to leave - Q:";
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
			cout<<"\nThe game has shut down.\n";
			break;
		default:
			cout<<"There's no such option.\n";
		}
	} while(!((movement == 'Q')||(movement == 'q')));
		return 0;
}
	 # # # # # # # # # # # # # # # # 
	 # S . . . . . . # . # . # # . #
	 # . # . # # # # # . . . . . . # 
	 # . # . . . . . . . # . # # . # 
	 # . # # # . # # # # # . # . . # 
	 # . . . . . # . . . . . # . # # 
	 # # # . # . # . # # # # # . # # 
	 # . # . # . . . . . # . . . # # 
	 # . . . # . # # . # # . # . # # 
	 # . # # # . . . . . . . # . # # 
	 # . # . . . # # # # # # # . . # 
	 # . . . . . # . . . # . . . . # 
	 # . # # # # # . # . # . # # . # 
	 # # # . # . . . # . # . . # . # 
	 # O . . . . # . # . . . . . . #
	 # # # # # # # # # # # # # # # # 