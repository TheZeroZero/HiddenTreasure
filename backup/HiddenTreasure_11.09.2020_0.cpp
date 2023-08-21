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
	player.setX(2);
	player.setY(-2);
	cout<<(player.getX()-1)<<(player.getY()-1);
	cout<<(player.getX())<<(player.getY()-1);
	cout<<(player.getX()+1)<<(player.getY()-1);
	cout<<endl;
	cout<<(player.getX()-1)<<(player.getY());
	// cout i (the player), instead of:
	// "cout<<(player.getX())<<(player.getY());"
	cout<<i;
	cout<<(player.getX()+1)<<(player.getY());
	cout<<endl;
	cout<<(player.getX()-1)<<(player.getY()+1);
	cout<<(player.getX())<<(player.getY()+1);
	cout<<(player.getX()+1)<<(player.getY()+1);
	cout<<endl;
}

char map(int inputX, int inputY);

int main()
{
	PlayerOptions pOptions;
	pOptions.Display();
	return 0;
}

char map(int x, int y)
{
	char [16][16] = {
	{#, #, #, #, #, #, #, #, #, #, #, #, #, #, #, #}, 
	{#, S, ., ., ., ., ., ., #, ., #, ., #, #, ., #}, // S - start
	{#, ., #, ., #, #, #, #, #, ., ., ., ., ., ., #}, 
	{#, ., #, ., ., ., ., ., ., ., #, ., #, #, ., #}, 
	{#, ., #, #, #, ., #, #, #, #, #, ., #, ., ., #}, 
	{#, ., ., ., ., ., #, ., ., ., ., ., #, ., #, #}, 
	{#, #, #, ., #, ., #, ., #, #, #, #, #, ., #, #}, 
	{#, ., #, ., #, ., ., ., ., ., #, ., ., ., #, #}, 
	{#, ., ., ., #, ., #, #, ., #, #, ., #, ., #, #}, 
	{#, ., #, #, #, ., ., ., ., ., ., ., #, ., #, #}, 
	{#, ., #, ., ., ., #, #, #, #, #, #, #, ., ., #}, 
	{#, ., ., ., ., ., #, ., ., ., #, ., ., ., ., #}, 
	{#, ., #, #, #, #, #, ., #, ., #, ., #, #, ., #}, 
	{#, #, #, ., #, ., ., ., #, ., #, ., ., #, ., #}, 
	{#, 0, ., ., ., ., #, ., #, ., ., ., ., ., ., #}, // 0 - exit
	{#, #, #, #, #, #, #, #, #, #, #, #, #, #, #, #} };
	return 
	