#include "Plant.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <cstdlib>

bool compare(Plant *a, Plant *b)
{
	return consonant_count(*a) < consonant_count(*b);
}

Plant* in(std::ifstream &ifst)
{
    Plant *p;
	std::string test;
    ifst >> test;
    if (ifst.fail()) {
        return 0;
	}
    for (int i = 0; i < test.length(); i++) {
        if (!isdigit(test[i])) {
            std::cerr << "Wrong plant key" << std::endl;
			exit(-1);
		}
	}
    int k;
	std::istringstream strin(test);
	strin >> k;
    if (strin.fail()) {
        std::cerr << "Wrong plant key" << std::endl;
		exit(-1);
	}
	std::string name;
	ifst >> name;
    if (ifst.fail()) {
        std::cerr << "Wrong plant name" << std::endl;
		exit(-1);
	}
	std::string habitat_in;
	ifst >> habitat_in;
    if (ifst.fail()) {
        std::cerr << "Wrong plant habitat" << std::endl;
		exit(-1);
	}
    p = new Plant;
	if (habitat_in == "Tundra")
        p->habitat = Plant::TUNDRA;
	else if (habitat_in == "Desert")
        p->habitat = Plant::DESERT;
	else if (habitat_in == "Steppe")
        p->habitat = Plant::STEPPE;
	else if (habitat_in == "Forest")
        p->habitat = Plant::FOREST;
	else{
		delete p;
        std::cerr << "Wrong plant habitat" << std::endl;
		exit(-1);
	}
	p->name = name;
    switch (k) {
		case 1:
            p->k = Plant::TREE;
            in_t(p->t, ifst);
			break;
		case 2:
            p->k = Plant::BUSH;
            in_b(p->b, ifst);
			break;
		case 3:
            p->k = Plant::FLOWER;
            in_f(p->f, ifst);
			break;
        default:
			delete p;
            std::cerr << "Wrong plant key" << std::endl;
			exit(-1);
	}
	return p;
}

void out(Plant &p, std::ofstream &ofst)
{
    switch (p.k) {
        case Plant::TREE :
            out_t(p.t, ofst);
			break;
        case Plant::BUSH :
            out_b(p.b, ofst);
			break;
        case Plant::FLOWER :
            out_f(p.f, ofst);
			break;
		default:
            std::cerr << "Incorrect plant!" << std::endl;
			return;
	}
	std::string habitat_out = "";
	switch (p.habitat){
        case Plant::TUNDRA:
			habitat_out = "Tundra";
			break;
        case Plant::DESERT:
			habitat_out = "Desert";
			break;
        case Plant::STEPPE:
			habitat_out = "Steppe";
			break;
        case Plant::FOREST:
			habitat_out = "Forest";
			break;
		default:
			std::cerr << "Incorrect habitat!" << std::endl;
			return;
	}
	ofst << "Name = " << p.name << ", habitat = " << habitat_out <<
			", consonant count = " << consonant_count(p) << std::endl;
}

int consonant_count(Plant &p)
{
	int consonsnts = 0;
    for (int i = 0, length = p.name.size(); i < length; i++) {
		char c = p.name[i];
		if (!isalpha(c))
			continue;
		c = tolower(c);
		if (c == 'a' || c == 'i' || c == 'u' || c == 'o' || c == 'e')
			continue;
		consonsnts++;
	}
	return consonsnts;
}
