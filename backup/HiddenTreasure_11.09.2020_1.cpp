#include "Point.hpp"
using namespace std;

class playerOptions
{
public:
	Point player;
//public: TEMPORARY (player PUBLIC)
	void Display();
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
};

void playerOptions::Display()
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
	{'#', '0', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '#'}, // 0 - exit
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} }; 
	
	player.setX(2);
	player.setY(-2);
	cout<<map[player.getX()-1]<<" "<<map[player.getY()-1];
	cout<<map[player.getX()]<<" "<<map[player.getY()-1];
	cout<<map[player.getX()+1]<<" "<<map[player.getY()-1];
	cout<<endl;
	cout<<map[player.getX()-1]<<" "<<map[player.getY()];
	// cout i (the player), instead of:
	// "cout<<(player.getX())<<(player.getY());"
	cout<<"i";
	cout<<map[player.getX()+1]<<" "<<map[player.getY()];
	cout<<endl;
	cout<<map[player.getX()-1]<<" "<<map[player.getY()+1];
	cout<<map[player.getX()]<<" "<<map[player.getY()+1];
	cout<<map[player.getX()+1]<<" "<<map[player.getY()+1];
	cout<<endl;
}

int main()
{
	
	playerOptions pOptions;
	pOptions.Display();
	return 0;
}