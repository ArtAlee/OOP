/*
#include <iostream>
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <memory>
#include "../game_class.h"
#include "../module.h"
#include "../component.h"
#include "../criminal.h"
#include "../module.h"
#include "../platform.h"
#include "../field.h"

using namespace game;
using namespace std;

TEST(Constuctor, DefaultConstructors) {
    Field f(10,10);
    ASSERT_EQ(f.n_, 10);
    ASSERT_EQ(f.m_, 10);
    Platform p(2);
    ASSERT_EQ(p.cap_, 2);
    Criminal c(150);
    ASSERT_EQ(150, c.health_);
    Module m(10, 15, 1);
    ASSERT_EQ(10, m.energySupply_);
    ASSERT_EQ(15, m.power_);
    ASSERT_EQ(1, m.slotSize_);
    Sensor s(3);
    ASSERT_EQ(3, s.range_);
    Gun g;
    ASSERT_EQ(50, g.damage_);
}

TEST(Gun, CriminalDeath) {
    Gun g;
    Criminal c(100);
    g.shoot(c);
    ASSERT_EQ(50, c.health_);
    g.shoot(c);
    ASSERT_EQ(0, c.isAlive());
}


TEST(Field, Polymorph){
    Field f(10, 10);
    Point p1(1,1);
    Point p2(2,2);
    Point p3(3,3);
    f.addCriminal(p1);
    f.addWall(p2);
    f.addPlatform(p3);
    ASSERT_EQ(GameType::CRIMINAL, f.components_[1][1]->getType());
    ASSERT_EQ(GameType::WALL, f.components_[2][2]->getType());
    ASSERT_EQ(GameType::PLATFORM, f.components_[3][3]->getType());
    
}


TEST(Sensor, SensorDetection) {
    Field f(10, 10);
    Point pcrim(2,2);
    Point pplatf(2,3);
    f.addCriminal(pcrim);
    f.addPlatform(pplatf);
    shared_ptr<Platform> plat = dynamic_pointer_cast<Platform>(f.components_[2][3]);
    shared_ptr<Sensor> s = dynamic_pointer_cast<Sensor>(plat->modules_.front());
    pair<Point, bool> res = s->getInformation(f, pplatf);
    ASSERT_EQ(1, res.second);
    ASSERT_EQ(2, res.first.row_);
    ASSERT_EQ(2, res.first.col_);
}

TEST(Criminal, Move){
    Field f(20, 20);
    Point p1(5,5);
    Point p2(5,6);
    Point p3(5,4);
    Point p4(10,10);
    f.addCriminal(p1);
    f.addWall(p3);
    auto crim = f.components_[5][5];
    f.move(crim, p2);
    ASSERT_EQ(6, crim->coordinate_.col_);
    ASSERT_ANY_THROW(f.move(crim, p3));
    ASSERT_ANY_THROW(f.move(crim, p4));
    
}




int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

*/





