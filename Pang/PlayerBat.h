//
//  PlayerBat.h
//  Pang
//
//  Created by James Tease on 15/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#pragma once
#include "GameObject.h"

class PlayerBat : public GameObject {
public:
    PlayerBat();
    ~PlayerBat();
    
    void update(float elapsedTime);
    void draw(sf::RenderWindow& window);
    float getVelocity() const;
    
private:
    float _velocity;
    float _maxVelocity;
};
