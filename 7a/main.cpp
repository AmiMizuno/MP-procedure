#include <iostream>
#include <fstream>
#include <cstdlib>
#include "container.h"

using namespace std;


void init(container &c);
void clear(container &c);
void in(container &c, ifstream &ifst);
void out(container &c, ofstream &ofst);
void multimethod(container &c, ofstream &ofst);


int main(int argc, char* argv[])
{
	if(argc != 3)	{
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;
	init(c);
	in(c, ifst);
	ofst << "Filled container. " << endl;
	multimethod(c, ofst);
	clear(c);
	ofst << "Empty container. " << endl;
	out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}
