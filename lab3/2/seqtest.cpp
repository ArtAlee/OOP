#include <iostream>
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

TEST(Constructor, DefaultConstructor) {
	Sequence s;
	ASSERT_EQ(0, s.getsize());
	ASSERT_ANY_THROW(s[9]);
}

TEST(SequenceMethods, Adding) {
	Sequence a(10), b(15);
	a+=b;
	Sequence c = a + b;
	ASSERT_EQ(2, a.getsize());
	ASSERT_EQ(3, c.getsize());
	ASSERT_EQ(15, a[1]);
	ASSERT_EQ(15, c[2]);
}

TEST(SequenceMethods, Increasing) {
	int mass[] = {0,1,2,10,4,-6,-1};
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
	Sequence c = join(a, b);
	for (int i = 0; i < 10; ++i) {
		ASSERT_EQ(i, c[i]);
	}
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
TEST(Network, CriticalShot) {
    Field f(30,30);
    Point pCrim(5,10);
    Point pPlat1(5,5);
    Point pPlat2(5,12);
    f.addCriminal(pCrim);
    shared_ptr<Criminal> crim = dynamic_pointer_cast<Criminal>(f.components_[5][10]);
    crim->health_ = 10;
    f.addPlatform(pPlat1);
    f.addPlatform(pPlat2);
    Game g(f);
    g.setNetwork(pPlat1);
    g.setNetwork(pPlat2);
    Platform& platform = dynamic_cast<Platform&>(*f.components_[5][5]);
    g.platformProcess(platform, pPlat1);
    ASSERT_EQ(0, crim->isAlive());
    
    
}

*/




