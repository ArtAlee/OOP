//
//  criminal.h
//  lab4
//
//  Created by Artem Aleksenko on 04.12.2022.
//

#ifndef criminal_h
#define criminal_h
#include <iostream>
#include "point.h"
#include "component.h"
namespace game {
/// Active game class
class Criminal: public Component{
public:
    int health_;
    

    Criminal(int health=100);
    GameType getType()override;
    /// Checks if criminal is alive by it's health
    bool isAlive()const;
    /// Subtracts damage parameter from health
    void takeDamage(size_t damage);
};




}

#endif /* criminal_h */
