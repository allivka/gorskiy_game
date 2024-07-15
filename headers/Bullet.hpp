

#ifndef BULLET_HPP
#define BULlET_HPP

#include "Object.hpp"
#include "Info.hpp"
#include <SFML/Graphics.hpp>

class Bullet: public Object {
public:
    Bullet();

    Bullet(const sf::Texture& texture);

    void moveUp(double y);
};

#endif