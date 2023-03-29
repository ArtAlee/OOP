#include <iostream>
#include "sequence.h"
using namespace std;
using namespace sequence;


Sequence::Sequence(unsigned s, const int *numbers) : size(s) {
	if (s > MAX) {
		throw overflow_error("too many elements");
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

void Sequence::print(ostream &os) const {
	for (size_t i = 0; i < size; ++i) {
		os << arr[i] << " ";
	}
	cout << endl;
}


void Sequence::addEl(int x) {
	if (size == MAX) {
		throw overflow_error("too many elements");
	}
	arr[size++] = x;
}

Sequence& Sequence::addSequence(const Sequence &s) {
	if (size + s.size > MAX) {
		throw overflow_error("too many elements");
	}
	for (size_t i = 0; i < s.size; ++i) {
		addEl(s.arr[i]);
	}
	return *this;
}


Sequence Sequence::firstIncreasing() const{
	Sequence seq;
	int counter_plus = 1;
	int counter_minus = 1;
	int prev = arr[0];
	size_t idx;
	for (size_t i = 0; i < size; ++i) {
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
	for (size_t i = 0; i < size; ++i) {
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


size_t Sequence::frequency(int x) const{
	size_t counter = 0;
	for(size_t i =0; i < size; ++i) {
		if (arr[i] == x) ++counter;
	}
	return counter;
}


Sequence sequence::join(const Sequence & s1, const Sequence &s2) {
	Sequence res;
	if (s1.getsize()+ s2.getsize() > MAX) {
		throw overflow_error("too many elements");
	}
	for (size_t i = 0; i < s1.getsize(); ++i) {
		res.addEl(s1[i]);
	}
	for (size_t j = 0; j < s2.getsize(); ++j) {
		res.addEl(s2[j]);
	}
	return res;
}


Sequence sequence::inp(istream &is, int s) {
	if(s > MAX) {
		throw overflow_error("too many elements");
	}
	Sequence seq;
	int el;
	for (size_t i =0; i < s; ++i) {
		is >> el;
		seq.addEl(el);
	}
	return seq;
} 

// operators


Sequence& Sequence::operator+=(const Sequence& s) {
	for (size_t i = 0; i < s.size; ++i) {
		addEl(s.arr[i]);
	}
	return *this;
}


Sequence sequence::operator+(const Sequence &s1, const Sequence &s2) {
	Sequence copy = s1;
	copy += s2;
	return copy;
}

Sequence Sequence::operator*() const {
	return firstIncreasing();
}


int Sequence::operator[](size_t i) const{
	if (i >= size) {
		throw range_error("out of range");
	}
	return arr[i];
}

Sequence& Sequence::operator--() {
	if (size == 0) {
		throw underflow_error("seq. is empty");
	}
	--size;
	return *this;
}

Sequence Sequence::operator--(int) {
	if (size == 0) {
		throw underflow_error("seq is empty");
	}
	Sequence copy = *this;
	--size;
	return copy;
}

//throw invalid arguements or runtime error


