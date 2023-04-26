#include "RankManager.h"


void RankManager::Management()
{
	LoadRank();
	SortRank();
	DrawInterface();
}

void RankManager::SortRank()  // stage È®ÀÎ -> score
{
	Rank tmp;

	for (int i = 0; i < rankList.size() - 1; i++)
	{
		for (int j = i + 1; j < rankList.size(); j++)
		{
			if (rankList.at(i).m_iStage < rankList.at(j).m_iStage)
			{
				tmp = rankList.at(i);
				rankList.at(i) = rankList.at(j);
				rankList.at(j) = tmp;
			}
			else if (rankList.at(i).m_iStage == rankList.at(j).m_iStage)
			{
				if (rankList.at(i).m_iScore < rankList.at(j).m_iScore)
				{
					tmp = rankList.at(i);
					rankList.at(i) = rankList.at(j);
					rankList.at(j) = tmp;
				}
			}
		}
	}
}

void RankManager::DrawInterface()
{
	string str = "==========================================";
	int height = 3;
	Rank tmp;

	m_Drawer.DrawGrayBox(0, 0, WIDTH, HEIGHT);
	BLUEGREENGRAYBACK
		m_Drawer.BoxDraw(0, 0, WIDTH, HEIGHT - 5);
	BLUEGRAYBACK
	m_Drawer.BoxDraw(WIDTH, HEIGHT * 0.05f, WIDTH * 0.3f, 5);
	m_Drawer.DrawMidText("Ranking", WIDTH, HEIGHT * 0.05f + 2);
	m_Drawer.DrawMidText(str + str + str, WIDTH, HEIGHT * 0.2f);
	m_Drawer.TextDraw("Name", WIDTH*0.6f, HEIGHT * 0.2f + 2);
	m_Drawer.TextDraw("Score", WIDTH, HEIGHT * 0.2f + 2);
	m_Drawer.TextDraw("Stage", WIDTH*1.4f, HEIGHT * 0.2f + 2);

	for (int i = 0; i < rankList.size(); i++)
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