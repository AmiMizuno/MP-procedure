#include "flower.h"
#include <iostream>
#include <cstdlib>
#include <string>
void in_f(Flower &f, std::ifstream &ifst)
{
	std::string growing_in;
	ifst >> growing_in;
    if (ifst.fail()) {
		std::cerr << "Wrong flower growing place" << std::endl;
		exit(-1);
	}
	if (growing_in == "Home")
		f.growing = HOME;
	else if (growing_in == "Garden")
		f.growing = GARDEN;
	else if (growing_in == "Wild")
		f.growing = WILD;
    else {
        std::cerr << "Wrong flower growing place" << std::endl;
		exit(-1);
	}
}

void out_f(Flower &f, std::ofstream &ofst)
{
	std::string growing_out;
    switch (f.growing) {
		case HOME : growing_out = "at home"; break;
		case GARDEN : growing_out = "in garden"; break;
		case WILD : growing_out = "in the wild"; break;
		default : break;
	}
	ofst << "This is a flower: grows " << growing_out << ". ";
}
