//
//  module.h
//  lab4
//
//  Created by Artem Aleksenko on 29.11.2022.
//

#ifndef module_h
#define module_h
#include "field.h"
#include "criminal.h"
#include <vector>
//#include <list>
#include "List.cpp"
namespace game {

enum class ModuleType{
    GUN,
    SENSOR,
    NETWORK,
    MODULE,
};


/// Base class of modules, that can be set to
/// a platform
class Module {
public:
    size_t energySupply_; // charging possibility
    size_t power_=10; // energy wasted per time
    size_t slotSize_; // slots needed for it
    bool isOn_ = false;
    
    Module(size_t energySupply=10, size_t power=10, size_t slotSize=1);
    size_t getPower();
    bool isWorking();
    size_t getSlotsize();
    size_t getEnergySupply();
    /// Swithing the mode of module
    void powerSwitch();
    virtual ModuleType getType();
    //virtual void action();
    virtual ~Module()=default;
};



/// Class that detects criminal
class Sensor: public Module {
public:
    size_t range_;
    
    Sensor(size_t range=3);
    size_t getRange();
    ModuleType getType() override;
    
    /// Criminal searching function
    /// - Parameters:
    ///   - f: game field
    ///   - p: coordinate of sensor
    virtual std::pair<Point, bool> getInformation(Field &f, Point& p);
    //void action() override;
    
};


/// Module that performs connection between sensors
class Network: public Module{
public:
    List<std::shared_ptr<Network>>& networks_;
    
    size_t area_=7;
    Point coordinate_;
    std::shared_ptr<Sensor> sensor_;
    
    Network()=delete;
    Network(List<std::shared_ptr<Network>>& networks, int range);
    Network(List<std::shared_ptr<Network>>& networks);
    
    /// Returns list of all networks on the field
    List<std::shared_ptr<Network>>& getNConnections();
    /// Finds nearest partner according to range of network. Returns nullptr if it doesn't exists
    std::shared_ptr<Network> getPartner();
    ModuleType getType() override;
    
};

/// Class to shoot criminals
class Gun: public Module{
public:
    size_t damage_ = 50;
    size_t range_ = 4;
    
    ModuleType getType() override;
    /// Make damage on criminal
    /// - Parameter criminal: Aim
    void shoot(Criminal &criminal);
};


}

#endif /* module_h */
