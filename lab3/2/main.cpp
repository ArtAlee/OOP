#include <iostream>
#include "sequence.h"
#include "input.h"

using namespace std;
using namespace sequence;



int Dialog1(Sequence &s) {
	s.print(cout);
	return 0;
}

int Dialog2(Sequence &s) {
	int tmp;
	const char *mess = "Input element";
	input(tmp, mess);
	try {
		s +=tmp;
	}
	catch (overflow_error &e) {
		cout << e.what() << endl;
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
	catch (overflow_error &e) {
		cout << e.what() << endl;
	}
	Sequence res;
	try {
		res = s + s2;
	}
	catch (overflow_error &e) {
		cout << e.what() << endl;
	}  
	res.print(cout);
	return 0;
}

int Dialog4(Sequence &s) {
	Sequence res = *s;
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
	catch (overflow_error &e) {
		cout << e.what() << endl;
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
	catch (overflow_error &er) {
		cout << er.what() << endl;
	}
	return 0;
}

int Dialog9(Sequence &s){
	Sequence seq;
	cout << "prefix--" << endl;
	try {
		(--s).print(cout);
	}
	catch (underflow_error &e) {
		cout << e.what() << endl;
	}
	cout << "postfix--" << endl;
	try {
		seq = s--;
	}
	catch (underflow_error &e) {
		cout << e.what() << endl;
	}
	seq.print(cout);
	return 0;
}


int Dialog10 (Sequence &s) {
	int tmp;
	const char *mess = "Input index:";
	input(tmp, mess, -1);
	try {
		cout << s[tmp] << endl;
	}
	catch (range_error &e) {
		cout << e.what() << endl;
	}
	return 0;
}



int Dialog11(Sequence &s) {
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
	catch (overflow_error &e){
		cout << e.what() << endl;
	}
	int flag=0;
	while (flag == 0) {
		cout << endl;
		for (int i = 0; i < size; ++i) {
			cout << messages[i] << endl;
		}
		input(flag, "", 0, 12);
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
	const char *mess9 = "9. Postfix and prefix --";
	const char *mess10 = "10. []";
	const char *mess11 = "11. Quit";
	const char *messages[] = {mess1, mess2, mess3, mess4, mess5, mess6, mess7, mess8, mess9, mess10, mess11};
	int (*dialogs[])(Sequence &s) = {Dialog1, Dialog2, Dialog3, Dialog4, Dialog5, Dialog6, Dialog7, Dialog8, Dialog9, Dialog10, Dialog11};
	menu(messages, dialogs, 11);
	return 0;

}








