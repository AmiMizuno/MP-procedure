#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <fstream>
#include "tree.h"
#include "bush.h"
#include "flower.h"

enum zone { TUNDRA, DESERT, STEPPE, FOREST };
enum key { TREE, BUSH, FLOWER };
struct plant
	{
		std::string name;
		zone habitat;
		key k;
		union {
			tree t;
			bush b;
			flower f;
		};
	};

plant *readP(std::ifstream &ifst);
void outP(plant &p, std::ofstream &ofst);
int consonant_count(plant &p);
bool compare(plant *a, plant *b);



#endif // PLANT_H
