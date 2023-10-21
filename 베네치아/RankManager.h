#pragma once
#include "Mecro.h"
#include "DrawManager.h"

struct Rank
{
	string m_sName;
	int m_iScore;
	int m_iStage;
};

class RankManager
{
private:
	vector<Rank> rankList;
	DrawManager m_Drawer;
public:
	RankManager();
	~RankManager();
	void Management();
	void DrawInterface();
	void LoadRank();
	void SortRank();
	void QuickSort(int start, int end);
	bool CompareRank(const Rank& a, const Rank& b);
};

