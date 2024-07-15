
#include "../headers/Game.hpp"

Game::Game(const sf::Texture& tPlayer, const sf::Texture& tEnemy, const sf::Texture& p_tBullet, const sf::Font& p_font) {
    player.sprite.setTexture(tPlayer);
    player.setPos(sf::Vector2f(info::WINX / 2.0, info::WINY - info::BORDER - 50));

    tBullet = &p_tBullet;

    textScore.setFont(p_font);
    textScore.setString(text + std::to_string(score));
    textScore.setPosition(info::BORDER, info::BORDER / 2.0);
    textScore.setColor(sf::Color(191, 191, 31));
    textScore.setCharacterSize(50);

    //creating enemies
    for(int y = 50; y < 50 + 150 * 3; y += 150) {
        for(int x = 50; x < 50 + 180 * 9; x += 180) {
            Enemy* temp = new Enemy(tEnemy);

            temp->setPos(x, y);

            enemies.push_back(temp);
        }
    }
}


Game::~Game() {
    for(auto& el : enemies) {
        delete el;
    }
    for(auto& el : bullets) {
        delete el;
    }

}


void Game::controlTick() {
    
    //controlling character behavior

    if(isGameOver || isVictory) return;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
        player.move(info::PLAYERSPEED);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
        player.move(-info::PLAYERSPEED);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space) && player.fireDelay.getElapsedTime().asSeconds() >= info::FIREDELAY) {
        Bullet* temp = new Bullet(*tBullet);
        temp->setPos(player.pos.x, player.pos.y);
        bullets.push_back(temp);

        player.fireDelay.restart();
    }
}


void Game::stateTick() {
        
        if(isVictory || isGameOver) {
            explosionSound.stop();
            music.stop();
        }

        //updating state of every object on the screen

        if(isGameOver || isVictory) return;

        for(auto& el : bullets) {
            el->moveUp(info::BULLETSPEED);

        }

        //handling interactions of bullets and enemies

        std::vector<int> trashBullets;
        std::vector<int> trashEnemies;

        for(int i = 0; i < bullets.size(); i++) {
            for(int j = 0; j < enemies.size(); j++) {
                if(bullets[i]->sprite.getGlobalBounds().intersects(enemies[j]->sprite.getGlobalBounds())) {
                    delete enemies[j];
                    delete bullets[i];
                    
                    trashEnemies.push_back(j);
                    trashBullets.push_back(i);

                    score++;

                    explosionSound.play();

                    break;
                }
            }
        }

        for(auto& idx : trashBullets) {
            bullets.erase(bullets.begin() + idx);
        }

        for(auto& idx : trashEnemies) {
            enemies.erase(enemies.begin() + idx);
        }

        //handling victory

        if(enemies.empty()) {
            isVictory = true;
            victorySound.play();
            return;
        }


        //handling game over
        for(auto& el : enemies) {
            el->moveDown(info::ENEMYSPEED);
            if((el->pos.y >= info::WINY - info::BORDER || 
            player.sprite.getGlobalBounds().intersects(el->sprite.getGlobalBounds())) && el->pos.x) {
                isGameOver = true;
                loseSound.play();
                break;
            }
        }

        

    }