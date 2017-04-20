#include "flower.h"
#include <iostream>
#include <cstdlib>

void in_f(Flower &f, std::ifstream &ifst)
{
	std::string growing_in;
	ifst >> growing_in;
    if (ifst.fail()) {
		std::cerr << "Wrong flower growing place" << std::endl;
		exit(-1);
	}
	if (growing_in == "Home")
        f.growing = Flower::HOME;
	else if (growing_in == "Garden")
        f.growing = Flower::GARDEN;
	else if (growing_in == "Wild")
        f.growing = Flower::WILD;
    else {
        std::cerr << "Wrong flower growing place" << std::endl;
		exit(-1);
	}
}

void out_f(Flower &f, std::ofstream &ofst)
{
	std::string growing_out;
    switch (f.growing) {
        case Flower::HOME : growing_out = "at home"; break;
        case Flower::GARDEN : growing_out = "in garden"; break;
        case Flower::WILD : growing_out = "in the wild"; break;
		default : break;
	}
	ofst << "This is a flower: grows " << growing_out << ". ";
}
