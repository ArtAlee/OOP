//
//  point.h
//  lab4
//
//  Created by Artem Aleksenko on 30.11.2022.
//

#ifndef point_h
#define point_h

#include <iostream>
#include <cmath>

namespace game{

struct Point {
    int row_;
    int col_;
    Point(int x=0, int y=0) : row_(x), col_(y){}
    /// Distance between two points on field
    double dist(Point b) {
        return sqrt(pow((int)(row_- b.row_), 2) + pow((int)(col_- b.col_), 2));
    }
    
};



}

#endif /* point_h */
