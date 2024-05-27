#include "Ball.h"

Ball::Ball() {
	srand(time(NULL));
	shape.setRadius(r);
	int vect = rand() % 2;
	float vel = (rand() % 6)+5;
	if (vect == 0) {
		velocity.x = -vel/10;
		velocity.y = -vel/10;
	}
	else {
		velocity.x = vel / 10;
		velocity.y = vel / 10;
	}
	shape.setFillColor(sf::Color::White);
	restart();
}
Ball::~Ball() {

}
bool Ball::collisions(sf::FloatRect obj) {
	sf::FloatRect ballBounds = shape.getGlobalBounds();
	if (ballBounds.intersects(obj)) {
		return true;
	}
	if (ballBounds.top < obj.top || ballBounds.top + ballBounds.height > obj.top + obj.height) {
		return false;
	}
	return false;
}
void Ball::move(float& time) {
	sf::Vector2f pos;
	
	shape.move(velocity.x*time, velocity.y*time);
	pos = shape.getPosition();
	if (pos.y < 0) {
		shape.setPosition(pos.x,0);
		velocity.y *= -1.0;
	}
	else if (pos.y > 680) {
		shape.setPosition(pos.x, 680);
		velocity.y *= -1.0;
	}
}
void Ball::draw(sf::RenderWindow& window) {
	window.draw(shape);
}
void Ball::restart() {
	float x = 600.f;
	float y = 10.f;
	shape.setPosition(x,y);
	int vect = rand() % 2;
	float vel = (rand() % 6) + 5;
	if (vect == 0) {
		velocity.x = -vel / 10;
		velocity.y = -vel / 10;
	}
	else {
		velocity.x = vel / 10;
		velocity.y = vel / 10;
	}
}
void Ball::changeVelocityAfterCollision() {
	velocity.x *= -1; 

	if (velocity.x < 0)
		velocity.x -= 0.25;
	else
		velocity.x += 0.25;

	if (velocity.y < 0)
		velocity.y -= 0.25;
	else
		velocity.y += 0.25;
}

sf::Vector2f Ball::getPos() {
	return shape.getPosition();
}