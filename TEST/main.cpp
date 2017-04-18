#include <iostream>
#include <fstream>
#include <cstdlib>
#include "container.h"

using namespace std;


	void init(container &c);
	void clear(container &c);
	void sort(container &c);
    void In(container &c, ifstream &ifst);
    void Out(container &c, ofstream &ofst);
	void outTrees(container &c, ofstream &ofst);



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
    In(c, ifst);
	ofst << "Filled container. " << endl;
	sort(c);
    Out(c, ofst);
	ofst << endl;
	outTrees(c, ofst);
	clear(c);
	ofst << "Empty container. " << endl;
    Out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}
