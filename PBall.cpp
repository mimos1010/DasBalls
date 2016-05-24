#include "PBall.h"



PBall::PBall(int circlesize, int circlemass, float x, float y, sf::Vector2f velocityx)
{
	setRadius(circlesize);
	mass = circlemass;
	setPosition(x, y);
	sf::Vector2f centerx(getPosition().x + getRadius(), getPosition().x + getRadius());
	center = centerx;
	velocity = velocityx;
	
}


PBall::~PBall()
{
}

void PBall::updatePos() {
	setPosition(getPosition().x + velocity.x, getPosition().y + velocity.y); //actual position update
	sf::Vector2f centerx(getPosition().x + getRadius(), getPosition().y + getRadius()); //update center
	
	center = centerx;
	oldvelocity = velocity;
}
bool PBall::isColliding(PBall B) {
	float distance = sqrt(((center.x - B.center.x) * (center.x - B.center.x)) + ((center.y - B.center.y) * (center.y - B.center.y)));
	if (distance <= (getRadius() + B.getRadius()))
	{
		return true;
	}
	return false;
}

void PBall::resolveCollision(PBall B) {
	oldvelocity = velocity;

	float Velx = (((mass - B.mass) / (mass + B.mass)) * velocity.x) + (((2 * B.mass) / (mass + B.mass)) * B.oldvelocity.x);
	float Vely = (((mass - B.mass) / (mass + B.mass)) * velocity.y) + (((2 * B.mass) / (mass + B.mass)) * B.oldvelocity.y);
	
	sf::Vector2f VelocityO(Velx,Vely);
	setPosition(getPosition().x + Velx, getPosition().y + Vely);
	velocity = VelocityO;

}