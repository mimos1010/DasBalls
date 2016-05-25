#pragma once
#include "Precompiled.h"
#include "PBall.h"

	int circle_size = 30;
	int circle_mass = 50;
	sf::Color color(255, 1, 1, 255);
	void onClickSpawn(sf::RenderWindow &window, sf::Event eventx, int var1, int var2, std::vector <PBall> &ballz);

int main()
{
	std::vector <PBall> balls;

	instructionText();
	sf::RenderWindow window(sf::VideoMode(800, 640), "Das Engine");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			winClose(window, event);
			handleVars(window, event, circle_size, circle_mass);
			onClickSpawn(window, event, circle_size, circle_mass, balls);
		}
		
		//Updates go here
		for (int i = 0; i < balls.size(); i++)
		{
			balls[i].updatePos();
			balls[i].resolveEdges();
		}
		for (int i = 0; i < balls.size(); i++)
		{
			for (int j = i + 1; j < balls.size(); j++)
			{
				bool collision = balls[i].isColliding(balls[j]);

				if (collision)
				{
					balls[i].resolveCollision(balls[j]);
					balls[j].resolveCollision(balls[i]);
				}
			}
		}


		window.clear();
		//Stuff drawn here
		for (int i = 0; i < balls.size(); i++)
		{
			window.draw(balls[i]);
		}
		window.display();
		
	}
}

void instructionText()
{
	std::cout << "Q and W to change the size of the ball \n";
	std::cout << "A and S to change the mass of the ball \n";
	std::cout << "R to randomize the color of the ball \n";
}

void winClose(sf::RenderWindow &window, sf::Event eventx) {
	if (eventx.type == sf::Event::Closed)
	{
		window.close();
	}
}
void handleVars(sf::RenderWindow &window, sf::Event eventx, int &var1, int &var2) {
	if (eventx.type == sf::Event::KeyPressed)
	{
		switch (eventx.key.code)
		{
		case sf::Keyboard::Q:
			if (var1 > 10)
			{
				var1--;
				std::cout << var1 << "\n";
			}
			break;
		case sf::Keyboard::W:
			if (var1 < 99)
			{
				var1++;
				std::cout << var1 << "\n";
			}
			break;
		case sf::Keyboard::A:
			if (var2 > 10)
			{
				var2--;
				std::cout << var2 << "\n";
			}
			break;
		case sf::Keyboard::S:
			if (var2 < 99)
			{
				var2++;
				std::cout << var2 << "\n";
			}
			break;
		}
	}
}
void onClickSpawn(sf::RenderWindow &window, sf::Event eventx, int var1, int var2, std::vector <PBall> &ballz) {

	sf::Vector2f velocity(-.1, .1);
	PBall ball_template(var1, var2, 0, 0, velocity);
	

	if (eventx.type == sf::Event::MouseButtonPressed)
	{

	}
	if (eventx.type == sf::Event::MouseButtonReleased)
	{
		ball_template.setPosition(sf::Mouse::getPosition(window).x - ball_template.getRadius(), sf::Mouse::getPosition(window).y - ball_template.getRadius());
		ballz.push_back(ball_template);
	}
}
