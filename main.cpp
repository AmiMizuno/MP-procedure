#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Container.h"
using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	check_infile(ifst);
	cout << "Start" << endl;
    Container c;
	init(c);
	in(c, ifst);
	ofstream ofst(argv[2]);
	check_outfile(ofst);
    ofst << "Filled container. " << endl;
	out(c, ofst);
	ofst << "Sorted container. " << endl;
	sort(c);
	out(c, ofst);
	ofst << endl;
    out_trees(c, ofst);
	clear(c);
    ofst << "Empty container. " << endl;
	out(c, ofst);
	ifst.close();
	ofst.close();
	cout << "Stop" << endl;
	return 0;
}
