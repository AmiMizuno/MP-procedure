#include <iostream>
#include <fstream>
#include <cstdlib>
#include "container.h"

using namespace std;

void Init(container &c);
void Clear(container &c);
void Sort(container &c);
void InContainer(container &c, ifstream &ifst);
void OutContainer(container &c, ofstream &ofst);
void OutTrees(container &c, ofstream &ofst);
void Multimethod(container &c, ofstream &ofst);

int Main(int argc, char* argv[])
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
	Init(c);
	InContainer(c, ifst);
	ofstream ofst(argv[2]);
	ofst << "Filled container. " << endl;
	Sort(c);
	Multimethod(c, ofst);
	ofst << endl;
	OutTrees(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	OutContainer(c, ofst);
	ifst.close();
 	ofst.close();
	cout << "Stop" << endl;
	return 0;
}
