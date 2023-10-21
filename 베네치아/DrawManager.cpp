#include "DrawManager.h"


DrawManager::DrawManager()
{

}

string DrawManager::ReturnSize(int size)
{
	string str;

	for (int i = 0; i < size; i++)
	{
		str += " ";
	}

	return str;
}

void DrawManager::ErasePoint(int x, int y, int size)
{
	gotoxy(x * 2, y);
	string str;
	str = ReturnSize(size);
	cout << str;
	return;
}

void DrawManager::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void DrawManager::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void DrawManager::DrawEndText(string str, int x, int y)
{
	x -= str.size() + 5;
	gotoxy(x, y);
	cout << str;
	return;
}

void DrawManager::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void DrawManager::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	if (Start_x > Width)
		Start_x -= Width;
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┐";
		}
		else if (y == Height - 1)
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┘";
		}
		else
		{
			cout << "│";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "│";
		}
	}
		return;
}

void DrawManager::DrawBox(int Start_x, int Start_y, int Width, int Height)
{
	if (Start_x > Width)
		Start_x -= Width;
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		for (int x = 0; x < Width; x++)
			cout << "  ";
	}
}

int DrawManager::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	int select = 1;
	RED;
		DrawPoint("▷", x, y);
		ORIGINAL;
		while (1)
		{
			switch (getch())
			{
			case UP:
				if (select - 1 >= 1)
				{
					ErasePoint(x, y, 2);
					y -= AddCol;
					select--;
				}
				break;
			case DOWN:
				if (select + 1 <= MenuLen)
				{
					ErasePoint(x, y, 2);
					y += AddCol;
					select++;
				}
				break;
			case ENTER:
				ORIGINAL;
					return select;
			}
			RED;
				DrawPoint("▷", x, y);
			ORIGINAL;
		}
		ORIGINAL;
}

void DrawManager::DrawStory(vector<string> storyList)
{
	vector<string> tmp;
	string str;
	int y = 0, yTmp = 0;
	char ch;

	BoxDraw(WIDTH, HEIGHT * 0.6f, WIDTH * 0.3f, 5);
	DrawMidText("Skip: s", WIDTH, HEIGHT * 0.65f);
	for (int i = 0; i < storyList.size(); i++)
	{
		if (kbhit())
		{
			ch = getch();
			if (ch == SKIP)
				return;
		}

		if (i >= 10)
		{
			tmp.erase(tmp.begin());
			yTmp = 8;

			for (int j = tmp.size() - 1; j >= 0; j--)
			{
				str = ReturnSize(WIDTH);
				DrawMidText(str, WIDTH, HEIGHT * 0.2f + yTmp);
				str = tmp.at(j);
				DrawMidText(str, WIDTH, HEIGHT * 0.2f + yTmp);
				yTmp--;
			}
		}

		str = ReturnSize(WIDTH);
		DrawMidText(str, WIDTH, HEIGHT * 0.2f + y);
		str = storyList.at(i);
		DrawMidText(str, WIDTH, HEIGHT * 0.2f + y);
		tmp.push_back(storyList.at(i));

		if (y < 9)
			y++;

		Sleep(500);
	}
}

void DrawManager::GameStartMenu()
{
	BLUE;
		DrawMidText("☆ ★ 베 네 치 아 ★ ☆", WIDTH, HEIGHT * 0.2f);
	DrawMidText("1.Game Start", WIDTH, HEIGHT * 0.4f);
	DrawMidText("2.Rank", WIDTH, HEIGHT * 0.4f + 3);
	DrawMidText("3.Exit", WIDTH, HEIGHT * 0.4f + 6);
	ORIGINAL;
}

void DrawManager::DrawStage(int stage)
{
	BLUE;
	DrawMidText("★ STAGE " + to_string(stage) + " ★", WIDTH, (HEIGHT - 5) / 2);
	Sleep(1000);
	ORIGINAL;
}

void DrawManager::DrawRanking()
{
	string str = "==========================================";

	DrawBox(0, 0, WIDTH, HEIGHT);
	BLUE;
	BoxDraw(0, 0, WIDTH, HEIGHT - 5);
	BLUE;
	BoxDraw(WIDTH, HEIGHT * 0.05f, WIDTH * 0.3f, 5);
	DrawMidText("Ranking", WIDTH, HEIGHT * 0.05f + 2);
	DrawMidText(str + str + str, WIDTH, HEIGHT * 0.2f);
	TextDraw("Name", WIDTH * 0.6f, HEIGHT * 0.2f + 2);
	TextDraw("Score", WIDTH, HEIGHT * 0.2f + 2);
	TextDraw("Stage", WIDTH * 1.4f, HEIGHT * 0.2f + 2);
	ORIGINAL;
}

DrawManager::~DrawManager()
{
}