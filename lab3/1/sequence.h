#ifndef SEQUENCE_H
#define SEQUENCE_H
#define MAX 15

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
		int geti(int i)const;
		void addEl(int x);
		Sequence& addSequence(const Sequence &s);

		void print(std::ostream &os)const;
		void inp(std::istream &is, int s);
		Sequence & firstIncreasing()const;
		size_t frequency(int x)const;
		size_t groupCount() const;
};
	Sequence &inp(std::istream &is, int s);
	Sequence & join(const Sequence & s1, const Sequence &s2);

}
#endif

