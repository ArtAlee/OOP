#ifndef component_h
#define component_h
#include <iostream>
#include "point.h"

namespace game {

enum class GameType{
    COMPONENT,
    PLATFORM,
    WALL,
    CRIMINAL
};

/// Base class of field's elements
class Component {
public:
    Point coordinate_;
    
    /// Type determinator
    virtual GameType getType();
    
    Component(size_t x=0, size_t y=0);
    const Point& getCoordinate()const;
    /// Displacement on field
    /// - Parameter point: destination
    virtual void move(Point& point);
    virtual ~Component()=default;

};


/// Obstacle object
class Wall: public Component{
public:
    GameType getType()override;
};

}
#endif /* component_h */
