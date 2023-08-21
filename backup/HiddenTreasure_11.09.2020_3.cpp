#include "Point.hpp"
using namespace std;

class playerOptions
{
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
	char map[16][16] = {
	{'█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█'}, 
	{'█', 'S', '.', '.', '.', '.', '.', '.', '█', '.', '█', '.', '█', '█', '.', '█'}, // S - start
	{'█', '.', '█', '.', '█', '█', '█', '█', '█', '.', '.', '.', '.', '.', '.', '█'}, 
	{'█', '.', '█', '.', '.', '.', '.', '.', '.', '.', '█', '.', '█', '█', '.', '█'}, 
	{'█', '.', '█', '█', '█', '.', '█', '█', '█', '█', '█', '.', '█', '.', '.', '█'}, 
	{'█', '.', '.', '.', '.', '.', '█', '.', '.', '.', '.', '.', '█', '.', '█', '█'}, 
	{'█', '█', '█', '.', '█', '.', '█', '.', '█', '█', '█', '█', '█', '.', '█', '█'}, 
	{'█', '.', '█', '.', '█', '.', '.', '.', '.', '.', '█', '.', '.', '.', '█', '█'}, 
	{'█', '.', '.', '.', '█', '.', '█', '█', '.', '█', '█', '.', '█', '.', '█', '█'}, 
	{'█', '.', '█', '█', '█', '.', '.', '.', '.', '.', '.', '.', '█', '.', '█', '█'}, 
	{'█', '.', '█', '.', '.', '.', '█', '█', '█', '█', '█', '█', '█', '.', '.', '█'}, 
	{'█', '.', '.', '.', '.', '.', '█', '.', '.', '.', '█', '.', '.', '.', '.', '█'}, 
	{'█', '.', '█', '█', '█', '█', '█', '.', '█', '.', '█', '.', '█', '█', '.', '█'}, 
	{'█', '█', '█', '.', '█', '.', '.', '.', '█', '.', '█', '.', '.', '█', '.', '█'}, 
	{'█', 'O', '.', '.', '.', '.', '█', '.', '█', '.', '.', '.', '.', '.', '.', '█'}, // 0 - exit
	{'█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█', '█'} }; 
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
	player.setY(player.getY() - 1);
}

void playerOptions::moveRight()
{
	player.setX(player.getX() + 1);
}

void playerOptions::moveLeft()
{
	player.setX(player.getX() - 1);
}

void playerOptions::moveDown()
{
	player.setY(player.getY() + 1);
}

int main()
{	
	
	char movement;
	playerOptions pOptions;
	pOptions.setPlayer(1, 1);
	pOptions.Display();
	cout<<"Zeby sie poruszac wpisz A, W, S lub D. A jezeli chcesz wyjsc - Q:";
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
			cout<<"Gra zostala wylaczona.\n";
			break;
		default:
			cout<<"Nie ma takiej opcji. Sprobuj ponownie.\n";
		}
	} while(!((movement == 'Q')||(movement == 'q')));
		return 0;
}