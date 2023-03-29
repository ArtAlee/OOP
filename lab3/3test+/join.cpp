#include <iostream>
#include "sequence.h"


using namespace std;
using namespace sequence;


int main() {
	//int m1[] = {0,1,2,3,4};
	//int m2[] = {5,6,7,8,9};
	Sequence a, b, c, d;
	cin >> a;
	cin >> b;
	cout << "Testing join with &" << endl;
	c = join1(a, b);
	cout << c;
	cout << "Testing join with Seq" << endl;
	d = join2(a,b);
	cout << d;
}