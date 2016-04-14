//
//  MainMenu.cpp
//  Pang
//
//  Created by James Tease on 14/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#include <stdio.h>
#include "MainMenu.h"
#include "ResourcePath.hpp"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow& window) {
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "mainmenu.png");
    sf::Sprite sprite(texture);
    
    MenuItem playButton;
    playButton.rect.top = 145;
    playButton.rect.height = 255;
    playButton.rect.left = 0;
    playButton.rect.width = 1023;
    playButton.action = PLAY;
    
    MenuItem exitButton;
    exitButton.rect.top = 400;
    exitButton.rect.height = 180;
    exitButton.rect.left = 0;
    exitButton.rect.width = 1023;
    exitButton.action = EXIT;
    
    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);
    
    window.draw(sprite);
    window.display();
    
    return getMenuResponse(window);
}

MainMenu::MenuResult MainMenu::handleClick(int x, int y) {
    std::list<MenuItem>::iterator it;
    for(it = _menuItems.begin(); it != _menuItems.end(); it++) {
        sf::Rect<int> menuItemRect = (*it).rect;
        if(menuItemRect.top + menuItemRect.height > y &&
           menuItemRect.top < y &&
           menuItemRect.left < x &&
           menuItemRect.left + menuItemRect.width > x) {
            return (*it).action;
        }
    }
    
    return NOTHING;
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow& window) {
    sf::Event menuEvent;
    while(true) {
        while(window.pollEvent(menuEvent)) {
            if(menuEvent.type == sf::Event::MouseButtonPressed) {
                return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            
            if(menuEvent.type == sf::Event::Closed) {
                return EXIT;
            }
        }
    }
}