#include <iostream>
#include "sequence.h"
#include "input.h"

using namespace std;
using namespace sequence;

//поймать исключения в добавлении и в создании

//dialog[i]();
int Dialog1(Sequence &s) {
	s.print(cout);
	return 0;
}

int Dialog2(Sequence &s) {
	int tmp;
	const char *mess = "Input element";
	input(tmp, mess);
	try {
		s.addEl(tmp);
	}
	catch (exception &ex) {
		cout << "Overflow" << endl;
	}
	return 0;
}

int Dialog3(Sequence &s) {
	int tmp;
	const char *mess = "Inupt size of seq.";
	input(tmp, mess, 0);
	Sequence s2;
	try {
		s2 = inp(cin, tmp);
	}
	catch (exception &ex) {
		cout << "size is larger than max possible";
	}
	Sequence res;
	try {
		res = join(s, s2);
	}
	catch (exception &ex) {
		cout << "Overflow" << endl;
	}  
	res.print(cout);
	return 0;
}

int Dialog4(Sequence &s) {
	Sequence res = s.firstIncreasing();
	if (res.getsize() == 0) {
		cout << "No increasing/decreasing sequences" << endl;
		return 0;
	}
	res.print(cout);
	return 0;
}

int Dialog5(Sequence &s) {
	int tmp;
	const char *mess = "Input element";
	input(tmp, mess);
	cout << s.frequency(tmp) << endl;
	return 0;
}


int Dialog6(Sequence &s) {
	cout << s.groupCount() << endl;
	return 0;
}


int Dialog7(Sequence &s) {
	int tmp;
	const char *mess = "Inupt size of seq.";
	input(tmp, mess, 0);
	Sequence s2 = inp(cin, tmp);
	try {
		s.addSequence(s2);
	}
	catch (exception &ex) {
		cout << "Overflow" << endl;
	}  
	s.print(cout);
	return 0;
}

int Dialog8(Sequence &s) {
	int count, tmp;
	const char *mess = "Inupt size of seq.";
	input(count, mess, 0, 101);
	int b[count];
	for (int i = 0; i < count; ++i) {
		input(tmp, "");
		b[i] = tmp;
	}
	try {
		s = Sequence(count, b);
	}
	catch (exception &ex) {
		cout << "Overflow" << endl;
	}
	return 0;
}


int Dialog9(Sequence &s) {
	return 1;
}




void menu(const char* messages[], int (*dialog[])(Sequence &s), int size) {
	int count;
	const char* mess = "Input size of seq.";
	input(count, mess, 0);
	Sequence s;
	cout << "Input elements" << endl;
	try {
		s = inp(cin, count);
	}
	catch (exception &ex){
		cout << "size larger than maximum possible" << endl;
	}
	int flag=0;
	while (flag == 0) {
		cout << endl;
		for (int i = 0; i < size; ++i) {
			cout << messages[i] << endl;
		}
		input(flag, "", 0, 10);
		flag = dialog[flag - 1](s);
	}
}









int main() {
	const char *mess1 = "1. Print";
	const char *mess2 = "2. Add an element";
	const char *mess3 = "3. Join two sequences";
	const char *mess4 = "4. Find first increasing or decreasing consequence";
	const char *mess5 = "5. Frequency of element";
	const char *mess6 = "6. Count of groups";
	const char *mess7 = "7. Add sequence";
	const char *mess8 = "8. Create new";
	const char *mess9 = "9. Quit";
	const char *messages[] = {mess1, mess2, mess3, mess4, mess5, mess6, mess7, mess8,mess9};
	int (*dialogs[])(Sequence &s) = {Dialog1, Dialog2, Dialog3, Dialog4, Dialog5, Dialog6, Dialog7, Dialog8, Dialog9};
	menu(messages, dialogs, 9);
	return 0;

}








