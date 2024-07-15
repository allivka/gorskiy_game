

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Object.hpp"
#include "Info.hpp"
#include <SFML/Graphics.hpp>

class Enemy : public Object {
public:
    Enemy();

    Enemy(const sf::Texture& texture);

    void moveDown(double y);

};


#endif