#ifndef BUSH_H
#define BUSH_H

#include <fstream>

struct bush
{
	enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };
	month flowering;
};

void InBush(bush &b, std::ifstream &ifst);
void OutBush(bush &b, std::ofstream &ofst);

#endif // BUSH_H
