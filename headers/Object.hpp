

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Info.hpp"
#include <SFML/Graphics.hpp>

class Object {
public:
    sf::Vector2f pos;
    sf::Vector2f size;
    sf::Sprite sprite;

    Object();

    Object(sf::Texture& texture);

    void setPos(const sf::Vector2f& point);

    void setPos(double x, double y);
};

#endif