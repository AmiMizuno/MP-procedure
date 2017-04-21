#ifndef PLANT_H
#define PLANT_H
#include <string>
#include <fstream>
#include "tree.h"
#include "bush.h"
#include "flower.h"

enum zone { TUNDRA, DESERT, STEPPE, FOREST };
enum key { TREE, BUSH, FLOWER };
struct Plant
	{
		std::string name;
		zone habitat;

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
