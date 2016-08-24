//
//  PlayerBat.cpp
//  Pang
//
//  Created by James Tease on 15/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#include <stdio.h>
#include <cassert>
#include "PlayerBat.h"
#include "ResourcePath.hpp"
#include "Game.h"
#include <iostream>

PlayerBat::PlayerBat()
: _velocity(0),
_maxVelocity(600.0) {
    load(resourcePath() + "bat.png");
    assert(isLoaded());
    
    getSprite()
        .setOrigin(
            getSprite().getLocalBounds().width / 2,
            getSprite().getLocalBounds().height / 2
        );
}
PlayerBat::~PlayerBat() {}

void PlayerBat::draw(sf::RenderWindow &window) {
    std::cout << "drawing bat" << std::endl;
    GameObject::draw(window);
}

float PlayerBat::getVelocity() const {
    return _velocity;
}

void PlayerBat::update(float elapsedTime) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        std::cout << "left" << std::endl;
        _velocity -= 3.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        std::cout << "right" << std::endl;
        _velocity += 3.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity = 0.0f;
    }
    
    if(_velocity > _maxVelocity) {
        _velocity = _maxVelocity;
    }
    
    if(_velocity < -_maxVelocity) {
        _velocity = -_maxVelocity;
    }
    
    sf::Vector2f pos = this->getPosition();
    
    if(pos.x < getSprite().getLocalBounds().width / 2 ||
       pos.x > (Game::SCREEN_WIDTH - getSprite().getLocalBounds().width / 2)) {
        _velocity = -_velocity;
    }
    std::cout << _velocity << std::endl;
    
    getSprite().move(_velocity * elapsedTime, 0);
}