//
//  SplashScreen.cpp
//  Pang
//
//  Created by James Tease on 14/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#include <stdio.h>
#include "SplashScreen.h"
#include "ResourcePath.hpp"

void SplashScreen::show(sf::RenderWindow& window) {
    sf::Texture texture;
    if(texture.loadFromFile(resourcePath() + "splashscreen.png") != true) {
        return;
    }
    
    sf::Sprite sprite(texture);
    window.draw(sprite);
    window.display();
    
    sf::Event event;
    while(true) {
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::EventType::KeyPressed ||
               event.type == sf::Event::EventType::MouseButtonPressed ||
               event.type == sf::Event::EventType::Closed) {
                return;
            }
        }
    }
}