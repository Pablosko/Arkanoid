#include "XML.h"
#include "../dependencies/RapidXML/rapidxml.hpp"
#include "../dependencies/RapidXML/rapidxml_utils.hpp"
#include "../dependencies/RapidXML/rapidxml_iterators.hpp"
#include "../dependencies/RapidXML/rapidxml_print.hpp"
#include <iostream>

LoadXML::LoadXML()
{
	rapidxml::file<> xmlFile("resources/config.xml");
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());

	rapidxml::xml_node<>* pRoot = doc.first_node();

	for (rapidxml::xml_node<>* pNode = pRoot->first_node("Level"); pNode; pNode = pNode->next_sibling())
	{
		for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling())
		{
			int a = 0;
			Vector2D<int> pos;
			for (rapidxml::xml_attribute<>* pAttr = pNodeI->first_attribute(); pAttr; pAttr = pAttr->next_attribute())
			{
				if (a ==  0)
				{
					pos.X = atoi(pAttr->value());
				}
				if (a == 1)
				{
					pos.Y = atoi(pAttr->value());
				}
				if (a == 2)
				{
					std::string str = std::string(pAttr->value());
					if (str == "N")
					{
						types.push_back(BrickType::Green);
					}
					if (str == "H")
					{
						types.push_back(BrickType::Red);
					}
					if (str == "F")
					{
						types.push_back(BrickType::Fix);
					}
					//types.push_back(pAttr->value());
					positions.push_back(pos);
				}
				
				a++;
			}
		}
		std::cout << '\n';
	}	
}

