#include "bush.h"
#include <iostream>
#include <cstdlib>
#include <string>

void in_b(Bush &b, std::ifstream &ifst)
{
	std::string month;
	ifst >> month;
    if (ifst.fail()) {
		std::cerr << "Wrong bush month" << std::endl;
		exit(-1);
	}
	if (month == "January")
		b.flowering = JANUARY;
	else if (month == "February")
		b.flowering = FEBRUARY;
	else if (month == "March")
		b.flowering = MARCH;
	else if (month == "April")
		b.flowering = APRIL;
	else if (month == "May")
		b.flowering = MAY;
	else if (month == "June")
		b.flowering = JUNE;
	else if (month == "July")
		b.flowering = JULY;
	else if (month == "August")
		b.flowering = AUGUST;
	else if (month == "September")
		b.flowering = SEPTEMBER;
	else if (month == "October")
		b.flowering = OCTOBER;
	else if (month == "November")
		b.flowering = NOVEMBER;
	else if (month == "December")
		b.flowering = DECEMBER;
    else {
		std::cerr << "Wrong bush month" << std::endl;
		exit(-1);
	}
}

void out_b(Bush &b, std::ofstream &ofst)
{
	std::string month;
    switch (b.flowering) {
		case JANUARY : month = "January"; break;
		case FEBRUARY : month = "February"; break;
		case MARCH : month = "March"; break;
		case APRIL : month = "April"; break;
		case MAY : month = "May"; break;
		case JUNE : month = "June"; break;
		case JULY : month = "July"; break;
		case AUGUST : month = "August"; break;
		case SEPTEMBER : month = "September"; break;
		case OCTOBER : month = "October"; break;
		case NOVEMBER : month = "November"; break;
		case DECEMBER : month = "December"; break;
		default : break;
	}
	ofst << "This is a bush: flowering month = " << month << ". ";
}
