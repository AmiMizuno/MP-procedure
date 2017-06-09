#ifndef TREE_H
#define TREE_H

#include <fstream>

struct tree
{
	long int age;
};

void InTree(tree &t, std::ifstream &ifst);
void OutTree(tree &t, std::ofstream &ofst);

#endif // TREE_H
