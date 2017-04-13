#ifndef FLOWER_H
#define FLOWER_H

#include <fstream>



struct flower
{
	enum area { HOME, GARDEN, WILD };
	area growing;
};

void in(flower &f, std::ifstream &ifst);
void out(flower &f, std::ofstream &ofst);




#endif // FLOWER_H
