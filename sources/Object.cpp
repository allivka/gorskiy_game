
#include "../headers/Object.hpp"

Object::Object() {
    pos.x = 0;
    pos.y = 0;
}

Object::Object(sf::Texture& texture) {
    sprite.setTexture(texture);
    Object();
}

void Object::setPos(const sf::Vector2f& point) {
    pos = point;
    sprite.setPosition(pos);
}

void Object::setPos(double x, double y) {
    pos.x = x;
    pos.y = y;
    sprite.setPosition(pos);
}