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

void Game::start() {
    if(_gameState != UNINITIALISED) {
        return;
    }
    
    _mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
    _gameState = Game::SHOWING_SPLASH;
    
    while(!isExiting()) {
        gameLoop();
    }
    
    _mainWindow.close();
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
    _gameState = Game::SHOWING_SPLASH;
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
    while(_mainWindow.pollEvent(currentEvent)) {
        switch(_gameState) {
            case Game::SHOWING_SPLASH: {
                showMenu();
                break;
            }
                
            case Game::SHOWING_MENU: {
                showMenu();
                break;
            }
                
            case Game::PLAYING: {
                sf::Event currentEvent;
                
                while(_mainWindow.pollEvent(currentEvent)) {
                    _mainWindow.clear(sf::Color(125, 0, 0));
                    _mainWindow.display();
                    
                    if(currentEvent.type == sf::Event::Closed) {
                        _gameState = Game::EXITING;
                    }
                    
                    if(currentEvent.type == sf::Event::KeyPressed) {
                        if(currentEvent.key.code == sf::Keyboard::Key::Escape) {
                            showMenu();
                        }
                    }
                }
                
                break;
            }
        }
    }
}


Game::GameState Game::_gameState = UNINITIALISED;
sf::RenderWindow Game::_mainWindow;
