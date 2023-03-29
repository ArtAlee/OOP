#ifndef SEQUENCE_H
#define SEQUENCE_H

namespace sequence {

	class Sequence {
	private:
		size_t size;
		int *arr;
		void Free();
	
	public:
		friend Sequence operator+(const Sequence &s1, const Sequence &s2);
		friend std::istream& operator >> (std::istream& in, Sequence& s);
		~Sequence();
		Sequence(int x);
		Sequence(size_t s, const int *arr);
		Sequence();
		Sequence(const Sequence &source);
		size_t getsize()const;
		void addEl(int x);
		Sequence(Sequence && source);
		void print(std::ostream &os)const;
		size_t frequency(int x)const;
		size_t groupCount() const;

		Sequence & operator=(Sequence && source);
		Sequence & operator=(const Sequence &s);
		Sequence & operator+=(const Sequence &s);
		Sequence operator*()const;
		int operator[](size_t i) const;
		Sequence& operator--();
		Sequence operator--(int d);
		
};
	std::ostream & operator <<(std::ostream & os, const Sequence &s);
	Sequence inp(std::istream &is, int s);
	Sequence &join1(const Sequence &a, const Sequence &b);
	Sequence join2(const Sequence &a, const Sequence &b);

}
#endif

