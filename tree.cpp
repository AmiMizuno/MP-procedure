#include "tree.h"
#include <string>
namespace flora
{

void in(tree &t, std::ifstream &ifst)
{
	ifst >> t.age;
}


void out(tree &t, std::ofstream &ofst)
{
	ofst << "This is a tree: age = " << t.age << " years. ";
}

}
