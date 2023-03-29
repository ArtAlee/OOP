//
//  module.cpp
//  lab4
//
//  Created by Artem Aleksenko on 29.11.2022.
//

#include "module.h"
//#include "criminal.h"
#include "field.h"
#include <iostream>
#include <float.h>
#include "List.cpp"
using namespace game;
using namespace std;

Module::Module(size_t energySupply, size_t power, size_t slotSize) : energySupply_(energySupply),
                                                            power_(power), slotSize_(slotSize){
                                    
                                                                
}


bool Module::isWorking(){
    return isOn_;
}


size_t Module::getPower() {
    return power_;
}

size_t Module::getSlotsize(){
    return slotSize_;
}

size_t Module::getEnergySupply(){
    return energySupply_;
}

void Module::powerSwitch(){
    isOn_ = !isOn_;
}

//void Module::action(){}


ModuleType Module::getType(){
    return  ModuleType::MODULE;
}







// ?????
Sensor::Sensor(size_t range): range_(range){}
/*
std::pair<Point, bool> Sensor::getInformation(Field &f, Point& p){
    size_t rowMin, rowMax, colMin, colMax;
    rowMin = p.row_ > range_ ? p.row_ - range_ : 0;
    colMin =p.col_ > range_ ? p.col_ - range_ : 0;
    rowMax = std::min(f.n_, p.row_ + range_);
    colMax = std::min(f.m_, p.col_ + range_);
    for (size_t i = rowMin; i < rowMax; ++i) {
        for (size_t j = colMin; j < colMax; ++j) {
            if (f.components_[i][j] &&(f.components_[i][j])->getType() == GameType::CRIMINAL) {
                //std::cout << "criminal!!!!\n";
                return make_pair(Point(i, j), true);
            }
        }
    }
    return std::make_pair<Point, bool>(Point(), false);
    
}
*/


void BFS(std::pair<Point, bool>& result, Field& f, Point p, int depth, size_t maxDepth, std::vector<vector<bool>> used){
    if (p.row_ >= f.n_ || p.row_ >= f.m_) return;
    if (used[p.row_][p.col_]) return;
    used[p.row_][p.col_] = true;
    if (f.components_[p.row_][p.col_] && f.components_[p.row_][p.col_]->getType() == GameType::WALL) return;
    if (f.components_[p.row_][p.col_] && f.components_[p.row_][p.col_]->getType() == GameType::CRIMINAL) {
        result.first = p;
        result.second = true;
        return;
    }
    if (depth == maxDepth) return;
    
    if (p.row_ - 1 >= 0) {
        Point p1(p.row_-1, p.col_);
        BFS(result, f, p1, depth+1, maxDepth,used);
    }
    if (p.row_+1 < f.n_) {
        Point p2(p.row_+1, p.col_);
        BFS(result, f, p2, depth+1, maxDepth,used);
    }
    if (p.col_ - 1 >= 0) {
        Point p3(p.row_, p.col_-1);
        BFS(result, f, p3, depth+1, maxDepth,used);
    }
    if(p.col_ +1 < f.m_) {
        Point p4(p.row_, p.col_+1);
        BFS(result, f, p4, depth+1, maxDepth,used);
    }
}


std::pair<Point, bool> Sensor::getInformation(Field &f, Point& p){
    std::vector<std::vector<bool>> used(f.n_);
    for (size_t i = 0; i < f.n_; ++i){
        used[i] = std::vector<bool>(f.m_);
    }
    //std::shared_ptr<Sensor> s = dynamic_pointer_cast<Sensor>(f.components_[p.row_][p.col_]);
    std::pair<Point, bool> res;
    BFS(res, f, p, 0, range_, used);
    return res;
    
}



    
    
size_t Sensor::getRange() {
        return range_;
    }
    
ModuleType Sensor::getType() {
    return ModuleType::SENSOR;
}
    
void Gun::shoot(Criminal &criminal) {
        criminal.takeDamage(damage_);
    }


ModuleType Gun::getType(){
    return ModuleType::GUN;
}




Network::Network(List<std::shared_ptr<Network>>& networks): networks_(networks){}


Network::Network(List<std::shared_ptr<Network>>& networks, int range): networks_(networks), area_(range){}


ModuleType Network::getType(){
    return ModuleType::NETWORK;
}


std::shared_ptr<Network> Network::getPartner(){
    std::shared_ptr<Network> res = nullptr;
    double curDist;
    double minDist=std::numeric_limits<double>::max();
    //List<s>::const_iterator it;
    for (auto it = networks_.begin(); it != networks_.end(); ++it){
        auto elem = *it;
        curDist = coordinate_.dist((*it)->coordinate_);
        if (curDist < minDist && curDist !=0) {
            minDist = curDist;
            res = *it;
        }
    }
    if (res && res->coordinate_.dist(coordinate_) < std::min(area_, res->area_)) {
        return res;
    }
    return nullptr;
}


List<std::shared_ptr<Network>>& Network::getNConnections(){
    return networks_;
}



