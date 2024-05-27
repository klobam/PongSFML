#include "Game.h"
Game::Game():window(sf::VideoMode(1280, 720),"pong") {
    sf::Image icon;
    icon.loadFromFile("Image/icon.jpg");
    window.setIcon(85, 69, icon.getPixelsPtr());
}
Game::~Game() {

}
void Game::run() {
    sf::Font fontStart;
    sf::Font fontScore;
    sf::Font fontWinText;
    fontWinText.loadFromFile("Fonts/radiance-lightitalic.otf");
    fontStart.loadFromFile("Fonts/bangers-regular.ttf");
    fontScore.loadFromFile("Fonts/grenze-bold.ttf");
    sf::Clock clock;
    sf::Text score;
    sf::Text winText;
    winText.setPosition(300, 320);
    winText.setFont(fontWinText);
    winText.setCharacterSize(40);
    score.setPosition(600, 20);
    score.setFont(fontScore);
    score.setCharacterSize(15);
    float time, timePlayer1, timePlayer2;
    while (window.isOpen())
    {   
            sf::Event event;
            time = clock.getElapsedTime().asMicroseconds();
            timePlayer1 = clock.getElapsedTime().asMicroseconds();
            timePlayer2 = clock.getElapsedTime().asMicroseconds();
            time /= 6000;
            timePlayer1 /= 2000;
            timePlayer2 /= 2000;
            clock.restart();
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed && !isGameStarted)
                    isGameStarted = true;
                players.movePlatform(timePlayer1, timePlayer2, event);
            }
            window.clear();
            if (isGameStarted) {
                Shape.move(time);
                players.move();
                if (Shape.collisions(players.getGlobalBoundPlayer1())) {
                    Shape.changeVelocityAfterCollision();
                }
                if (Shape.collisions(players.getGlobalBoundPlayer2())) {
                    Shape.changeVelocityAfterCollision();
                }
                window.clear();
                Shape.draw(window);
                players.draw(window);
                players.chekingOutOfBounds();
                sf::Vector2f posShape = Shape.getPos();
                if (posShape.x < 0) {
                    scorePlayer2++;
                    restart();
                }
                else if (posShape.x > 1240) {
                    scorePlayer1++;
                    restart();
                }
                score.setString(std::to_string(scorePlayer1) + ":" + std::to_string(scorePlayer2));
                if (scorePlayer1 >= 2) {
                    window.clear();
                    winText.setString("Player 1 wins \n Thanks for game=)");
                    window.draw(winText);
                }
                else if (scorePlayer2 >= 2) {
                    window.clear();
                    winText.setString("Player 2 wins \n Thanks for game=)");
                    window.draw(winText);

                }
                window.draw(score);
                window.display();
            }
            else {
                if (scorePlayer1 != 2 || scorePlayer2 != 2) {
                    sf::Text startText("Pong is a two-dimensional sports game that simulates table tennis\nControl for 1 player:W-up your platform.S- down ypur platform\nControl for 2 player:Up -up your platform.Down -down ypur platform\nPress any key to start", fontStart, 32);
                    startText.setPosition(300, 300);
                    if (scorePlayer1 > 0 || scorePlayer2 > 0) {
                        startText.setString("Press any key to continue");
                        startText.setPosition(500, 300);
                    }

                    window.draw(startText);
                    window.display();
                }
            }
        }   
}
void Game::restart() {
    Shape.restart();
    players.restart();
    isGameStarted = false;
}