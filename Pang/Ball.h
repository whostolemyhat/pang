//
//  Ball.h
//  Pang
//
//  Created by James Tease on 02/05/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#pragma once
#include "GameObject.h"

class Ball : public GameObject {
public:
    Ball();
    virtual ~Ball();
    void update(float);

private:
    float _velocity;
    float _angle;
    float _elapsedTime;
    
    float linearVelocityX(float angle);
    float linearVelocityY(float angle);
};