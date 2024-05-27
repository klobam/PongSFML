#pragma once
#include <SFML/Graphics.hpp>
class PLayers
{
private:
	sf::RectangleShape player1;
	sf::RectangleShape player2;
	sf::Vector2f velocityPlayer1;
	sf::Vector2f velocityPlayer2;
	sf::Vector2f size;
public:
	PLayers();
	~PLayers();
	void movePlatform(float& timePlayer1, float& timePLayer2, sf::Event event);
	void move();
	void draw(sf::RenderWindow& window);
	void chekingOutOfBounds();
	sf::FloatRect getGlobalBoundPlayer1();
	sf::FloatRect getGlobalBoundPlayer2();
	void restart();
};

