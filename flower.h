#ifndef FLOWER_H
#define FLOWER_H

#include <fstream>

struct flower
{
	enum area { HOME, GARDEN, WILD };
	area growing;
};

void InFlower(flower &f, std::ifstream &ifst);
void OutFlower(flower &f, std::ofstream &ofst);

#endif // FLOWER_H
