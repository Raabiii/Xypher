#ifndef GAME_H
#define GAME_H

#include "../States/MainMenuState.h"

class Game
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::Event sfevent;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings windowSettings;
    bool fullscreen;

    sf::Clock dtClock;
    float dt;

    std::stack <State*> states;

    std::map <std::string, int> supportedKeys;

    //Initializers
    void initVariables();
    void initWindow();
    void initKeys();    
    void initStates();
public:
    //Constructors/Destructors
    Game();
    virtual ~Game();

    //Functions

    // Regular
    void endApplication();

    // Update
    void updateDt();
    void updateSFMLEvents();
    void update();

    // Render
    void render();
    void run();
};

#endif // GAME_H