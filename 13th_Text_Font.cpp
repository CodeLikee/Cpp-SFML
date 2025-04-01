#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {

	RenderWindow window(VideoMode(1100.f,800.f), "Text and Fonts");
	window.setFramerateLimit(60);

	/* Fonts :*/
	Font font;
	font.loadFromFile("Fonts/HARNGTON.TTF"); 
	//C:\Windows\Fonts     // for extra fonts

	Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold);
	text.setString("Hi, how are you ??");
	text.setPosition(window.getSize().x/3, window.getSize().y / 3);
	int dir = 0;

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		// Update
		if (text.getPosition().y <= -10)
			dir = 0;
		if (text.getPosition().y > window.getSize().y-50)
			dir = 1;
		if (dir)
			text.move(0.f, -2.f);
		else
			text.move(0.f, 2.f);



		window.clear(Color::White);

		/* Text */
		window.draw(text);


		window.display();
	}

	return 0;
}