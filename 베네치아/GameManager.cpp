#include "GameManager.h"


GameManager::GameManager()
{
	InitInfo();
	LoadStory();
}

void GameManager::GameMenu()
{
	int select;
	while (1)
	{
		BLUEGREENGRAYBACK
		m_Drawer.BoxDraw(0, 0, WIDTH, HEIGHT - 5);
		ORIGINAL
		m_Drawer.GameStartMenu();
		DrawInfo();
		select = m_Drawer.MenuSelectCursor(3, 3, WIDTH / 2 - 5, HEIGHT * 0.4f);

		switch (select)
		{
		case 1:
			system("cls");
			GameStart();
			break;

		case 2:
			system("cls");
			m_RankManager.Management();
			system("pause");
			break;

		case 3:
			return;
		}
	}
}

void GameManager::GameStart()
{
	DrawInterface();
	BLUEGRAYBACK
		m_Drawer.DrawStory(storyList);
	system("cls");
	DrawInterface();
	BLUEGRAYBACK
		InputName();
	ORIGINAL
		m_WordManager.RandWord();

	char ch;
	string str;

	while (1)
	{
		system("cls");
		DrawInterface();
		m_Drawer.DrawStage(m_iStage);
		BLUEGRAYBACK
			m_Drawer.ErasePoint((WIDTH / 2) - 3, (HEIGHT - 5) / 2, 15);
		m_iGamming = GAMMING_GAMESTART;
		while (1)
		{
			BLUEGRAYBACK
				m_Drawer.BoxDraw(WIDTH, HEIGHT * 0.6f, WIDTH * 0.3f, 5);
			m_Drawer.DrawMidText(GetWord(PRINT), WIDTH, HEIGHT * 0.65f);
			if (CheckLife())
			{
				REDGRAYBACK
					m_Drawer.DrawMidText("�� Game Over ��", WIDTH, (HEIGHT - 5) / 2);
				ORIGINAL
					Sleep(2000);
				SaveInfo();
				InitInfo();
				m_WordManager.InitWord();
				return;
			}

			if (clock() - m_iOldTime > m_iPopTime)
			{
				m_WordManager.PopWord();
				m_iOldTime = clock();
			}
			m_WordManager.DropWords();

			if (m_WordManager.CheckWord())
			{
				MinusLife();
				EraseInfo();
				DrawInfo();
			}

			if (kbhit())
			{
				BLUEGRAYBACK;
				ch = getch();

				if (ch == ENTER)
				{
					if (m_WordManager.CheckAnswer(GetWord(GET)))
					{
						PlusScore();
						EraseInfo();
						DrawInfo();
						CheckStage();
						if (m_iGamming == GAMMING_NEXTSTAGE)
							break;
					}
				}
				else
				{
					Input(ch);
					m_Drawer.DrawMidText(GetWord(PRINT), WIDTH, HEIGHT * 0.65f);
				}
				ORIGINAL
			}
		}
	}
}

void GameManager::Input(char ch)
{
	if (ch == BACKSPACE)
	{
		if (input.empty())
			return;
		else
			input.pop();
		m_Drawer.BoxDraw(WIDTH, HEIGHT * 0.6f, WIDTH * 0.3f, 5);
	}
	else
	{
		if (input.size() >= 20)
			return;
		input.push(ch);
	}
}

string GameManager::GetWord(int type)
{
	string str;
	stack<char> print, tmp = input;

	if (input.empty())
		return "";

	while(!tmp.empty())
	{
		print.push(tmp.top());
		tmp.pop();
	}

	while(!print.empty())
	{
		str += print.top();
		print.pop();

		if (type == GET)
			input.pop();
	}
	
	return str;
}

void GameManager::InputName()
{
	char ch;
	m_Drawer.BoxDraw(WIDTH, HEIGHT * 0.6f, WIDTH * 0.3f, 5);
	m_Drawer.DrawMidText("�̸� �Է�", WIDTH, HEIGHT * 0.5f);

	while (1)
	{
		if (kbhit())
		{
			BLUEGRAYBACK;
			ch = getch();

			if (ch == ENTER)
			{
				m_sName = GetWord(GET);
				return;
			}
			Input(ch);
			m_Drawer.DrawMidText(GetWord(PRINT), WIDTH, HEIGHT * 0.65f);
			ORIGINAL
		}
	}
}

void GameManager::InitInfo()
{
	m_iOldTime = clock();
	m_iPopTime = 2000;
	m_iLife = 9;
	m_iScore = 0;
	m_iStage = 1;
	m_iStageScore = 300;
	m_iGamming = GAMMING_GAMESTART;
	m_sName = "? ? ?";
}

void GameManager::SaveInfo()
{
	ofstream save;
	save.open("Rank.txt", ios::app);

	if (save.is_open())
	{
		save << m_sName;
		save << " " << m_iStage;
		save << " " << m_iScore << "\n";
	}
}

void GameManager::CheckStage()
{
	if (m_iScore >= m_iStageScore)
	{
		m_iStage++;
		m_iScore = 0;
		m_iStageScore += 300;
		m_iPopTime -= 200;
		m_iGamming = GAMMING_NEXTSTAGE;
		m_WordManager.EraseList();
		m_WordManager.SetSpeed(200);
	}
}

int GameManager::CheckLife()
{
	if (m_iLife <= 0)
	{
		m_iGamming = GAMMING_GAMEOVER;
		return DIE;
	}
	else
		return LIVE;
}

void GameManager::LoadStory()
{
	ifstream load;
	string str;
	load.open("����ġ��_���丮.txt");

	while (!load.eof())
	{
		getline(load, str);
		storyList.push_back(str);
	}
}

void GameManager::DrawInterface()
{
	m_Drawer.DrawGrayBox(0, 0, WIDTH, HEIGHT);
	BLUEGREENGRAYBACK
	m_Drawer.BoxDraw(0, 0, WIDTH, HEIGHT - 5);
	EraseInfo();
	DrawInfo();
}

void GameManager::DrawInfo()
{
	string life;
	for (int i = 0; i < m_iLife; i++)
	{
		life += "��";
	}
	REDGRAYBACK
	m_Drawer.TextDraw("Life: " + life, 2, HEIGHT - 4);
	m_Drawer.DrawMidText("            ", WIDTH, HEIGHT - 4);
	m_Drawer.DrawMidText("Score: " + to_string(m_iScore), WIDTH, HEIGHT - 4);
	m_Drawer.DrawEndText("Name: " + m_sName, WIDTH * 2, HEIGHT - 4);
	ORIGINAL
}

void GameManager::EraseInfo()
{
	REDGRAYBACK
	m_Drawer.TextDraw("                        ", 2, HEIGHT - 4);
	m_Drawer.DrawMidText("             ", WIDTH, HEIGHT - 4);
	m_Drawer.DrawEndText("             ", WIDTH * 2, HEIGHT - 4);
	ORIGINAL
}