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

// »ö»ó
#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define BLOOD SetConsoleTextAttribute( col,0x0004 )
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 )
#define BLUE SetConsoleTextAttribute( col,0x0009 )
#define RED SetConsoleTextAttribute( col,0x000c )

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