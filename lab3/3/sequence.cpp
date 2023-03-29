#include <iostream>
#include "sequence.h"
#include "input.h"
using namespace std;
using namespace sequence;


void Sequence::Free() {
	if (size > 0) {
		delete[] arr;
		size = 0;
	}
}

Sequence::Sequence(size_t s, const int *numbers) : size(s) {
	

	if (size>0) arr = new int[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = numbers[i];
	}
}


Sequence::Sequence() : size(0) {
	//cout << "empty constructor" << endl;
};
Sequence::Sequence(int x) : size(1) {
	arr = new int;
	arr[0] = x;
}

Sequence::~Sequence(){
	Free();
}
// copy constructor
Sequence::Sequence(const Sequence &source) {
	//cout << "copy constructor" << endl;
	arr = new int[source.size];
	size = source.size;
	for (int i = 0; i < size; ++i) {
		arr[i] = source.arr[i];
	}
}


Sequence &Sequence::operator=(const Sequence &source) {
	//cout << "copy =" << endl;
	if (&source == this) return *this;
	Free();
	arr = new int[source.size];
	size = source.size;
	for(int i = 0; i < size; ++i) {
		arr[i] = source.arr[i];
	}
	return *this;
}

Sequence::Sequence(Sequence && source) {
	//cout << "contsr &&" << endl;
	arr = source.arr;
	size = source.size;
	source.size = 0;
}

Sequence &Sequence::operator=(Sequence && source) {
	//cout << "operator= with &&" << endl;
	if (&source == this) return *this;
	Free();
	arr = source.arr;
	size = source.size;
	source.size = 0;
	return *this;
}

size_t Sequence::getsize() const{return size;}


void Sequence::print(ostream &os) const {
	for (size_t i = 0; i < size; ++i) {
		os << arr[i] << " ";
	}
	cout << endl;
}


void Sequence::addEl(int x) {
	int *n_arr = new int[size+1];
	for (size_t i =0; i < size; ++i) n_arr[i] = arr[i];
	n_arr[size] = x;
	if (size > 0) delete[] arr;
	size++;
	arr = n_arr;
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


Sequence sequence::inp(istream &is, int s) {
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
	int count = 0;
	int newsize = size+s.size;
	int *n_arr;
	n_arr = new int[s.size + size];
	for (int i=0; i < size; ++i) {
		n_arr[count++] = arr[i];
	}
	for(int j = 0; j < s.size;++j) {
		n_arr[count++] = s.arr[j];
	}
	Free();
	arr = n_arr;
	size = newsize;
	return *this;
}


Sequence sequence::operator+(const Sequence &s1, const Sequence &s2) {
	Sequence copy = s1;
	try {
		copy += s2;
	}
	catch(bad_alloc &ba) {
		copy.Free();
	}
	return copy;
}

Sequence Sequence::operator*() const {
	Sequence seq;
	int counter_plus = 1;
	int counter_minus = 1;
	int prev = arr[0];
	size_t idx;
	for (size_t i = 1; i < size; ++i) {
		prev = arr[i-1];
		if (arr[i] > prev) {
			counter_minus = 1;
			++counter_plus;
			if (counter_plus == 3) {
				idx = i - 2;
				break;
			}
		}
		else if (arr[i] < prev) {
			counter_plus = 1;
			++counter_minus;
			if (counter_minus == 3) {
				idx = i - 2;
				break;
			}
		}		
		else counter_plus = counter_minus = 1;
		//prev = arr[i];
	}
	//cout << counter_plus << endl << counter_minus << endl;
	if (counter_plus < 3 && counter_minus < 3) return seq;
	int * vec = new int[size];
	int idx_vec = 0;
	if (counter_plus == 3) {
		prev = arr[idx];
		//seq.addEl(arr[idx++]);
		vec[idx_vec++] = arr[idx++];
		while(idx < size && arr[idx] > prev) {
			//seq.addEl(arr[idx++]);
			vec[idx_vec++] = arr[idx++];
		}
	}
	if (counter_minus == 3) {
		prev = arr[idx];
		//seq.addEl(arr[idx++]);
		vec[idx_vec++] = arr[idx++];
		while(idx < size && arr[idx] < prev) {
			//seq.addEl(arr[idx++]);
			vec[idx_vec++] = arr[idx++];
		}
	}
	seq.size = idx_vec;
	seq.arr = new int[idx_vec];
	for (int i = 0; i < seq.size; ++i) seq.arr[i] = vec[i];
	delete[] vec;
	return seq;
}


int Sequence::operator[](size_t i) const{
	if (i >= size) {
		throw range_error("Out of range");
	}
	return arr[i];
}

Sequence& Sequence::operator--() {
	if (size == 0) {
		throw underflow_error("Sequence is empty");
	}
	int newsize = size -1;
	int * n_arr = new int[size-1];
	for(int i = 0; i < size-1; ++i) {
		n_arr[i] = arr[i];
	}
	Free();
	arr= n_arr;
	size = newsize;
	return *this;
}

Sequence Sequence::operator--(int d) {
	int newsize = size -1;
	if (size == 0) {
		throw underflow_error("Sequence is empty");
	}
	Sequence copy = *this;
	int * n_arr = new int[size-1];
	for(int i = 0; i < size-1; ++i) {
		n_arr[i] = arr[i];
	}
	Free();
	arr= n_arr;
	size = newsize;
	return copy;
}



Sequence & sequence::join1(const Sequence &a, const Sequence &b) {
	Sequence result;
	for (size_t i = 0; i < a.getsize(); ++i) {
		result.addEl(a[i]);
	}
	for (size_t j = 0; j < b.getsize(); ++j) {
		result.addEl(b[j]);
	}
	return result;
}


Sequence sequence::join2(const Sequence &a, const Sequence &b) {
	Sequence result;
	for (size_t i = 0; i < a.getsize(); ++i) {
		result.addEl(a[i]);
	}
	for (size_t j = 0; j < b.getsize(); ++j) {
		result.addEl(b[j]);
	}
	return result;
}


ostream & sequence::operator <<(ostream & os, const Sequence &s) {
	for (size_t i =0; i < s.getsize(); ++i) {
		os << s[i] << " ";
	}
	os << endl;
	return os;
}
/*
istream& sequence::operator >> (istream& in, Sequence &s) {
	int count;
	int el;
	input(count, "enter size", 1);
	s.Free();
	s.arr = new int[count];
	s.size = count;
	for (size_t i =0; i < count; ++i) {
		input(el, "");
		s.arr[i] = el;
	}
	return in;
}

*/
istream& sequence::operator >> (istream& in, Sequence &s) {
	size_t count;
	int temp;
	in >> count;
	//cout << "count=" << count << endl;
	//s.size = count;
	for(size_t i =0; i < count; ++i) {
		in >> temp;
		s.addEl(temp);
	}
	return in;
}
