
#include "../headers/Bullet.hpp"


Bullet::Bullet() {
    size.x = 100;
    size.y = 34;
}

Bullet::Bullet(const sf::Texture& texture) {
    Bullet();
    sprite.setTexture(texture);
    sprite.setOrigin(size.x / 2.0, size.y);
}

void Bullet::moveUp(double y) {
    pos.y += -y;
    sprite.setPosition(pos);
}