#ifndef BUSH_H
#define BUSH_H
#include <fstream>

struct Bush
{
	enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };
	month flowering;
};
void in_b(Bush &b, std::ifstream &ifst);
void out_b(Bush &b, std::ofstream &ofst);

#endif // BUSH_H
