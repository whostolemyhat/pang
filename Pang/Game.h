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

#include "PlayerBat.h"

class Game {
public:
    static void start();
    
private:
    static bool isExiting();
    static void gameLoop();
    
    static void showMenu();
    static void showSplashScreen();
    
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
    static PlayerBat _player;
};
