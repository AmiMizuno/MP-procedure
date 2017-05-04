#include "bush.h"
#include <string>



void in(bush &b, std::ifstream &ifst)
{
	std::string month;
	ifst >> month;
	if (month == "January")
		b.flowering = bush::JANUARY;
	else if (month == "February")
		b.flowering = bush::FEBRUARY;
	else if (month == "March")
		b.flowering = bush::MARCH;
	else if (month == "April")
		b.flowering = bush::APRIL;
	else if (month == "May")
		b.flowering = bush::MAY;
	else if (month == "June")
		b.flowering = bush::JUNE;
	else if (month == "July")
		b.flowering = bush::JULY;
	else if (month == "August")
		b.flowering = bush::AUGUST;
	else if (month == "September")
		b.flowering = bush::SEPTEMBER;
	else if (month == "October")
		b.flowering = bush::OCTOBER;
	else if (month == "November")
		b.flowering = bush::NOVEMBER;
	else if (month == "December")
		b.flowering = bush::DECEMBER;
}


void out(bush &b, std::ofstream &ofst)
{
	std::string month;
	switch (b.flowering)
	{
		case bush::JANUARY : month = "January"; break;
		case bush::FEBRUARY : month = "February"; break;
		case bush::MARCH : month = "March"; break;
		case bush::APRIL : month = "April"; break;
		case bush::MAY : month = "May"; break;
		case bush::JUNE : month = "June"; break;
		case bush::JULY : month = "July"; break;
		case bush::AUGUST : month = "August"; break;
		case bush::SEPTEMBER : month = "September"; break;
		case bush::OCTOBER : month = "October"; break;
		case bush::NOVEMBER : month = "November"; break;
		case bush::DECEMBER : month = "December"; break;
		default : break;
	}
	ofst << "This is a bush: flowering month = " << month;
}


