//
//  game_classes.h
//  lab4
//
//  Created by Artem Aleksenko on 13.11.2022.
//

#ifndef game_classes_h
#define game_classes_h
#include <vector>
#include <iostream>
#include "module.h"
#include "component.h"
#include "criminal.h"
#include "field.h"
#include "point.h"
#include "platform.h"

namespace game{

    


/// Class to manipulate game objects
class Game{
public:
    Field field_;
    std::shared_ptr<Criminal> criminal_;
    List<std::shared_ptr<Network>> networks_;
    
    /// Game constructor with default field 10X10
    Game();
    /// Custom game consrtuctor
    /// - Parameters:
    ///   - fieldN: vertical size of field
    ///   - fieldM: horizontal size of fild
    ///   - platforms: platform's coordinates
    ///   - walls: wall's coordinates
    ///   - criminalPoint: coopdinate of Criminal start position
    Game(size_t fieldN, size_t fieldM, std::vector<Point> platforms, std::vector<Point> walls, Point& criminalPoint);
    Game(Field& f);
    /// Makes one step of platform perfomance
    /// 1) Gets information from sensor
    /// 2) if criminal is in visible area and range of gun is enough, shoots the criminal
    /// 3) Otherwise connects with nearest platform (if exists) and repeats the procces on it
    /// - Parameters:
    ///   - platform: performing platform
    ///   - point: point of platform
    void platformProcess(Platform &platform, Point &point);
    /// Scans all field, saves coordinate of criminal. Than runs platformprocces() on platforms and
    void makeStep();
    void print();
    /// Returns all existing networks on field
    std::vector<std::shared_ptr<Platform>> getPlatforms();
    /// Sets network on platform
    /// - Parameter point: coordinate of platform
    void setNetwork(Point point, size_t range=7);
    void criminalMover();
    void show();
    void gameModify();
    
};

}

#endif /* game_classes_h */
