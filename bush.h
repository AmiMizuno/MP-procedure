#ifndef BUSH_H
#define BUSH_H

#include <fstream>

namespace flora
{

struct bush
{
	enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };
	month flowering;
};

void in(bush &b, std::ifstream &ifst);
void out(bush &b, std::ofstream &ofst);

}

#endif // BUSH_H
