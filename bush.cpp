#include "bush.h"
#include <iostream>
#include <cstdlib>

void in_b(Bush &b, std::ifstream &ifst)
{
	std::string month;
	ifst >> month;
    if (ifst.fail()) {
		std::cerr << "Wrong bush month" << std::endl;
		exit(-1);
	}
	if (month == "January")
        b.flowering = Bush::JANUARY;
	else if (month == "February")
        b.flowering = Bush::FEBRUARY;
	else if (month == "March")
        b.flowering = Bush::MARCH;
	else if (month == "April")
        b.flowering = Bush::APRIL;
	else if (month == "May")
        b.flowering = Bush::MAY;
	else if (month == "June")
        b.flowering = Bush::JUNE;
	else if (month == "July")
        b.flowering = Bush::JULY;
	else if (month == "August")
        b.flowering = Bush::AUGUST;
	else if (month == "September")
        b.flowering = Bush::SEPTEMBER;
	else if (month == "October")
        b.flowering = Bush::OCTOBER;
	else if (month == "November")
        b.flowering = Bush::NOVEMBER;
	else if (month == "December")
        b.flowering = Bush::DECEMBER;
    else {
		std::cerr << "Wrong bush month" << std::endl;
		exit(-1);
	}
}

void out_b(Bush &b, std::ofstream &ofst)
{
	std::string month;
    switch (b.flowering) {
        case Bush::JANUARY : month = "January"; break;
        case Bush::FEBRUARY : month = "February"; break;
        case Bush::MARCH : month = "March"; break;
        case Bush::APRIL : month = "April"; break;
        case Bush::MAY : month = "May"; break;
        case Bush::JUNE : month = "June"; break;
        case Bush::JULY : month = "July"; break;
        case Bush::AUGUST : month = "August"; break;
        case Bush::SEPTEMBER : month = "September"; break;
        case Bush::OCTOBER : month = "October"; break;
        case Bush::NOVEMBER : month = "November"; break;
        case Bush::DECEMBER : month = "December"; break;
		default : break;
	}
	ofst << "This is a bush: flowering month = " << month << ". ";
}
