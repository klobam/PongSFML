#include "PLayers.h"

PLayers::PLayers() {
	size.x = 10;
	size.y = 100;

	player1.setSize(size);
	player2.setSize(size);
	player1.setPosition(100, 310);
	player2.setPosition(1170, 310); 

	velocityPlayer1.x = 0;
	velocityPlayer1.y = 0;
	velocityPlayer2.x = 0;
	velocityPlayer2.y = 0;
}
PLayers::~PLayers() {
	
}
void PLayers::movePlatform(float& timePlayer1, float& timePlayer2, sf::Event event) {
	switch (event.type) {
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::W)velocityPlayer1.y = -0.5 * timePlayer1;
		if (event.key.code == sf::Keyboard::S)velocityPlayer1.y = 0.5 * timePlayer1;
		if (event.key.code == sf::Keyboard::Up)velocityPlayer2.y = -0.5 * timePlayer2;
		if (event.key.code == sf::Keyboard::Down)velocityPlayer2.y = 0.5 * timePlayer2;
		break;
	case sf::Event::KeyReleased:
		if (event.key.code == sf::Keyboard::W)velocityPlayer1.y = 0;
		if (event.key.code == sf::Keyboard::S)velocityPlayer1.y = 0;
		if (event.key.code == sf::Keyboard::Up)velocityPlayer2.y = 0;
		if (event.key.code == sf::Keyboard::Down)velocityPlayer2.y = 0;
		break;
	}
}
void PLayers::move() {
	player1.move(velocityPlayer1);
	player2.move(velocityPlayer2);

}
void PLayers::chekingOutOfBounds() {
	sf::Vector2f player1Pos = player1.getPosition();
	sf::Vector2f player2Pos = player2.getPosition();
	if (player1Pos.y < 0)player1.setPosition(100, 0);
	if (player1Pos.y > 620)player1.setPosition(100, 620);
	if (player2Pos.y < 0)player2.setPosition(1170, 0);
	if (player2Pos.y > 620)player2.setPosition(1170, 620);
}
void PLayers::draw(sf::RenderWindow& window) {
	window.draw(player1);
	window.draw(player2);
}
sf::FloatRect PLayers::getGlobalBoundPlayer1() {
	return player1.getGlobalBounds();
}
sf::FloatRect PLayers::getGlobalBoundPlayer2() {
	return player2.getGlobalBounds();
}
void PLayers::restart() {
	// set on middle position on screen
	player1.setPosition(100, 310);
	player2.setPosition(1170, 310);
}