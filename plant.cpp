#include "plant.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <cstdlib>

void InBush(bush &b, std::ifstream &ifst);
void InTree(tree &t, std::ifstream &ifst);
void InFlower(flower &f, std::ifstream &ifst);
void OutBush(bush &b, std::ofstream &ofst);
void OutTree(tree &t, std::ofstream &ofst);
void OutFlower(flower &f, std::ofstream &ofst);

bool compare(plant *a, plant *b)
{
	return consonant_count(*a) < consonant_count(*b);
}

plant* In(std::ifstream &ifst)
{
	plant *p;
	std::string test;
    ifst >> test;
	if (ifst.fail())
	{
		return 0;
	}
	for (int i = 0; i < test.length(); i++)
	{
        if (!isdigit(test[i]))
		{
			std::cerr << "Wrong plant key" << std::endl;
			exit(-1);
		}
	}
	int k;
	std::istringstream strin(test);
	strin >> k;
	if (strin.fail())
	{
		std::cerr << "Wrong plant key" << std::endl;
		exit(-1);
	}

	std::string name;
	ifst >> name;
	if (ifst.fail())
	{
		std::cerr << "Wrong plant name" << std::endl;
		exit(-1);
	}
	std::string habitat_in;
	ifst >> habitat_in;
	if (ifst.fail())
	{
		std::cerr << "Wrong plant habitat" << std::endl;
		exit(-1);
	}

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
		std::cerr << "Wrong plant habitat" << std::endl;
		exit(-1);
	}
	p->name = name;

	switch (k)
	{
		case 1:
			p->k = plant::TREE;
			InTree(p->t, ifst);
			break;
		case 2:
			p->k = plant::BUSH;
			InBush(p->b, ifst);
			break;
		case 3:
			p->k = plant::FLOWER;
			InFlower(p->f, ifst);
			break;
		default:
			delete p;
			std::cerr << "Wrong plant key" << std::endl;
			exit(-1);
	}
	return p;
}


void Out(plant &p, std::ofstream &ofst)
{
	switch (p.k)
	{
		case plant::TREE :
			OutTree(p.t, ofst);
			break;
		case plant::BUSH :
			OutBush(p.b, ofst);
			break;
		case plant::FLOWER :
			OutFlower(p.f, ofst);
			break;
		default:
			std::cerr << "Incorrect plant!" << std::endl;
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
			std::cerr << "Incorrect habitat!" << std::endl;
			return;
	}

	ofst << "Name = " << p.name << ", habitat = " << habitat_out <<
			", consonant count = " << ConsonantCount(p) << std::endl;
}

int ConsonantCount(plant &p)
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
