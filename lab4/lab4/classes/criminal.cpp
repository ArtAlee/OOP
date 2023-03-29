#include "criminal.h"
namespace game {
//Criminal

bool Criminal::isAlive() const{
    return health_ > 0;
}


Criminal::Criminal(int health) : health_(health){}

void Criminal::takeDamage(size_t damage) {
    health_ -= damage;
}


GameType Criminal::getType() {
    return GameType::CRIMINAL;
}

}




