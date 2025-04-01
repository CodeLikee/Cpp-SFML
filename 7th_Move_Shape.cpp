#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {

	RenderWindow window(VideoMode(1000, 800), "Simple Game");
	window.setFramerateLimit(30);

	CircleShape traingle(50.f,3);
	traingle.setFillColor(Color::Cyan);

	traingle.setPosition(100.f , 200.f);

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Left)
					traingle.move(-5.f, 0.f);
				if (event.key.code == Keyboard::Right)
					traingle.move(5.f, 0.f);
				if (event.key.code == Keyboard::Up)
					traingle.move(0.f, -5.f);
				if (event.key.code == Keyboard::Down)
					traingle.move(0.f, 5.f);

			}
		}
		window.clear(Color::Red);

		window.draw(traingle);
		window.display();
	}
	return 0;
}