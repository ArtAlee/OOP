#include <iostream>
#include <sstream>
#include<string>
#include "sequence.h"

using namespace std;
using namespace sequence;


int main() {
	Sequence s;
	int a;
	stringstream buff;
	buff << 1 << 2 << 3;
	stringstream inbuf;
	inbuf << 1 << '\n' << 2 << 4 << 5;

	inbuf >> s;
	s.print(cout);
	return 0;
}