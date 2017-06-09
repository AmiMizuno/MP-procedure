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

void Init(container &c);
void Clear(container &c);
void InContainer(container &c, std::ifstream &ifst);
void OutContainer(container &c, std::ofstream &ofst);
void OutTrees(container &c, std::ofstream &ofst);

#endif // CONTAINER_H
