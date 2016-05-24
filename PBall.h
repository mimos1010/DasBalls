#pragma once
#include "Precompiled.h"

class PBall: public sf::CircleShape
{
public:
	PBall(int circlesize, int circlemass, float x, float y, sf::Vector2f velocityx);

	int mass;

	sf::Vector2f center;    //the center of the circle
	sf::Vector2f speed;		//velocity without direction
	sf::Vector2f oldvelocity;
	sf::Vector2f velocity;  //speed with direction

	void updatePos();
	bool isColliding(PBall B);
	void resolveCollision(PBall B);



	~PBall();
};

