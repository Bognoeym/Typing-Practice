#include "Word.h"


Word::Word()
{
	RandPX();
	m_iItemType = ITEMTYPE_NORMAL;
}

void Word::DropWord(bool blind)
{
	if (m_iItemType == ITEMTYPE_NORMAL)
	{
		BLUE;
	}
	else
	{
		BLOOD;
	}
	m_Drawer.ErasePoint(m_ix, m_iy++, m_sWord.size());

	if (!blind)
		m_Drawer.DrawPoint(m_sWord, m_ix, m_iy);
	ORIGINAL;
}

bool Word::WordOver()
{
	if (m_iy >= HEIGHT - 7)
	{
		BLUE;
		m_Drawer.ErasePoint(m_ix, m_iy, m_sWord.size());
		return true;
	}
	else
		return false;
}

void Word::EraseWord()
{
	BLUE;
	m_Drawer.ErasePoint(m_ix, m_iy, m_sWord.size());
	ORIGINAL;
}

void Word::RandPX()
{
	m_ix = rand() % (WIDTH - 4) + 2;  // rand() % (b-a+1) + a 
	m_iy = 1;
}

Word::~Word()
{

}