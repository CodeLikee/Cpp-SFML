#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {

	RenderWindow window(VideoMode(1000, 800), "Keyboard Mouse Input");
	window.setFramerateLimit(40);

	while (window.isOpen()) {

		Event event;
		while(window.pollEvent(event)){
			if (event.type == Event::Closed)
				window.close();
			
			/************* Keyboard Events ********(insid event handler)/
				//if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape){
				//	window.close();

			
			/**** Mouse Events ***(indsid event handler)*/
			if (event.type == Event::MouseButtonPressed && event.MouseButtonPressed == Mouse::Left) {
				window.close();
				}
		}

		/* outside event handler */
		//if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		//		window.close();
		//}

		/**** Mouse Events ***/
		if (Mouse::isButtonPressed(Mouse::Left))
			window.close();

		window.clear(Color::Red);
		window.display();


	}
	return 0;
}