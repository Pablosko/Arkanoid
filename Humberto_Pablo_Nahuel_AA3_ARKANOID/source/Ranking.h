#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include "../dependencies/RapidXML/rapidxml.hpp"
#include "../dependencies/RapidXML/rapidxml_utils.hpp"
#include "../dependencies/RapidXML/rapidxml_iterators.hpp"
#include "../dependencies/RapidXML/rapidxml_print.hpp"
#include <algorithm>
#include <iostream>
#include "Button.h"
#include "Scene.h"
class Ranking
{
public:
	Ranking();
	void LoadXmlRanking();
	void SaveXmlRanking();
	std::vector<std::pair<std::string, int>> SortRanking();
	void ShowRank(RenderManager* scene);
	bool SortByVal(const std::pair<std::string, int> a, const std::pair<std::string, int> b);

	std::map<std::string, int> ranking;

	std::vector<std::string> names;
	std::vector<int> score;

};

