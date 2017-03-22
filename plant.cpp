#include "plant.h"
#include <cctype>

namespace flora
{

void in(bush &b, std::ifstream &ifst);
void in(tree &t, std::ifstream &ifst);
void in(flower &f, std::ifstream &ifst);
void out(bush &b, std::ofstream &ofst);
void out(tree &t, std::ofstream &ofst);
void out(flower &f, std::ofstream &ofst);


bool compare(plant *a, plant *b)
{
	return consonant_count(*a) < consonant_count(*b);
}

plant* in(std::ifstream &ifst)
{
	plant *p;
	int k;
	ifst >> k;
	std::string name;
	ifst >> name;
	std::string habitat_in;
	ifst >> habitat_in;

	p = new plant;
	if (habitat_in == "Tundra")
		p->habitat = plant::TUNDRA;
	else if (habitat_in == "Desert")
		p->habitat = plant::DESERT;
	else if (habitat_in == "Steppe")
		p->habitat = plant::STEPPE;
	else if (habitat_in == "Forest")
		p->habitat = plant::FOREST;
	else
	{
		delete p;
		return 0;
	}
	p->name = name;

	switch (k)
	{
		case 1:
			p->k = plant::TREE;
			in(p->t, ifst);
			break;
		case 2:
			p->k = plant::BUSH;
			in(p->b, ifst);
			break;
		case 3:
			p = new plant;
			p->name = name;
			p->k = plant::FLOWER;
			in(p->f, ifst);
			break;
		default:
			delete p;
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
		case plant::FLOWER :
			out(p.f, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << std::endl;
			return;
	}

	std::string habitat_out = "";
	switch (p.habitat)
	{
		case plant::TUNDRA:
			habitat_out = "Tundra";
			break;
		case plant::DESERT:
			habitat_out = "Desert";
			break;
		case plant::STEPPE:
			habitat_out = "Steppe";
			break;
		case plant::FOREST:
			habitat_out = "Forest";
			break;
		default:
			ofst << "Incorrect habitat!" << std::endl;
			return;
	}

	ofst << "Name = " << p.name << ", habitat = " << habitat_out <<
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


