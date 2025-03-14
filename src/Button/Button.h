#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
    button_states buttonState;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height,
        sf::Font* font, std::string text,
        sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
    ~Button();

    // Accessors
    const bool isPressed() const;

    // Functions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);

};

#endif // BUTTON_H