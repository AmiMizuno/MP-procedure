#ifndef TREE_H
#define TREE_H

#include <fstream>


struct tree
{
	long int age;
};

void in_t(tree &t, std::ifstream &ifst);
void out_t(tree &t, std::ofstream &ofst);



#endif // TREE_H
