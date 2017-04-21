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
void sort(Container &c); // не было в загловочном
void in(Container &c, std::ifstream &ifst);
void out(Container &c, std::ofstream &ofst);
void out_trees(Container &c, std::ofstream &ofst);
void check_infile(std::ifstream &ifst);
void check_outfile(std::ofstream &ofst);
std::string check_data(std::ifstream &ifst, std::string str);
#endif // CONTAINER_H
