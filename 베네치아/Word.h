#pragma once
#include "Mecro.h"
#include "DrawManager.h"

class Word
{
private:
	int m_ix, m_iy;
	int m_iItemType;
	string m_sWord;
	DrawManager m_Drawer;
public:
	Word();
	inline string GetWord() { return m_sWord; }
	inline void SetWord(string word) { m_sWord = word; }
	inline void SetItemType(int item) { m_iItemType = item; }
	inline int GetItemType() { return m_iItemType; }

	void RandPX();
	void DropWord(bool blind);
	void EraseWord();
	bool WordOver();
};

