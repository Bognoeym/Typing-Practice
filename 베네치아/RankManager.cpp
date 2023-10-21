#include "RankManager.h"

RankManager::RankManager()
{

}

void RankManager::Management()
{
	LoadRank();
	SortRank();
	DrawInterface();
}

bool RankManager::CompareRank(const Rank& a, const Rank& b)
{
	if (a.m_iStage == b.m_iStage)
	{ 
		return a.m_iScore >= b.m_iScore;
	}
	else 
	{
		return a.m_iStage > b.m_iStage; 
	}
}

void RankManager::QuickSort(int start, int end)
{
	if (start >= end)
		return;

	int pivot = start;
	int i = start + 1, j = end;
	Rank temp;

	while (i <= j)
	{
		while (i <= end && CompareRank(rankList.at(i), rankList.at(pivot)))
		{
			i++;
		}
		while (j > start && !(CompareRank(rankList.at(j), rankList.at(pivot))))
		{
			j--;
		}

		if (i > j)
		{
			temp = rankList.at(j);
			rankList.at(j) = rankList.at(pivot);
			rankList.at(pivot) = temp;
		}
		else
		{

			temp = rankList.at(i);
			rankList.at(i) = rankList.at(j);
			rankList.at(j) = temp;
		}
	}

	QuickSort(start, j - 1);
	QuickSort(j + 1, end);
}

void RankManager::SortRank()  // stage È®ÀÎ -> score
{
	QuickSort(0, rankList.size() - 1);

	//sort(rankList.begin(), rankList.end(), compare);
}

void RankManager::DrawInterface()
{
	int height = 3, rankSize = rankList.size();
	Rank tmp;
	
	if (rankSize > 10)
		rankSize = 10;

	m_Drawer.DrawRanking();

	for (int i = 0; i < rankSize; i++)
	{
		tmp = rankList.at(i);
		m_Drawer.TextDraw(tmp.m_sName, WIDTH * 0.6f, HEIGHT * 0.2f + height);
		m_Drawer.TextDraw(to_string(tmp.m_iScore), WIDTH, HEIGHT * 0.2f + height);
		m_Drawer.TextDraw(to_string(tmp.m_iStage), WIDTH * 1.4f, HEIGHT * 0.2f + height);
		height += 2;
	}

}

void RankManager::LoadRank()
{
	rankList.clear();

	ifstream load;
	Rank tmp;
	load.open("Rank.txt");

	while (!load.eof())
	{
		load >> tmp.m_sName;
		load >> tmp.m_iStage;
		load >> tmp.m_iScore;

		rankList.push_back(tmp);
	}

	rankList.pop_back();
}

RankManager::~RankManager()
{

}