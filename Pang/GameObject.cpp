//
//  GameObject.cpp
//  Pang
//
//  Created by James Tease on 15/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#include <stdio.h>
#include "GameObject.h"

GameObject::GameObject()
    :_isLoaded(false) {}

GameObject::~GameObject() {}

void GameObject::load(std::string filename) {
    if(_texture.loadFromFile(filename) == false) {
        _filename = "";
        _isLoaded = false;
    } else {
        _filename = filename;
        _sprite.setTexture(_texture);
        _isLoaded = true;
    }
}

void GameObject::draw(sf::RenderWindow& window) {
    if(_isLoaded) {
        window.draw(_sprite);
    }
}

void GameObject::setPosition(float x, float y) {
    if(_isLoaded) {
        _sprite.setPosition(x, y);
    }
}