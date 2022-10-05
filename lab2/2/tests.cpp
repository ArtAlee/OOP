#include "strophoid.h"
#include "gtest/gtest.h"
using namespace lab2;

TEST(Constructor, DefaultConstructor) {
	Strophoid s;
	ASSERT_EQ(1, s.getA().x);
	ASSERT_EQ(0, s.getA().y);
}



TEST(Constructor, Getters_and_setters) {
	const Point p1(12, 0);
	const Point p2(10, 0);
	Strophoid s(p1);
	ASSERT_EQ(12, s.getA().x);
	ASSERT_EQ(0, s.getA().y);
	s.setA(p2);
	ASSERT_EQ(10, s.getA().x);
}

TEST(StrophoidMethods, Parameters) {
	Strophoid s1(5.6);
	ASSERT_NEAR(8.13661, s1.getY(2), 0.001);
	ASSERT_NEAR(4.31318, s1.getRo(1), 0.001);
	ASSERT_NEAR(7.9196, s1.getRad(), 0.001);
	ASSERT_NEAR(13.4598, s1.area(), 0.001);
	ASSERT_NEAR(s1.area(), s1.area2(), 0.001);
	ASSERT_NEAR(213.124, s1.volumeSpin(), 0.001);
	ASSERT_NEAR(111.98, s1.asympArea(), 0.001);
	Point pp(0, 0);
	ASSERT_ANY_THROW(Strophoid s2 = Strophoid(pp));

}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}