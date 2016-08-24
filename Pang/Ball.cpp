//
//  Ball.cpp
//  Pang
//
//  Created by James Tease on 02/05/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#include <stdio.h>
#include "Game.h"
#include "Ball.h"
#include "ResourcePath.hpp"
#include <cassert>
#include <cmath>

Ball::Ball() :
_velocity(230.0f),
_elapsedTime(0.0f) {
    load(resourcePath() + "ball.png");
    assert(isLoaded());
    
    getSprite().setOrigin(15, 15);
    
    _angle = std::rand() % 360 + 1;
}

Ball::~Ball() {}

void Ball::update(float elapsedTime) {
    _elapsedTime += elapsedTime;
    
    if(_elapsedTime < 3.0f) {
        return;
    }
    
    float moveAmount = _velocity * elapsedTime;
    
    float moveByX = linearVelocityX(_angle) * moveAmount;
    float moveByY = linearVelocityY(_angle) * moveAmount;
    
    // left hand collision
    if(getPosition().x + moveByX <= 0 + getWidth() / 2 ||
       getPosition().x + getHeight() / 2 + moveByX >= Game::SCREEN_WIDTH) {
        _angle = 360.0f - _angle;
        if(_angle > 260.0f && _angle < 280.0f) {
            _angle += 20.0f;
        }
        
        if(_angle > 80.0f && _angle < 100.0f) {
            _angle += 20.0f;
        }
        
        moveByX = -moveByX;
    }
    
    PlayerBat* bat = dynamic_cast<PlayerBat*>(Game::getManager().get("player1"));
    
    if(bat != NULL) {
        sf::Rect<float> batRect = bat->getBoundingRect();
        if(batRect.intersects(getBoundingRect())) {
            _angle = 360.0f - (_angle - 180.0f);
            
            if(_angle > 360.0f) {
                _angle -= 360.0f;
            }
            
            moveByY = -moveByY;
            
            //make sure ball isn't in bat
            if(getBoundingRect().width > bat->getBoundingRect().top) {
                setPosition(getPosition().x, bat->getBoundingRect().top - getWidth() / 2 - 1);
            }
            
            // change angle based on player velocity
            float playerVelocity = bat->getVelocity();
            
            if(playerVelocity < 0) {
                _angle -= 20.0f;
                if(_angle < 0) {
                    _angle = 360.0f - _angle;
                }
            } else if (playerVelocity > 0) {
                _angle += 20.0f;
                if(_angle > 360.0f) {
                    _angle = _angle - 360.0f;
                }
            }
            
            _velocity += 5.0f;
        }
        
        if(getPosition().y - getHeight() / 2 <= 0) {
            _angle = 180 - _angle;
            moveByY = -moveByY;
        }
        
        if(getPosition().y + getHeight() / 2 + moveByY >= Game::SCREEN_HEIGHT) {
            getSprite().setPosition(Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT / 2);
            _angle = (rand() % 360) + 1;
            _velocity = 230.0f;
            _elapsedTime = 0.0f;
        }
        
        getSprite().move(moveByX, moveByY);
    }
}

float Ball::linearVelocityX(float angle) {
    angle -= 90;
    if(angle < 0) {
        angle = 360 + angle;
    }
    
    return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float Ball::linearVelocityY(float angle) {
    angle -= 90;
    if(angle < 0) {
        angle = 360 + angle;
    }
    
    return (float)std::sin(angle * (3.1415826 / 180.0f));
}