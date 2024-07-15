
#include "../headers/Game.hpp"
#include <iostream>

int main() {

    sf::RenderWindow app(sf::VideoMode(info::WINX, info::WINY), "Gorskiy_game");

    app.setFramerateLimit(60);

    sf::Texture tBackGround, tPlayer, tEnemy, tGameOver, tBullet, tVictory;

    tBackGround.loadFromFile("images/background.jpg");
    tPlayer.loadFromFile("images/player.png");
    tEnemy.loadFromFile("images/enemy.png");
    tBullet.loadFromFile("images/bullet.png");
    tGameOver.loadFromFile("images/gameover.jpg");
    tVictory.loadFromFile("images/victory.png");

    sf::Font font;
    font.loadFromFile("font/font.ttf");

    sf::SoundBuffer explosionBuff, loseBuff;
    explosionBuff.loadFromFile("audio/explosion.wav");
    loseBuff.loadFromFile("audio/lose.wav");


    sf::Sprite backGround(tBackGround), gameOver(tGameOver), victory(tVictory);

    while(1) {

        Game game(tPlayer, tEnemy, tBullet, font);
        game.explosionSound.setBuffer(explosionBuff);
        game.loseSound.setBuffer(loseBuff);
        game.music.openFromFile("audio/music.wav");
        game.music.play();
        game.music.setVolume(45);

        while(app.isOpen()) {
            sf::Event event;
            
            while(app.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        app.close();
                        return 0;
                        break;
                        
                }
            }


            game.controlTick();
            game.stateTick();
            

            if((game.isGameOver || game.isVictory) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::R)) {
                break;
            }


            if(game.isGameOver) {
                app.draw(gameOver);
            } else if(game.isVictory) {
                app.draw(victory);
            } else {
                app.draw(backGround);
                app.draw(game.player.sprite);

                for(auto& el : game.enemies) {
                    if(el == nullptr) continue;
                    app.draw(el->sprite);

                }

                for(auto& el : game.bullets) {
                    if(el == nullptr) continue;
                    app.draw(el->sprite);
                }
            }

            game.textScore.setString(game.text + std::to_string(game.score));
            app.draw(game.textScore);

            app.display();
        }
    }
}
