#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

/* not complete this topic and playlist of sfml*/

using namespace sf;

int main() {

	RenderWindow window(VideoMode(1000.f,800.f), "FrameRate Independent !!");
	window.setFramerateLimit(100);
	//window.setFramerateLimit(200);
	/*
		Frame Rate varies in devices 
		So if you code some here and move your char it moves normal 
		but when you shift it to other device it moves either too fast or slow

		Because no. of frames are changed in one second.	

		setFramerateLimit  drops frame's that makes game to unsmooth

		we have make the game frame indepedent for smooth
	*/

	/* check frame rate*/
	Clock clock;
	float dt;
	float multiplier=60;

	RectangleShape rect;
	rect.setSize(Vector2f(100.f,50.f));
	rect.setOrigin(50.f, 25.f);			// set origin to center
	
	rect.setPosition(500.f, 400.f);
	rect.setFillColor(Color::Red); 
	

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		dt = clock.restart().asSeconds();


		/* Now it move same whatever the frame Rate is.*/
		if (Keyboard::isKeyPressed(Keyboard::Up))
			//rect.move(0.f, -10.f*dt*multiplier);
			rect.move(0.f, -10.f);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			rect.move(0.f, 10.f * dt * multiplier);
		if (Keyboard::isKeyPressed(Keyboard::Right))
			rect.move(10.f * dt * multiplier, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			rect.move(-10.f * dt * multiplier, 0.f);
		

		window.clear(Color::White);

		window.draw(rect);

		window.display();

		std::cout << "dt: " << dt << "\n";
	}

	return 0;
}