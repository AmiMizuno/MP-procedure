#ifndef FLOWER_H
#define FLOWER_H
#include <fstream>

struct Flower
{
	enum area { HOME, GARDEN, WILD };
	area growing;
};
void in(Flower &f, std::ifstream &ifst);
void out(Flower &f, std::ofstream &ofst);

#endif // FLOWER_H
