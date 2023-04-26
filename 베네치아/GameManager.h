#pragma once
#include "Mecro.h"
#include "DrawManager.h"
#include "WordManager.h"
#include "RankManager.h"

enum GAMMING
{
	GAMMING_GAMESTART,
	GAMMING_GAMEOVER,
	GAMMING_NEXTSTAGE
};

class GameManager
{
private:
	int m_iLife;
	int m_iScore;
	int m_iStageScore;
	int m_iStage;
	int m_iOldTime;
	int m_iPopTime;
	int m_iGamming;
	string m_sName;
	vector<string> storyList;
	stack<char> input;
	DrawManager m_Drawer;
	WordManager m_WordManager;
	RankManager m_RankManager;
public:
	GameManager();
	inline void PlusScore() { m_iScore += 50; }
	inline void MinusLife() { m_iLife--; }

	void GameMenu();
	void GameStart();
	void InputName();
	void LoadStory();
	void DrawInfo();
	void EraseInfo();
	void DrawInterface();
	void CheckStage();
	void SaveInfo();
	void InitInfo(); 
	void Input(char ch);

	string GetWord(int type);
	int CheckLife();
};

