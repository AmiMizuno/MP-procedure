#include <iostream>
#include <fstream>
#include <cstdlib>
#include "container.h"

using namespace std;


	void init(container &c);
	void clear(container &c);
	void sort(container &c);
	void in(container &c, ifstream &ifst);
	void out(container &c, ofstream &ofst);
	void outTrees(container &c, ofstream &ofst);


int main(int argc, char* argv[])
{
	if(argc != 3)	{
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	if (!ifst)
	{
		cerr << "Failed to read input file" << std::endl;
		exit(-1);
	}
	cout << "Start" << endl;
	container c;
	init(c);
	in(c, ifst);
	ofstream ofst(argv[2]);
	ofst << "Filled container. " << endl;
	sort(c);
	out(c, ofst);
	ofst << endl;
	outTrees(c, ofst);
	clear(c);
	ofst << "Empty container. " << endl;
	out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}
