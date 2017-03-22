#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <fstream>
#include "tree.h"
#include "bush.h"

namespace flora
{

struct plant
	{
		std::string name;
		enum key { TREE, BUSH };
		key k;
		union {
			tree t;
			bush b;
		};
	};

plant *in(std::ifstream &ifst);
void out(plant &p, std::ofstream &ofst);

}

#endif // PLANT_H
