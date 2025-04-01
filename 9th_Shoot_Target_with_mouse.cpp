#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1000.f, 800.f), "Shoot Target with Mouse");
	window.setFramerateLimit(50);


	// Creating a target
	CircleShape hoop(50.f);
	int dir = 0;							//var to move target
	hoop.setPosition(0.f, 10.f);
	hoop.setFillColor(Color::Cyan);
	hoop.setOutlineThickness(5.f);
	hoop.setOutlineColor(Color::Blue);

	
	// Creating a ball
	CircleShape ball(20.f);
	bool isShot = false;
	ball.setPosition(0.f, window.getSize().y-ball.getRadius()*3);
	ball.setFillColor(Color::Red);
	

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		// making boundary for hoop and change dir
		if(hoop.getPosition().x<0)
			dir = 1;
		else if (2*hoop.getRadius() + hoop.getPosition().x > window.getSize().x)
			dir = 0;

		// moving hoop according dir
		if (dir)
			hoop.move(5.f, 0.f);
		else
			hoop.move(-5.f, 0.f);

		//ball.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);    // fun

		/* shoot ball */
		if (Keyboard::isKeyPressed(Keyboard::Space))
			isShot = true;
		if (!isShot)
			ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);    // moving ball with mouse
		else
			ball.move(0.f, -5.f);

		//	Coilision  and reset position of ball
		if (ball.getPosition().y < 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds())) {
			ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
			isShot = false;
		}



		window.clear(Color::White);
		window.draw(hoop);
		window.draw(ball);
		window.display();
		
	}
	return 0;
}