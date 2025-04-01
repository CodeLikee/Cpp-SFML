#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {
	// Fix the size of window
	//RenderWindow window(VideoMode(1000.f, 800.f), "Windows Style ", Style::Close | Style::Titlebar);

	RenderWindow window(VideoMode(1000.f,800.f), "Windows Style ");
	window.setFramerateLimit(40);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.clear(Color::White);
		window.display();
	}

	return 0;
}