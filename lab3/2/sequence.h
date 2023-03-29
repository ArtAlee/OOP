#ifndef SEQUENCE_H
#define SEQUENCE_H
#define MAX 10

namespace sequence {

	class Sequence {
	private:
		size_t size;
		int arr[MAX];
	
	public:
		Sequence(int x);
		Sequence(unsigned s, const int *arr);
		Sequence();
		size_t getsize()const;
		void addEl(int x);
		Sequence& addSequence(const Sequence &s);

		void print(std::ostream &os)const;
		void inp(std::istream &is, int s);
		Sequence firstIncreasing()const;
		size_t frequency(int x)const;
		size_t groupCount() const;
		// operators
		Sequence & operator+=(const Sequence &s);
		Sequence operator*()const;
		int operator[](size_t i) const;
		Sequence& operator--();
		Sequence operator--(int);
};
	Sequence inp(std::istream &is, int s);
	Sequence  join(const Sequence & s1, const Sequence &s2);
	Sequence operator+(const Sequence &s1, const Sequence &s2);

}
#endif

