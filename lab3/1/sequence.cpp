#include <iostream>
#include "sequence.h"
using namespace std;
using namespace sequence;


Sequence::Sequence(unsigned s, const int *numbers) : size(s) {
	if (s > MAX) {
		throw exception();
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = numbers[i];
	}
}


Sequence::Sequence() : size(0){};

Sequence::Sequence(int x) : size(1) {
	arr[0] = x;
}

size_t Sequence::getsize() const{return size;}

int Sequence::geti(int i) const{return arr[i];}
void Sequence::print(ostream &os) const {
	for (int i = 0; i < size; ++i) {
		os << arr[i] << " ";
	}
	cout << endl;
}


void Sequence::addEl(int x) {
	if (size == MAX) {
		throw exception();
	}
	arr[size++] = x;
}

Sequence& Sequence::addSequence(const Sequence &s) {
	if (size + s.size > MAX) {
		throw exception();
	}
	for (int i = 0; i < s.size; ++i) {
		addEl(s.arr[i]);
	}
	return *this;
}



//вернуть подпоследовательность в 
Sequence & Sequence::firstIncreasing() const{
	Sequence seq;
	int counter_plus = 1;
	int counter_minus = 1;
	int prev = arr[0];
	int idx;
	for (int i = 0; i < size; ++i) {
		if (arr[i] > prev) {
			counter_minus = 1;
			++counter_plus;
			if (counter_plus == 3) {
				idx = i - 2;
				break;
			}
		}
		if (arr[i] < prev) {
			counter_plus = 1;
			++counter_minus;
			if (counter_minus == 3) {
				idx = i - 2;
				break;
			}
		}		
		else counter_plus = counter_minus = 1;
		prev = arr[i];
	}
	if (counter_plus < 3 && counter_minus < 3) return seq;
	if (counter_plus == 3) {
		prev = arr[idx];
		seq.addEl(arr[idx++]);
		while(idx < size && arr[idx] > prev) {
			seq.addEl(arr[idx++]);
		}
	}
	if (counter_minus == 3) {
		prev = arr[idx];
		seq.addEl(arr[idx++]);
		while(idx < size && arr[idx] < prev) {
			seq.addEl(arr[idx++]);
		}
	}	
	return seq;
}

size_t Sequence::groupCount() const{
	size_t count = 0;
	int flag = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] == arr[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) ++count;
		flag = 0;
	}
	return count;
}
// size_t вместо инта
size_t Sequence::frequency(int x) const{
	size_t counter = 0;
	for(int i =0; i < size; ++i) {
		if (arr[i] == x) ++counter;
	}
	return counter;
}


Sequence & sequence::join(const Sequence & s1, const Sequence &s2) {
	Sequence res;
	if (s1.getsize()+ s2.getsize() > MAX) {
		throw exception();
	}
	for (int i = 0; i < s1.getsize(); ++i) {
		res.addEl(s1.geti(i));
	}
	for (int j = 0; j < s2.getsize(); ++j) {
		res.addEl(s2.geti(j));
	}
	return res;
}


Sequence &sequence::inp(istream &is, int s) {
	if(s > MAX) {
		throw exception();
	}
	Sequence seq;
	int el;
	for (int i =0; i < s; ++i) {
		is >> el;
		seq.addEl(el);
	}
	return seq;
} 





