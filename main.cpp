#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Container.h"
using namespace std;
void init(Container &c);
void clear(Container &c);
void sort(Container &c);
void in(Container &c, ifstream &ifst);
void out(Container &c, ofstream &ofst);
void outTrees(Container &c, ofstream &ofst);

int main(int argc, char* argv[])
{
    if(argc != 3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
    if (!ifst) {
		cerr << "Failed to read input file" << std::endl;
		exit(-1);
	}
	cout << "Start" << endl;
    Container c;
	init(c);
	in(c, ifst);
	ofstream ofst(argv[2]);
    ofst << "Filled container. " << endl;
	sort(c);
	out(c, ofst);
	ofst << endl;
    out_trees(c, ofst);
	clear(c);
    ofst << "Empty container. " << endl;
	out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}
