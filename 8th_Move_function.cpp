#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

/* Fun declaration */
void Update(RenderWindow& window,RectangleShape & square);
void Draw(RenderWindow& window, RectangleShape& square);

int main() {
	//int keyTime = 8; // contorl key presses

	RenderWindow window(VideoMode(1000.f, 800.f), "Move using Function");
	window.setFramerateLimit(50);

	RectangleShape square(Vector2f(100.f, 100.f));
	square.setFillColor(Color::Red);
	// pos of center of window
	square.setPosition(window.getSize().x/2, window.getSize().y/2);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
				
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		/* Call Function */
		Update(window,square);
		
		Draw(window,square);
	}
	return 0;
}

/* Function Body */
void Update(RenderWindow& window, RectangleShape& square) {
	// condition = check Key and stop going outside
	if (Keyboard::isKeyPressed(Keyboard::Up)&&square.getPosition().y>0)			{ square.move(0.f, -5.f); }
	if (Keyboard::isKeyPressed(Keyboard::Down)&&square.getPosition().y<window.getSize().y-square.getSize().y) 
	{ square.move(0.f, 5.f); }

	if (Keyboard::isKeyPressed(Keyboard::Right))								{ square.move(5.f, 0.f); }
	if (Keyboard::isKeyPressed(Keyboard::Left))									{ square.move(-5.f, 0.f); }

	// Change color when click
	if (Mouse::isButtonPressed(Mouse::Left)) {		square.setFillColor(Color::Yellow);	}
	else											square.setFillColor(Color::Red);
}
	
void Draw(RenderWindow& window, RectangleShape& square) {
	window.clear(Color::White);
	window.draw(square);
	window.display();
}