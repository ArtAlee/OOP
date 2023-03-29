#include <iostream>
#include <sstream>
#include<string>
#include "sequence.h"
#include "gtest/gtest.h"
using namespace sequence;


TEST(Constructorlego, ArrConstructor) {
	int mass[] = {0,1,2,3,4,5,6};
	Sequence s(7, mass);
	for (int i = 0; i < 7; ++i) {
		ASSERT_EQ(i, s[i]);
	}
}

TEST(Constructor, BigArray) {
	int mass[1000];
	Sequence s;
	ASSERT_NO_THROW(Sequence s(1000, mass));
}


TEST(Constructor, DefaultConstructor) {
	Sequence s;
	ASSERT_EQ(0, s.getsize());
	ASSERT_ANY_THROW(s[9]);
	s.addEl(5);
	ASSERT_EQ(5, s[0]);
}

TEST(SequenceMethods, Adding) {
	Sequence a(10), b(15);
	a+=b;
	Sequence c = a + b;
	ASSERT_EQ(2, a.getsize());
	ASSERT_EQ(3, c.getsize());
	ASSERT_EQ(15, a[1]);
	ASSERT_EQ(15, c[2]);
	for (size_t i = 0; i < 200; ++i) {
		a.addEl(i);
		b.addEl(i*2);
	}
	ASSERT_EQ(202, a.getsize());
	ASSERT_EQ(201, b.getsize());
	Sequence d;
	ASSERT_NO_THROW(d = a+b);
	ASSERT_EQ(403, d.getsize());
}

TEST(SequenceMethods, Increasing) {
	int mass[] = {0,1,2,10,-100,-6,-1};
	Sequence s(7, mass);
	Sequence res = *s;
	ASSERT_EQ(4, res.getsize());
}


TEST(SequenceMethods, frequency) {
	int mass[] = {0,1,2,2,2,2,-1};
	Sequence s(7, mass);
	ASSERT_EQ(4, s.frequency(2));
	
}

TEST(SequenceMethods, Groups) {
	int mass[] = {0,1,2,2,5,5,-1};
	Sequence s(7, mass);
	ASSERT_EQ(5, s.groupCount());
}


TEST(SequenceMethods, PostPref) {
	int mass[] = {0,1,2,2};
	Sequence s(4, mass);
	s--;
	--s;
	ASSERT_EQ(2, s.getsize());
	--s;
	--s;
	ASSERT_ANY_THROW(s--);
}

TEST(SequenceMethods, Join) {
	int m1[] = {0,1,2,3,4};
	int m2[] = {5,6,7,8,9};
	Sequence a(5, m1);
	Sequence b(5, m2);
	Sequence c = a + b;
	for (int i = 0; i < 10; ++i) {
		ASSERT_EQ(i, c[i]);
	}
}

// new
TEST(SequenceOperators, MovigOperator) {
	int m[] = {5,6,7,8,9};
	Sequence a(5, m);
	Sequence res = --a;
	ASSERT_EQ(4, a.getsize());
	for (int i = 5; i < 9; ++i) {
		ASSERT_EQ(i, res[i-5]);
	} 
}


TEST(SequenceOperators, CopyOperator) {
	Sequence a;
	for (int i = 0; i < 500; ++i) {
		a.addEl(i);
	}
	Sequence b = a;
	for(int i = 0; i < 500; ++i) {
		ASSERT_EQ(i, b[i]);
	}
 }


TEST(SequenceOperators, Eqconstructor) {
    Sequence a;
    for (int i = 0; i < 100; i++) {
        a.addEl(i);
    }
    Sequence b = a;
    ASSERT_EQ(5, b[5]);
}

TEST(SequenceOperators, StreamInput) {
	Sequence s;
	std::stringstream input;
	input << 2 << '\n' <<21 << '\n' << 231;
	input >> s;
	ASSERT_EQ(231, s[1]);
	
}


TEST(SequenceOperators, StreamOutput) {
	int m[] = {5,2,3,4,5,6,7};
	Sequence s(7, m);
	std::stringstream output;
	output << s;
	std::string str;
	output >> str;
	ASSERT_EQ('5', str[0]);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}






