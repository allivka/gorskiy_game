
#include "../headers/Player.hpp"

Player::Player() {
    size.x = 100;
    size.y = 129;
}

Player::Player(const sf::Texture& texture) {
    sprite.setTexture(texture);
    Player();
}

void Player::move(double x) {
    x += pos.x;
    x = std::min(x, info::WINX - 100);
    x = std::max(x, size.x / 2.0);
    setPos(sf::Vector2f(x, pos.y));

}