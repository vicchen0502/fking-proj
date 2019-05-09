#include "pch.h"
#include "Chess.h"
using namespace std;
//class Chess
Chess::Chess() :camp(0), alive(true), position({0,0}) {};
Chess::Chess(int c, bool d, short x, short y) : alive(d), position({x,y})
{
	if (c > 0 && c <= 7)
	{
		camp = 0;
	}
	else if (c > 7 && c <= 14)
	{
		camp = 1;
	}
};
void Chess::dead()
{
	alive = false;
}
int Chess::getCamp()
{
	return camp;
}
bool& Chess::getAlive()
{
	return alive;
}
vector<short>& Chess::getPosition()
{
	return position;
}
vector<vector<short>>& Chess::getCanGo()
{
	return canGo;
}
//class Soldier

Soldier::Soldier(int c, bool d, short x, short y) :Chess(c, d, x, y){};
vector<vector<short>>Soldier::listCanGo()
{
	if (overRiver = false)
	{
		if (this->getCamp() == 0)
		{
			getCanGo
		}
	}
}