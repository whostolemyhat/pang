//
//  Game.hpp
//  Pang
//
//  Created by James Tease on 14/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
public:
    static void start();
    
private:
    static bool isExiting();
    static void gameLoop();
    
    enum GameState {
        UNINITIALISED,
        SHOWING_SPLASH,
        PAUSED,
        PLAYING,
        SHOWING_MENU,
        EXITING
    };
    
    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
};
