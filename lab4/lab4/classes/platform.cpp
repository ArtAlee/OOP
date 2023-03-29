//
//  platform.cpp
//  lab4
//
//  Created by Artem Aleksenko on 04.12.2022.
//


#include "platform.h"

using namespace game;


Platform::Platform(size_t cap) : cap_(cap), size_(0){
    std::shared_ptr gun = std::make_shared<Gun>();
    std::shared_ptr sens = std::make_shared<Sensor>();
    modules_.push_front(gun);
    modules_.push_front(sens);
}


GameType Platform::getType() {
    return GameType::PLATFORM;
}



void Platform::setModule(std::shared_ptr<Module> module){
    if (size_ == cap_) {
        throw std::runtime_error("Platform is full");
    }
    if((*module).getType() == ModuleType::NETWORK) {
        for(auto it = modules_.begin(); it != modules_.end(); ++it) {
            if((*it)->getType() == ModuleType::SENSOR) {
                auto n = dynamic_pointer_cast<Network>(module);
                n->sensor_ = std::dynamic_pointer_cast<Sensor>(*it);
            }
        }
    }
    modules_.push_front(module);
    ++size_;
    if (energyLevel_ < (*module).power_) {
        (*module).isOn_ = false;
    }
    else {
       (*module).isOn_ = true;
        energyLevel_ -= (*module).power_;
    }
}

void Platform::removeModule() {
    if (size_ == 0) {
        throw std::runtime_error("No modules");
    }
    modules_.pop_back();
    --size_;
}



