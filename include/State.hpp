#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

const sf::Time FPS = sf::seconds(1.f/60.f);

enum DebugEnum { DEFAULT, MENU, PLAY };
const DebugEnum DEBUG_MODE      = DEFAULT;
const int WINDOW_WIDTH          = 800;
const int WINDOW_HEIGHT         = 480;
const int DEBUG_TEXT_OFFSET     = 100;
const int DEBUG_TEXT_SIZE       = 12;
const int DEBUG_TEXT_PADDING    = 12;
const std::string GAME_TITLE    = "Platformer";
const std::string DEBUG_STR     = "State: ";

class State {
protected:
    sf::Font font;
    State() {
        font.loadFromFile("./assets/arial.ttf");
    }
public:
    virtual int processInput(sf::Event event, sf::Vector2i mouse, float dt) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif // STATE_HPP
