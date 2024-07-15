
#include "../headers/Enemy.hpp"

Enemy::Enemy() {
    size.x = 100;
    size.y = 100;
}


Enemy::Enemy(const sf::Texture& texture) {
    sprite.setTexture(texture);
    Enemy();
}

void Enemy::moveDown(double y) {
    pos.y += y;
    sprite.setPosition(pos);
}