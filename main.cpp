#include <iostream>
#include <fstream>
#include <cstdlib>
#include "container.h"

using namespace std;

namespace flora {
	void init(container &c);
	void clear(container &c);
	void sort(container &c);
	void in(container &c, ifstream &ifst);
	void out(container &c, ofstream &ofst);
}
using namespace flora;

int main(int argc, char* argv[])
{
	if(argc != 3)	{
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);//вызов виртуальной таблицы
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;//создание контейнера
	init(c);
	in(c, ifst);
	ofst << "Filled container. " << endl;
	sort(c);
	out(c, ofst);
	clear(c);
	ofst << "Empty container. " << endl;
	out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}
