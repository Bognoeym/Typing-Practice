#include "WordManager.h"


WordManager::WordManager()
{
	LoadWord();
	m_iListSize = defWordList.size();
	m_iOldWordTime = 1000;
	m_iDropTime = clock();
	m_bBlind = NOTBLIND;
}

void WordManager::DropWords()
{
	if (randQueue.size() <= 1)
		RandWord();
	if (clock() - m_iItemTime > 3000)
		m_iWordSpeed = m_iOldWordTime;
	if (wordList.empty())
		return;
	if (clock() - m_iDropTime > m_iWordSpeed)
	{
		for (auto iter = wordList.begin(); iter != wordList.end(); iter++)
		{
			if (m_bBlind)
			{
				iter->DropWord(BLIND);
				if (clock() - m_iBlindTime > 1500)
					m_bBlind = NOTBLIND;
			}
			else
				iter->DropWord(NOTBLIND);
		}
		m_iDropTime = clock();
	}
}

void WordManager::PopWord()
{
	if (randQueue.empty())
		return;
	wordList.push_back(randQueue.front());
	randQueue.pop();
}

void WordManager::RandWord()
{
	int randNum;
	int randItem;

	for (int i = 0; i < defWordList.size(); i++)
	{
		Word tmp;
		randNum = rand() % m_iListSize;
		tmp = defWordList.at(randNum);
		randItem = rand() & 3;

		if (randItem == 1)
		{
			randItem = rand() & 5 + 1;
			tmp.SetItemType(randItem);
		}
		tmp.RandPX();
		randQueue.push(tmp);
	}
}

bool WordManager::CheckAnswer(string word)
{
	for (auto iter = wordList.begin(); iter != wordList.end(); iter++)
	{
		if (iter->GetWord() == word)
		{
			iter->EraseWord();
			if (iter->GetItemType() == ITEMTYPE_CLEAR)
			{
				ItemManager(iter->GetItemType());
			}
			else
			{
				ItemManager(iter->GetItemType());
				wordList.erase(iter);
			}
			return true;
		}
	}
	return false;
}

bool WordManager::CheckWord()
{
	for (auto iter = wordList.begin(); iter != wordList.end(); iter++)
	{
		if (iter->WordOver())
		{
			iter = wordList.erase(iter);
			return true;
		}
	}
	return false;
}

void WordManager::ItemManager(int itemType)
{
	switch (itemType)
	{
	case ITEMTYPE_NORMAL:
		return;

	case ITEMTYPE_FAST:
		m_iWordSpeed -= 200;
		m_iItemTime = clock();
		break;

	case ITEMTYPE_SLLOW:
		m_iWordSpeed += 200;
		m_iItemTime = clock();
		break;

	case ITEMTYPE_PAUSE:
		Sleep(3000);
		break;

	case ITEMTYPE_CLEAR:
		BlindWord();
		EraseList();
		break;

	case ITEMTYPE_BLIND:
		m_bBlind = BLIND;
		m_iBlindTime = clock();
		break;
	}
}

void WordManager::InitWord()
{
	m_iWordSpeed = 1000;
	m_iItemTime = clock();
	EraseList();
}

void WordManager::BlindWord()
{
	for (auto iter = wordList.begin(); iter != wordList.end(); iter++)
	{
		iter->EraseWord();
	}
}

void WordManager::EraseList()
{
	wordList.clear();

	if (randQueue.empty())
		return;
	for (int i = 0; i < randQueue.size(); i++)
	{
		randQueue.pop();
	}
}

void WordManager::LoadWord()
{
	ifstream load;
	string str;
	load.open("Word.txt");

	while (!load.eof())
	{
		getline(load, str);
		Word tmp;
		tmp.SetWord(str);
		defWordList.push_back(tmp);
	}
}

WordManager::~WordManager()
{

}