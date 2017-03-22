#ifndef TREE_H
#define TREE_H

#include <fstream>

namespace flora
{

struct tree
{
	long int age;
};

void in(tree &t, std::ifstream &ifst);
void out(tree &t, std::ofstream &ofst);

}

#endif // TREE_H
