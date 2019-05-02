#pragma once
#include"Arena.h"
#include"Chess.h"
/*
#include<iostream>
#include<string>
#include<vector>*/
using namespace std;
class Arena
{
public:
	void readInShowingMap();
	void readInMap(string loadGame);
	void showMap();
private:
	vector<string>showingMap;
	vector<vector<Chess>>map;
};