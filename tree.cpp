#include "tree.h"
#include <iostream>
#include <cstdlib>

void InTree(tree &t, std::ifstream &ifst)
{
	ifst >> t.age;
	if (ifst.fail() || t.age < 0)
	{
		std::cerr << "Wrong tree age" << std::endl;
		exit(-1);
	}
}


void OutTree(tree &t, std::ofstream &ofst)
{
	ofst << "This is a tree: age = " << t.age << " years. ";
}
