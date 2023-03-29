
#include "game_class.h"
#include "module.h"
#include "component.h"
#include "criminal.h"
#include "module.h"
#include "platform.h"
#include <iostream>
#include "classes/List.h"
#include "game_class.h"
#include "classes/List.cpp"
#include <memory>
#include <vector>
#include "play.h"
using namespace game;



Game gameCreator(int x){
    Game g;
    std::vector<Point> plat;
    std::vector<Point> walls;
    if (x == 0) {
        Game g;
        return g;
    }
    if (x == 2){
        for (int i = 0; i < 11;++i){
            walls.emplace_back(4,i);
        }
        for(int i = 7; i < 16; ++i){
            walls.emplace_back(i,2);
        }
        for (int i = 3; i < 9; ++i){
            walls.emplace_back(7,i);
        }
        for (int i = 5; i < 13; ++i){
            walls.emplace_back(i,10);
        }
        plat.emplace_back(12,5);
        plat.emplace_back(8,3);
        plat.emplace_back(15,15);
        plat.emplace_back(0,15);
        Point crim(15,0);
        Game g2(16,16,plat,walls,crim);
        return g2;
    }
    if(x == 3){
        for(int i=4; i < 11;++i){
            walls.emplace_back(i,3);
        }
        for(int i=7; i<16;++i){
            walls.emplace_back(7,i);
        }
        for(int i=9; i<18;++i){
            walls.emplace_back(16,i);
        }
        plat.emplace_back(14,1);
        plat.emplace_back(19,8);
        plat.emplace_back(11,5);
        plat.emplace_back(1,13);
        plat.emplace_back(8,15);
        plat.emplace_back(15,18);
        Point crimin(19,0);
        Game g3(20,20,plat,walls,crimin);
        return g3;
    }
    return g;
}




void gameModify(Game& g){
    Point p;
    int i = 0;
    int x, y;
    int cCoord, cDamage, cRange, choose;
    std::vector<std::shared_ptr<Platform>> vec = g.getPlatforms();
    std::vector<Point> points;
    g.show();
    std::cout << "Select platform to modify\nP(0 to exit)\n";
    for (auto it = vec.begin(); it != vec.end(); ++it, ++i){
        //points.push_back((*it)->getCoord());
        std::cout << i+1 << ". ";
        p = (*it)->getCoordinate();
        std::cout << '(' << p.row_ << ',' << p.col_ << ')' << '\n';
    }
    std::cin >> cCoord;
    if (cCoord == 0) return;
    std::shared_ptr<Platform> a = vec[cCoord-1];
    std::cout << "1. Modify sensor\n2. Modify Gun\n3. Set network\n";

    std::cin >> choose;
    if (choose == 3){
        p = vec[cCoord]->coordinate_;
        g.setNetwork(p);
        gameModify(g);
    }
    if (choose == 2) {
        for(auto it = a->modules_.begin(); it != a->modules_.end(); ++it){
            if ((*it)->getType() == ModuleType::GUN){
                std::shared_ptr<Gun> gun= dynamic_pointer_cast<Gun>(*it);
                std::cout << "Enter damage to set\n";
                std::cin >> cDamage;
                gun->damage_ = cDamage;
                std::cout << "Enter range to set\n";
                std::cin >> cRange;
                gun->range_ = cRange;
                gameModify(g);
            }
        }
    }
    if (choose == 1){
        for(auto it = a->modules_.begin(); it != a->modules_.end(); ++it){
            if ((*it)->getType() == ModuleType::SENSOR){
                std::shared_ptr<Sensor> sens= dynamic_pointer_cast<Sensor>(*it);
                std::cout << "Enter range to set\n";
                std::cin >> cRange;
                sens->range_ = cRange;
                gameModify(g);
            }
        }
    }
}


void menu(){
    int choose, choose2;
    char dest;
    int flag = 1;
    std::cout << "Select field\n1. 10x10(easy)\n2. 15x15(medium)\n3. 20x20(hard)\n";
    std::cin >> choose;
    Game game = gameCreator(choose);
    std::cout << "1. Play\n2. Creator mode\n";
    std::cin >> choose;
    if (choose == 2) gameModify(game);
    while(flag){
        game.print();
        //std::cin >> dest;
        game.criminalMover();
        game.makeStep();
        if (game.criminal_->isAlive() == false) {
            flag = 0;
            std::cout << "Game over\n";
            std::cout << "1.Play again\n2.Exit\n";
            std::cin >> choose2;
            if(choose2 == 1) menu();
            else return;
        }
        
    }
}

