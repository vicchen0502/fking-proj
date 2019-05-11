﻿// 開始使用的秘訣: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

#ifndef PCH_H
#define PCH_H

// TODO: 請於此新增您要先行編譯的標頭
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

using namespace std;

// 游標移動 "至" (x, y)  
void gotoxy(int x, int y);
// 設定游標的樣式
void SetCursorVisible(BOOL _bVisible, DWORD _dwSize);
// 初始化棋盤 (無任何文字，只有符號)
vector<string> intialBoard(vector<string>chessBoard);
#endif //PCH_H
