#ifndef platform_h
#define platform_h
#include "component.h"
#include "module.h"
#include "List.cpp"


namespace game {

/// Storage of several modules
class Platform: public Component {
public:
    size_t cap_ = 3;
    size_t size_ = 0;
    size_t energyLevel_=10;
    List<std::shared_ptr<Module>> modules_;
    
    GameType getType()override;
    Platform(size_t cap=3);
    /// Setting of module
    void setModule(std::shared_ptr<Module> module);
    /// Deleting module
    void removeModule();
    
};

}

#endif /* platform_h */
