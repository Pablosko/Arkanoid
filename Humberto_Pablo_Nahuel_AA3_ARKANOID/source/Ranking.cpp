#include "Ranking.h"

Ranking::Ranking()
{
	LoadXmlRanking();
}

void Ranking::LoadXmlRanking()
{
	rapidxml::file<> xmlFile("resources/files/ranking.xml");
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());

	rapidxml::xml_node<>* pRoot = doc.first_node();

	for (rapidxml::xml_node<>* pNode = pRoot->first_node("Ranking"); pNode; pNode = pNode->next_sibling())
	{
		for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling())
		{
			int i = 0;
			for (rapidxml::xml_attribute<>* pAttr = pNodeI->first_attribute(); pAttr; pAttr = pAttr->next_attribute())
			{
				if (i == 0)
				{
					names.push_back(std::string(pAttr->value()));
				}
				if (i == 1)
				{
					score.push_back(atoi(pAttr->value()));
				}
				i++;
			}
		}
	}
	for (size_t i = 0; i < names.size(); i++)
	{
		ranking.insert(std::pair<std::string, int>(names[i], score[i]));
	}
}

void Ranking::SaveXmlRanking()
{
	//Not Working
}

void Ranking::ShowRank(RenderManager* _rendMang)
{
	std::vector <std::pair<std::string, int>> ranking = SortRanking();
	SDL_Rect rankRect;
	rankRect.h = 32;
	rankRect.w = 150;
	rankRect.y = _rendMang->ScreenHeight * 0.27;
	rankRect.x = _rendMang->ScreenWidth * 0.4;
	for (int i = 0; i < 10; i++)
	{
		std::string name = std::to_string(ranking[i].second);
		Button* temp = new Button("resources/ButtonImage.png", _rendMang, rankRect, ranking[i].first + " " + name);
		rankRect.y += 33;
	}
}

bool sortByVal(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
	return a.second < b.second;
}

std::vector<std::pair<std::string, int>> Ranking::SortRanking()
{
	std::vector <std::pair<std::string, int>> vec;
	
	std::map<std::string, int> ::iterator it;
	for (it = ranking.begin(); it != ranking.end(); it++)
	{
		vec.push_back(std::make_pair(it->first, it->second));
	}
	std::sort(vec.begin(), vec.end(), sortByVal);

	return vec;
}

