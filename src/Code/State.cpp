#include "../Header/State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys): window(window), supportedKeys(supportedKeys)
{
    this->quit = false;

}

State::~State()
{
}

void State::updateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["CLOSE"])))
    {
        this->quit = true;
    }
}
