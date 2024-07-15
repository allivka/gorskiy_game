
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Object.hpp"
#include "Info.hpp"
#include <SFML/Graphics.hpp>

class Player : public Object {
public:

    sf::Clock fireDelay;

    Player();

    Player(const sf::Texture& texture);

    void move(double x);

};

#endif