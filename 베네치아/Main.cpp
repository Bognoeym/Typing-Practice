#include "Mecro.h"
#include "GameManager.h"

void main()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT, WIDTH * 2);
	system(buf);

	GameManager game;
	game.GameMenu();
}