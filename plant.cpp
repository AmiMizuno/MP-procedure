#include "plant.h"

namespace flora
{

void in(bush &b, std::ifstream &ifst);
void in(tree &t, std::ifstream &ifst);
void out(bush &b, std::ofstream &ofst);
void out(tree &t, std::ofstream &ofst);


plant* in(std::ifstream &ifst)
{
	plant *p = NULL;
	int k;
	ifst >> k;
	std::string name;
	ifst >> name;
	switch (k)
	{
		case 1:
			p = new plant;
			p->name = name;
			p->k = plant::TREE;
			in(p->t, ifst);
			break;
		case 2:
			p = new plant;
			p->name = name;
			p->k = plant::BUSH;
			in(p->b, ifst);
			break;
		default:
			return 0;
	}
	return p;
}


void out(plant &p, std::ofstream &ofst)
{
	switch (p.k)
	{
		case plant::TREE :
			out(p.t, ofst);
			break;
		case plant::BUSH :
			out(p.b, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << std::endl;
			break;
	}
	ofst << "Name = " << p.name << 
			", consonant count = " << consonant_count(p) << std::endl;
}

int consonant_count(plant &p)
{
	int consonsnts = 0;
	for (int i = 0, length = p.name.size(); i < length; i++)
	{
		char c = p.name[i];
		if (!isalpha(c))
			continue;
		c = tolower(c);
		if (c == 'a' || c == 'i' || c == 'u' || c == 'o' || c == 'e')
			continue;
		consonsnts++;
	}
	return consonsnts;
}


}
