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


plant* in(std::ifstream &ifst)
{
	plant *p;
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
		case 3:
			p = new plant;
			p->name = name;
			p->k = plant::FLOWER;
			in(p->f, ifst);
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
		case plant::FLOWER :
			out(p.f, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << std::endl;
			break;
	}


	ofst << "Name = " << p.name << std::endl;
}

}
