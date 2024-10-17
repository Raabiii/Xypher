#include "../Header/GameState.h"

void GameState::initKeybinds()
{
    std::ifstream ifs("src/Config/gamestate_keybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    this->initKeybinds();

    // this->player = Entity();
    // this->player.setPosition(50.f, 50.f);
    // this->player.setScale(0.5f, 0.5f);
}

GameState::~GameState()
{
}

void GameState::updateInput(const float& dt)
{
    this->checkForQuit();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_LEFT"])))
        this->player.move(dt, -1.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_RIGHT"])))
        this->player.move(dt, 1.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_UP"])))
        this->player.move(dt, 0.f, -1.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_DOWN"])))
        this->player.move(dt, 0.f, 1.f);
}

void GameState::endState()
{
    std::cout << "Ending Game State!" << std::endl;
}

void GameState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);


    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;
    this->player.render(target);
}