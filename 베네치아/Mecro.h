#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <queue>
#include <List>
#include <stdio.h>
#include <stack>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );

#define BLUEGREENGRAYBACK SetConsoleTextAttribute( col,0x0003 | (0x0008<<4));
#define BLUEGRAYBACK SetConsoleTextAttribute( col,0x0009 | (0x0008<<4));
#define REDGRAYBACK SetConsoleTextAttribute( col,0x000c | (0x0008<<4));
#define ORIGINALGRAYBACK SetConsoleTextAttribute( col,0x0007 | (0x0008<<4));
#define BLOODGRAYBACK SetConsoleTextAttribute( col,0x0004 | (0x0008<<4));

#define WIDTH 65
#define HEIGHT 40

#define LIVE 0
#define DIE 1

#define NOTBLIND 0
#define BLIND 1

#define BACKSPACE 8
#define ENTER 13
#define GET 0
#define PRINT 1

enum ITEMTYPE
{
	ITEMTYPE_NORMAL,
	ITEMTYPE_FAST,
	ITEMTYPE_SLLOW,
	ITEMTYPE_PAUSE,
	ITEMTYPE_CLEAR,
	ITEMTYPE_BLIND
};