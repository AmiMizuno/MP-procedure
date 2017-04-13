#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <fstream>
#include "tree.h"
#include "bush.h"
#include "flower.h"



struct plant
	{
		std::string name;
		enum zone { TUNDRA, DESERT, STEPPE, FOREST };
		zone habitat;
		enum key { TREE, BUSH, FLOWER };
		key k;
		union {
			tree t;
			bush b;
			flower f;
		};
	};

plant *in(std::ifstream &ifst);
void out(plant &p, std::ofstream &ofst);
int consonant_count(plant &p);



#endif // PLANT_H
