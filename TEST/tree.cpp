#include "tree.h"
#include <string>
using namespace std;


void in_t(tree &t, std::ifstream &ifst)
{
	ifst >> t.age;
}


void out_t(tree &t, std::ofstream &ofst)
{
	ofst << "This is a tree: age = " << t.age << " years. ";
}


