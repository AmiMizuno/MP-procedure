#ifndef FLOWER_H
#define FLOWER_H

#include <fstream>


enum area { HOME, GARDEN, WILD };
struct flower
{

	area growing;
};

void in_f(flower &f, std::ifstream &ifst);
void out_f(flower &f, std::ofstream &ofst);




#endif // FLOWER_H
