//
//  GameObjectManager.cpp
//  Pang
//
//  Created by James Tease on 15/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#include <stdio.h>
#include "Game.h"
#include "GameObjectManager.h"


GameObjectManager::GameObjectManager() {}

GameObjectManager::~GameObjectManager() {
    std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::add(std::string name, GameObject* gameObject) {
//void GameObjectManager::add(std::string name, std::shared_ptr<GameObject> gameObject) {
    _gameObjects.insert(std::pair<std::string, GameObject*>(name, gameObject));
}

void GameObjectManager::remove(std::string name) {
    std::map<std::string, GameObject*>::iterator results = _gameObjects.find(name);
    if(results != _gameObjects.end()) {
        delete results->second;
        _gameObjects.erase(results);
    }
}

GameObject* GameObjectManager::get(std::string name) const {
    std::map<std::string, GameObject*>::const_iterator results = _gameObjects.find(name);
    if(results != _gameObjects.end()) {
        return NULL;
    }
    return results->second;
}

int GameObjectManager::getObjectCount() const {
    return _gameObjects.size();
}

void GameObjectManager::drawAll(sf::RenderWindow& window) {
    std::map<std::string, GameObject*>::const_iterator it = _gameObjects.begin();
    while(it != _gameObjects.end()) {
        it->second->draw(window);
        it++;
    }
}

void GameObjectManager::updateAll() {
    std::map<std::string, GameObject*>::const_iterator it = _gameObjects.begin();
    float timeDelta = clock.restart().asSeconds();
    while(it != _gameObjects.end()) {
        it->second->update(timeDelta);
        it++;
    }
}