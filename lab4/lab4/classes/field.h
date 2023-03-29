//
//  field.h
//  lab4
//
//  Created by Artem Aleksenko on 30.11.2022.
//

#ifndef field_h
#define field_h
#include <vector>
#include "component.h"
//#include "platform.h"
//#include "criminal.h"
namespace game{

/// Game field, base element of game
class Field {
public:
    size_t n_;
    size_t m_;
    std::vector<std::vector<std::shared_ptr<Component>>> components_;
    Field(size_t n=10, size_t m =10);
    
    /// Moves object in point a to point b if it is possible
    /// - Parameters:
    ///   - a: departure point
    ///   - b: destination point
    void move(Point& a, Point& b);
    /// Moves given component to another position if it is possible
    void move(std::shared_ptr<Component> component, Point& b);
    /// Adds platform to a field
    void addPlatform(Point& point, size_t cap = 3);
    /// Adds wall to a field if it is possible
    void addWall(Point& point);
    /// Adds criminal to a field if it is possible
    void addCriminal(Point& point, int health=100);
    /// Removes component from a field
    /// - Parameter point: coordinate of object to remove
    void remove(Point& point);

};




}



#endif /* field_h */
