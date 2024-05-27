#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
private:
	sf::CircleShape shape;
	sf::Vector2f velocity;

	double r=20.f;
public:
	Ball();
	~Ball();
	void move(float& time);
	void draw(sf::RenderWindow& window);
	bool collisions(sf::FloatRect obj);
	void restart();
	void changeVelocityAfterCollision();
	sf::Vector2f getPos();
};