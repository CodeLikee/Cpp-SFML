#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {

	RenderWindow window(VideoMode(1000.f,800.f), "Rotation");
	window.setFramerateLimit(40);

	RectangleShape rect;
	rect.setSize(Vector2f(100.f,50.f));
	//rect.setOrigin(50.f, 25.f);			// set origin to center

	rect.setPosition(500.f, 400.f);
	rect.setFillColor(Color::Red); 

	CircleShape cir(100.f);
	cir.setFillColor(Color::Black);

	//cir.setOrigin(100.f, 100.f);        // set origin to center
	cir.setPosition(window.getSize().x/ 2, window.getSize().y / 2);


	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
			rect.move(0.f, -10.f);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			rect.move(0.f, 10.f);
		if (Keyboard::isKeyPressed(Keyboard::Right))
			rect.move(10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			rect.move(-10.f, 0.f);


		if (Keyboard::isKeyPressed(Keyboard::Space))
			rect.rotate(10.f);

		


		window.clear(Color::White);
		window.draw(cir);
		window.draw(rect);
		window.display();
	}

	return 0;
}