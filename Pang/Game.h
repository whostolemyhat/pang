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
#include "GameObjectManager.h"
#include "PlayerBat.h"
#include "Ball.h"

class Game {
public:
    static void start();
    static sf::RenderWindow& getWindow();
    const static sf::Event& getInput();
    const static GameObjectManager& getManager();
    const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;
    
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
    static GameObjectManager _manager;
};
