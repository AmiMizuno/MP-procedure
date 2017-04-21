#ifndef BUSH_H
#define BUSH_H

#include <fstream>

enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

struct bush
{
	month flowering;
};

void in_b(bush &b, std::ifstream &ifst);
void out_b(bush &b, std::ofstream &ofst);



#endif // BUSH_H
