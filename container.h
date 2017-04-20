#ifndef CONTAINER_H
#define CONTAINER_H
#include <fstream>
#include "plant.h"

struct Container
{

	struct element
	{
        Plant* p;
		element* next;
	};
	element* head, * tail;
	int len;

};

void init(Container &c);
void clear(Container &c);
void in(Container &c, std::ifstream &ifst);
void out(Container &c, std::ofstream &ofst);
void out_trees(Container &c, std::ofstream &ofst);
void sort(Container &c);

#endif // CONTAINER_H
