#ifndef FLOWER_H
#define FLOWER_H
#include <fstream>
enum area { HOME, GARDEN, WILD };

struct Flower
{
	area growing;
};
void in_f(Flower &f, std::ifstream &ifst);
void out_f(Flower &f, std::ofstream &ofst);

#endif // FLOWER_H
