#ifndef FLOWER_H
#define FLOWER_H

#include <fstream>



struct flower
{
	enum area { HOME, GARDEN, WILD };
	area growing;
};

void in_f(flower &f, std::ifstream &ifst);
void out_f(flower &f, std::ofstream &ofst);




#endif // FLOWER_H
