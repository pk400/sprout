#include "../include/Game.hpp"
#include "../include/PlayState.hpp"

PlayState::PlayState() {
    player = new Player();
    loadText();
}

void PlayState::loadText() {
    int text_height;

    debug_state = new sf::Text("State: Play State", font, 12);
    debug_state->setPosition(WINDOW_WIDTH - DEBUG_TEXT_OFFSET, 0);
    text_height = debug_state->getLocalBounds().height;

    debug_input = new sf::Text("Input: ", font, 12);
    debug_input->setPosition(WINDOW_WIDTH - DEBUG_TEXT_OFFSET, text_height * 1);

    player->loadText(font, text_height * 2);
}

int PlayState::processInput(sf::Event event) {
    std::string debug_str = "Input: ";

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        debug_str += 'A';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player->move(3);
        debug_str += 'D';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        debug_str += "Spacebar";
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return 2;
    }

    debug_input->setString(debug_str);

    return 0;
}

void PlayState::update() {
}

void PlayState::render(sf::RenderWindow& win) {
    win.draw(*debug_state);
    win.draw(*debug_input);
    player->draw(win);
}
