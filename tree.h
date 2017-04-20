#ifndef TREE_H
#define TREE_H
#include <fstream>

struct Tree
{
	long int age;
};

void in_t(Tree &t, std::ifstream &ifst);
void out_t(Tree &t, std::ofstream &ofst);

#endif // TREE_H
