//
//  MainMenu.h
//  Pang
//
//  Created by James Tease on 14/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class MainMenu {
public:
    enum MenuResult {
        NOTHING,
        EXIT,
        PLAY
    };
    
    struct MenuItem {
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };
    
    MenuResult show(sf::RenderWindow& window);
    
private:
    MenuResult getMenuResponse(sf::RenderWindow& window);
    MenuResult handleClick(int x, int y);
    std::list<MenuItem> _menuItems;
};