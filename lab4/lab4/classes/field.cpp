
#include "criminal.h"
#include "component.h"
#include "platform.h"
#include "field.h"
using namespace game;

Field::Field(size_t n, size_t m):n_(n), m_(m){
    components_ = std::vector<std::vector<std::shared_ptr<Component>>>(n_);
    for (size_t i = 0; i < n_; ++i) {
        components_[i] = std::vector<std::shared_ptr<Component>>(m_);
    }
    
}

void Field::move(Point& a, Point& b) {
    if (components_[b.row_][b.col_] != nullptr) {
        throw std::runtime_error("point is busy");
    }
    if (components_[a.row_][a.col_] == nullptr) {
        throw std::runtime_error("point is empty");
    }
    components_[a.row_][a.col_]->move(b);
    //std::swap(components_[a.row_][a.col_], components_[b.row_][b.col_]);
}

void Field::move(std::shared_ptr<Component> component, Point& b) {
    if (b.row_ >= n_ || b.col_ >= m_) {
        throw std::runtime_error("point is out of bounds");
    }
    if (components_[b.row_][b.col_] != nullptr) {
        throw std::runtime_error("point is busy");
    }
    Point prev = component->coordinate_;
    component->move(b);
    components_[b.row_][b.col_] = component;
    components_[prev.row_][prev.col_] = nullptr;
    

    
}

void Field::addCriminal(Point& point, int health) {
    if (components_[point.row_][point.col_] != nullptr) {
        throw std::runtime_error("point is busy");
    }
    components_[point.row_][point.col_] = std::make_shared<Criminal>(health);
    components_[point.row_][point.col_]->coordinate_ = point;
}


void Field::addWall(Point &point) {
    if (components_[point.row_][point.col_] != nullptr) {
        throw std::runtime_error("point is busy");
    }
    components_[point.row_][point.col_] = std::make_shared<Wall>();
    components_[point.row_][point.col_]->coordinate_ = point;
}


void Field::addPlatform(Point &point, size_t cap) {
    if (components_[point.row_][point.col_] != nullptr) {
        throw std::runtime_error("point is busy");
    }
    components_[point.row_][point.col_] = std::make_shared<Platform>();
    components_[point.row_][point.col_]->coordinate_ = point;
}


void Field::remove(Point &point) {
    components_[point.row_][point.col_] = nullptr;
}



