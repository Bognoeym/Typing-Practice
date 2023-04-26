#pragma once
#include "Mecro.h"

#define UP 'w'
#define DOWN 's'
#define ENTER 13
#define SKIP 's'

class DrawManager
{
public:
	void BoxDraw(int Start_x, int Start_y, int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void DrawEndText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y, int state);
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	DrawManager();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	void DrawGrayBox(int Start_x, int Start_y, int Width, int Height);
	void GameStartMenu();
	void DrawStory(vector<string> storyList);
	void DrawStage(int stage);

	string ReturnSize(int size);
	~DrawManager();
};