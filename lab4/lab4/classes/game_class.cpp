#include <iostream>
#include <vector>
#include "game_class.h"
#include "module.h"
#include "component.h"
#include "criminal.h"
#include "field.h"
#include "point.h"
#include "platform.h"
#include "List.cpp"
using namespace std;
using namespace game;



Game::Game(size_t fieldN, size_t fieldM, std::vector<Point> platforms, std::vector<Point> walls, Point& criminal){
    field_ = Field(fieldN, fieldM);
    for(size_t i = 0; i < platforms.size(); ++i) {
        field_.addPlatform(platforms[i]);
    }
    for(size_t i = 0; i < walls.size(); ++i) {
        field_.addWall(walls[i]);
    }
    field_.addCriminal(criminal);
    criminal_ = dynamic_pointer_cast<Criminal>(field_.components_[criminal.row_][criminal.col_]);
}

Game::Game(Field& f): field_(f){}

// default game constructor
Game::Game() {
    field_ = Field(10,10);
    Point pCrim(0,0);
    field_.addCriminal(pCrim);
    criminal_ = dynamic_pointer_cast<Criminal>(field_.components_[0][0]);
    for(size_t i = 2; i < 10; ++i) {
        Point pWall(i, 2);
        field_.addWall(pWall);
    }
    for(size_t j=3; j < 6; ++j){
        Point pWall(2, j);
        field_.addWall(pWall);
    }
    Point p1(4,3);
    Point p2(4,9);
    Point p3(6,3);
    Point p4(6,9);
    Point p5(8,3);
    Point p6(8,9);
    field_.addPlatform(p1);
    field_.addPlatform(p2);
    field_.addPlatform(p3);
    field_.addPlatform(p4);
    field_.addPlatform(p5);
    field_.addPlatform(p6);
    
}

void Game::platformProcess(Platform &platform, Point &point) {
    List<std::shared_ptr<Module>>::iterator it;
    std::pair<Point, bool> criminalPoint;
    std::shared_ptr<Sensor> sens;
    std::shared_ptr<Gun> gun;
    std::shared_ptr<Network> network;
    for (it = platform.modules_.begin(); it != platform.modules_.end(); ++it){
        if ((*it)->getType() == ModuleType::SENSOR) {
            sens = std::dynamic_pointer_cast<Sensor>((*it));
            criminalPoint = sens->getInformation(field_, point);
        }
        if ((*it)->getType() == ModuleType::GUN) {
            gun = dynamic_pointer_cast<Gun>(*it);
        }
        if ((*it)->getType() == ModuleType::NETWORK) {
            network = dynamic_pointer_cast<Network>(*it);
        }
    }
    if (criminalPoint.second && gun && point.dist(criminalPoint.first) <= gun->range_) {
        size_t i = criminalPoint.first.row_;
        size_t j = criminalPoint.first.col_;
        auto c = dynamic_pointer_cast<Criminal>(field_.components_[i][j]);
        gun->shoot(*c);
    }
    else if (network) {
        network = network->getPartner();
        if (network) {
            criminalPoint = network->sensor_->getInformation(field_, network->coordinate_);
            if (criminalPoint.second && gun && point.dist(criminalPoint.first) <= gun->range_) {
                size_t i = criminalPoint.first.row_;
                size_t j = criminalPoint.first.col_;
                auto crim = dynamic_pointer_cast<Criminal>(field_.components_[i][j]);
                gun->shoot(*crim);
            }
        }
    }
}



void Game::makeStep() {
    std::shared_ptr<Criminal> criminal = nullptr;
        for (size_t i = 0; i < field_.n_; ++i) {
            for(size_t j = 0; j < field_.m_; ++j) {
                if (field_.components_[i][j] && field_.components_[i][j]->getType() == GameType::CRIMINAL) {
                    criminal = dynamic_pointer_cast<Criminal>(field_.components_[i][j]);
                }
                if (field_.components_[i][j] && field_.components_[i][j]->getType() == GameType::PLATFORM) {
                    Platform& platform = dynamic_cast<Platform&>(*field_.components_[i][j]);
                    Point p(i, j);
                    platformProcess(platform, p);
                }
            }
    }
  //  if(criminal && criminal->isAlive() == false){
   //     field_.remove(criminal->coordinate_);
   // }
}


std::vector<std::shared_ptr<Platform>> Game::getPlatforms(){
    std::vector<shared_ptr<Platform>> platforms;
    for (size_t i = 0; i < field_.n_; ++i) {
        for(size_t j = 0; j < field_.m_; ++j) {
            if (field_.components_[i][j]) {
                if (field_.components_[i][j]->getType() == GameType::PLATFORM) {
                    auto pl = dynamic_pointer_cast<Platform>(field_.components_[i][j]);
                    platforms.push_back(pl);
                }
            }
        }
    }
    return platforms;
}



void Game::print() {
    GameType gt;
    cout << ' ';
    for(size_t i = 0; i < field_.m_; ++i) {
        cout << '_';
    }
    cout << '\n';
    for (size_t i = 0; i < field_.n_; ++i) {
        cout << '|';
        for(size_t j = 0; j < field_.m_; ++j) {
            if (field_.components_[i][j] == nullptr) {
                cout << " ";
                continue;
            }
            gt = field_.components_[i][j]->getType();
            if (gt == GameType::WALL) cout << '#';
            if (gt == GameType::PLATFORM) cout << 'P';
            if (gt == GameType::CRIMINAL) cout << 'C';
        }
        cout << "|\n";
    }
    cout << ' ';
    for(size_t i = 0; i < field_.m_+1; ++i) {
        cout << '_';
    }
    cout << '\n';
}


void Game::setNetwork(Point point, size_t range){
    auto network = std::make_shared<Network>(networks_, range);
    network->coordinate_ = point;
    networks_.push_back(network);
    if (field_.components_[point.row_][point.col_]->getType() != GameType::PLATFORM) {
        throw runtime_error("component isn't platform");
    }
    auto plat = dynamic_pointer_cast<Platform>(field_.components_[point.row_][point.col_]);
    plat->setModule(network);
    
}


void Game::criminalMover(){
    char c;
    Point p(criminal_->coordinate_.row_, criminal_->coordinate_.col_);
    std::cin >> c;
    switch(c){
        case 'w':
            p.row_ -= 1;
            break;
        case 's':
            p.row_ += 1;
            break;
        case 'd':
            p.col_ += 1;
            break;
        case'a':
        {
            p.col_ -= 1;
            break;
        }
        default:
            criminalMover();
    }
    try{
        field_.move(criminal_, p);
    }
    catch(...){
        criminalMover();
    }
}


void Game::show(){
    Point p;
    std::vector<std::shared_ptr<Platform>> vec = getPlatforms();
    for(auto it = vec.begin(); it != vec.end(); ++it){
        std::cout << "Platform ";
        p = (*it)->getCoordinate();
        std::cout << '(' << p.row_ << ',' << p.col_ << ')' << '\n';
        for (auto iter = (*it)->modules_.begin(); iter != (*it)->modules_.end(); ++iter){
            if((*iter)->getType() == ModuleType::GUN) {
                std::shared_ptr<Gun> gun = dynamic_pointer_cast<Gun>((*iter));
                std::cout << "Gun:  ";
                std::cout << "Range = " << gun->range_ <<"; " << "Damage = " << gun->damage_ << '\n';
            }
            if((*iter)->getType() == ModuleType::SENSOR) {
                std::shared_ptr<Sensor> sens = dynamic_pointer_cast<Sensor>((*iter));
                std::cout << "Sensor:  ";
                std::cout << "Range = " << sens->range_ <<'\n';
            }
            if((*iter)->getType() == ModuleType::NETWORK) {
                std::shared_ptr<Network> net = dynamic_pointer_cast<Network>((*iter));
                std::cout << "Network:  ";
                std::cout << "Area = " << net->area_<<'\n';
            }
            std::cout <<'\n';
        }
        std::cout <<'\n';
    }
}
