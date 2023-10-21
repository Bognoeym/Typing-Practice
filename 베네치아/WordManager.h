#pragma once
#include "Mecro.h"
#include "DrawManager.h"
#include "Word.h"

class WordManager
{
private:
	int m_iListSize;
	int m_iWordSpeed;
	int m_iOldWordTime;
	int m_iDropTime;
	int m_iItemTime;
	int m_iBlindTime;
	bool m_bBlind;
	vector<Word> defWordList;
	queue<Word> randQueue;
	list<Word> wordList;
public:
	WordManager();
	~WordManager();
	inline void SetSpeed(int time)
	{
		if (m_iOldWordTime <= 200)
			return;
		m_iOldWordTime -= time;
	}

	void LoadWord();
	void DropWords();
	void RandWord();
	void PopWord();
	void EraseList();
	void ItemManager(int itemType);
	void BlindWord();
	void InitWord();
	bool CheckWord();
	bool CheckAnswer(string word);
};

