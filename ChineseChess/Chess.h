#pragma once
#include"pch.h"
using namespace std;
class Chess
{
public:
	Chess();
	Chess(int c, bool d, short x, short y);
	void dead();
	int getCamp();
	int getAlive();
	vector<short> getPosition();
	virtual void move();
	
private:
	int camp;
	bool alive;
	vector<short> position;
};

//兵
class Soldier :public Chess
{
public:
	Soldier(int c, bool d, short x, short y);
	vector<vector<short>>canGoList();
	virtual void move();
private:
	bool overRiver;
};

//炮
class Cannon :public Chess
{
public:
	Cannon(int c, bool d, short x, short y);
	vector<vector<short>>canGoList();
	virtual void move();
	vector<vector<short>>canEat();
private:
};

//馬
class Horse :public Chess
{
public:
	Horse(int c, bool d, short x, short y);
	vector<vector<short>>canGoList();
	virtual void move();
};

//車
class Car :public Chess
{
public:
	Car(int c, bool d, short x, short y);
	vector<vector<short>>canGoList();
	virtual void move();
};

//相
class Elephant :public Chess
{
public:
	Elephant(int c, bool d, short x, short y);
	vector<vector<short>>canGoList();
	virtual void move();
};

//士
class Counselor :public Chess
{
public:
	Counselor(int c, bool d, short x, short y);
	vector<vector<short>>canGoList();
	virtual void move();
};

//帥
class King :public Chess
{
public:
	King(int c, bool d, short x, short y);
	vector<vector<short>>canGoList();
	virtual void move();
};