#ifndef PLANT_H
#define PLANT_H
#include <string>
#include <fstream>
#include "tree.h"
#include "bush.h"
#include "flower.h"

struct Plant
	{
		std::string name;
		enum zone { TUNDRA, DESERT, STEPPE, FOREST };
		zone habitat;
		enum key { TREE, BUSH, FLOWER };
		key k;
		union {
            Tree t;
            Bush b;
            Flower f;
		};
	};

Plant *in(std::ifstream &ifst);
void out(Plant &p, std::ofstream &ofst);
int consonant_count(Plant &p);

#endif // PLANT_H
