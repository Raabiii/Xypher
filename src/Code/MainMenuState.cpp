#include "../Header/MainMenuState.h"

void MainMenuState::initFonts()
{
    if (!this->font.loadFromFile("../Resources/Fonts/Veneer_Two.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initKeybinds()
{
    std::ifstream ifs("../src/Config/gamestate_keybinds.ini");

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

void MainMenuState::initBackground()
{
    //this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png");
    //this->background.setTexture(&this->backgroundTexture);
    this->background.setSize(sf::Vector2f(
        static_cast<float>(this->window->getSize().x),
        static_cast<float>(this->window->getSize().y)
    ));
    this->background.setFillColor(sf::Color::Magenta);
}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
        &this->font, "New Game",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

    /*this->buttons["SETTINGS"] = new Button(110, 200, 150, 50,
        &this->font, "Settings",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

    this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50,
        &this->font, "Quit",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));*/
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    this->initBackground();


}

MainMenuState::~MainMenuState()
{
    for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
    {
        delete it->second;
    }
}

void MainMenuState::updateInput(const float& dt)
{
    this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

}

void MainMenuState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;

    target->draw(this->background);

}

void MainMenuState::endState()
{
    std::cout << "Ending Main Menu State!" << std::endl;
}

