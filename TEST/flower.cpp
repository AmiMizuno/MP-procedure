#include "flower.h"
#include <string>
using namespace std;

void in_f(flower &f, std::ifstream &ifst)
{
	std::string growing_in;
	ifst >> growing_in;
	if (growing_in == "Home")
		f.growing = flower::HOME;
	else if (growing_in == "Garden")
		f.growing = flower::GARDEN;
	else if (growing_in == "Wild")
		f.growing = flower::WILD;
}


void out_f(flower &f, std::ofstream &ofst)
{
	std::string growing_out;
	switch (f.growing)
	{
		case flower::HOME : growing_out = "at home"; break;
		case flower::GARDEN : growing_out = "in garden"; break;
		case flower::WILD : growing_out = "in the wild"; break;
		default : break;
	}
	ofst << "This is a flower: grows " << growing_out << ". ";
}


