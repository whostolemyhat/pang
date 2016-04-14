//
//  Game.cpp
//  Pang
//
//  Created by James Tease on 14/04/2016.
//  Copyright © 2016 Don't Expect Anything Sensible. All rights reserved.
//

#include "Game.h"

void Game::start() {
    if(_gameState != UNINITIALISED) {
        return;
    }
    
    _mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
    _gameState = Game::PLAYING;
    
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

void Game::gameLoop() {
    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent)) {
        switch(_gameState) {
            case Game::PLAYING: {
                _mainWindow.clear(sf::Color(125, 0, 0));
                _mainWindow.display();
                
                if(currentEvent.type == sf::Event::Closed) {
                    _gameState = Game::EXITING;
                }
                
                break;
            }
        }
    }
}


Game::GameState Game::_gameState = UNINITIALISED;
sf::RenderWindow Game::_mainWindow;
