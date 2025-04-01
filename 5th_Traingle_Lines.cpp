#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {

	RenderWindow window(VideoMode(1000, 800), "Traingle, Lines and Convex");
	window.setFramerateLimit(40);
		
	/* Traingle with Circle */
	CircleShape traingle;
	traingle.setRadius(150.f);
	traingle.setPointCount(3);   //  3 for traingle  as you increase shape changes
	
	traingle.setFillColor(Color::Blue);
	traingle.setPosition(Vector2f(100.f,50));

	/* Line :- */
	Vertex line[] = { Vertex(Vector2f(450,100)),Vertex(Vector2f(750,100)) };// giving cordinates of line
	

	/* Convex shape*/
	ConvexShape convex;
	convex.setPosition(Vector2f(150, 500));

	convex.setPointCount(5);	// no. of points of convex shape that we need
	
	convex.setPoint(0, Vector2f(0, 0));		// set point for convex shape
	convex.setPoint(1, Vector2f(100, -80));
	convex.setPoint(2, Vector2f(200, 0));
	convex.setPoint(3, Vector2f(180, 100));
	convex.setPoint(4, Vector2f(20, 100));

	/* out line */
	convex.setOutlineThickness(15.f);
	convex.setOutlineColor(Color::Cyan);

	while (window.isOpen()) {
		Event event;
		
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::Red);

		window.draw(traingle);
		window.draw(line, 2,Lines);	// var_name     no. of Vertex   what to draw
		window.draw(convex);

		window.display();
	}

	return 0;
}