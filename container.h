#ifndef CONTAINER_H
#define CONTAINER_H

#include <fstream>
#include "plant.h"

namespace flora
{

struct container
{

	struct element
	{
		plant* p;
		element* next;
	};
	element* head, * tail;
	int len;

};

void init(container &c);
void clear(container &c);
void in(container &c, std::ifstream &ifst);
void out(container &c, std::ofstream &ofst);
}

#endif // CONTAINER_H
