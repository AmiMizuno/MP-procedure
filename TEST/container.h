#ifndef CONTAINER_H
#define CONTAINER_H

#include <fstream>
#include "plant.h"



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
void In(container &c, std::ifstream &ifst);
void Out(container &c, std::ofstream &ofst);
void outTrees(container &c, std::ofstream &ofst);
void sort(container &c);


#endif // CONTAINER_H
