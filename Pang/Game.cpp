//
//  Game.cpp
//  Pang
//
//  Created by James Tease on 14/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "ResourcePath.hpp"

#include <iostream>

void Game::start() {
    if(_gameState != UNINITIALISED) {
        return;
    }
    
    _mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pang!");
    
    PlayerBat *player = new PlayerBat();
//    std::shared_ptr<PlayerBat> player (new PlayerBat() );
    player->load(resourcePath() + "bat.png");
    player->setPosition((SCREEN_WIDTH/2) - 45, 700);
    _manager.add("player1", player);
    
    Ball *ball = new Ball();
    ball->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    _manager.add("ball", ball);
    
    _gameState = Game::SHOWING_SPLASH;
    
    while(!isExiting()) {
        gameLoop();
    }
    
    _mainWindow.close();
}

sf::RenderWindow& Game::getWindow() {
    return _mainWindow;
}

const sf::Event& Game::getInput() {
    sf::Event event;
    _mainWindow.pollEvent(event);
    return event;
}

const GameObjectManager& Game::getManager() {
    return Game::_manager;
}

bool Game::isExiting() {
    if(_gameState == Game::EXITING) {
        return true;
    } else {
        return false;
    }
}

void Game::showSplashScreen() {
    SplashScreen splashScreen;
    splashScreen.show(_mainWindow);
    _gameState = Game::SHOWING_MENU;
}

void Game::showMenu() {
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.show(_mainWindow);
    switch(result) {
        case MainMenu::EXIT: {
            _gameState = Game::EXITING;
            break;
        }
            
        case MainMenu::PLAY: {
            _gameState = Game::PLAYING;
            break;
        }
    }
}

void Game::gameLoop() {
    sf::Event currentEvent;
    _mainWindow.pollEvent(currentEvent);
    
    switch(_gameState) {
        case Game::UNINITIALISED:
        case Game::PAUSED: {
            std::cout << "Uninitialised or paused!" << std:: endl;
            break;
        }
            
        case Game::SHOWING_SPLASH: {
            showSplashScreen();
            break;
        }

        case Game::SHOWING_MENU: {
            showMenu();
            break;
        }

        case Game::PLAYING: {
            std::cout << currentEvent.type << std::endl;
            
            _mainWindow.clear(sf::Color(239, 143, 80));
                
            _manager.updateAll();
            _manager.drawAll(_mainWindow);
            _mainWindow.display();
                
            if(currentEvent.type == sf::Event::Closed) {
                std::cout << "Exiting from playing" << std::endl;
                _gameState = Game::EXITING;
            }
                    
            if(currentEvent.type == sf::Event::KeyPressed) {
                if(currentEvent.key.code == sf::Keyboard::Key::Escape) {
                    showMenu();
                }
            }
            
            break;
        }
    }
}


Game::GameState Game::_gameState = UNINITIALISED;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_manager;
