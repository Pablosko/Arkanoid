#include "XML.h"
#include "../dependencies/RapidXML/rapidxml.hpp"
#include "../dependencies/RapidXML/rapidxml_utils.hpp"
#include "../dependencies/RapidXML/rapidxml_iterators.hpp"
#include "../dependencies/RapidXML/rapidxml_print.hpp"
LoadXML::LoadXML()
{
	rapidxml::xml_document<> doc;
	std::ifstream file("../resources/files/bricks.xml");
	
}

