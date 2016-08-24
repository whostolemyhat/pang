//
//  GameObject.h
//  Pang
//
//  Created by James Tease on 15/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class GameObject {
public:
    GameObject();
    virtual ~GameObject();
    
    virtual void load(std::string filename);
    virtual void draw(sf::RenderWindow& window);
    virtual void update(float elapsedTime);
    virtual void setPosition(float x, float y);
    virtual sf::Vector2f getPosition() const;
    virtual bool isLoaded() const;
    virtual float getWidth() const;
    virtual float getHeight() const;
    virtual sf::Rect<float> getBoundingRect() const;

protected:
    sf::Sprite& getSprite();
    
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    std::string _filename;
    bool _isLoaded;
};
