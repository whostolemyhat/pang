//
//  GameObjectManager.h
//  Pang
//
//  Created by James Tease on 15/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#pragma once
#include "GameObject.h"

class GameObjectManager {
public:
    GameObjectManager();
    ~GameObjectManager();
    
    void add(std::string name, GameObject* gameObject);
    void remove(std::string name);
    int getObjectCount() const;
    GameObject* get(std::string name) const;
    
    void drawAll(sf::RenderWindow& window);
    
private:
    std::map<std::string, GameObject*> _gameObjects;
    
    struct GameObjectDeallocator {
        void operator()(const std::pair<std::string, GameObject*> &p) const {
            delete p.second;
        }
    };
};
