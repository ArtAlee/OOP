#include <iostream>

#include "component.h"
using namespace game;

//Component

Component::Component(size_t x, size_t y) : coordinate_(Point(x,y)){}

GameType Component::getType() {
    return GameType::COMPONENT;
}


			
const Point& Component::getCoordinate() const{
    return coordinate_;
}

void Component::move(Point &point){
    int a = abs((int)(point.row_- coordinate_.row_));
    int b = abs((int)(point.col_- coordinate_.col_));
    if (a < 2 && b < 2) {
        coordinate_.row_ = point.row_;
        coordinate_.col_ = point.col_;
    }
    else throw std::runtime_error("wrong range");
}


GameType Wall::getType() {
    return GameType::WALL;
}



