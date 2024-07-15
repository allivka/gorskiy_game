
#ifndef GAME_HPP
#define GAME_HPP

#include "Info.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <algorithm>

class Game {
private:
    const sf::Texture* tBullet;
public:

    Player player;
    std::vector<Enemy*> enemies;
    std::vector<Bullet*> bullets;

    bool isGameOver = false;
    bool isVictory = false;

    size_t score = 0;
    std::string text = "SCORE: ";
    sf::Text textScore;
    sf::Sound explosionSound, loseSound;

    sf::Music music;

    Game(const sf::Texture& tPlayer, const sf::Texture& tEnemy, const sf::Texture& p_tBullet, const sf::Font& p_font);

    ~Game();

    void controlTick();

    void stateTick();

};

#endif