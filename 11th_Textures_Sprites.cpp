#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {

	RenderWindow window(VideoMode(1000.f, 800.f), "Cat Doge");
	window.setFramerateLimit(30);

	// Cat
	Texture catTexture;
	Sprite cat;

	if (!catTexture.loadFromFile("Textures/cat.png"))
		throw " unable to load cat texture !!";

	cat.setTexture(catTexture);
	cat.setScale(Vector2f(0.2f, 0.2f));   //      acutual size * to we give
	int catSpawnTimer=15;

	std::vector<Sprite> cats; // a lot of cats we need
	cats.push_back(Sprite(cat));


	// Dog
	Texture dogTexture;
	Sprite dog;

	if (!dogTexture.loadFromFile("Textures/dog.png"))
		throw " unable to load dog texture !!";
	dog.setTexture(dogTexture);
	dog.setScale(Vector2f(0.3f, 0.3f));
	dog.setPosition(80.f, 10.f);
	int hp = 10;
	RectangleShape hpbar(Vector2f((float)hp * 20.f, 20.f));
	hpbar.setFillColor(Color::Green);
	hpbar.setPosition(Vector2f(400.f, 10.f));


	while (window.isOpen()&&hp>0) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		for (int j = 0; j < cats.size(); j++)
		{
			cats[j].move(-7.f, 0.f);
			if (cats[j].getPosition().x < 0 - cat.getGlobalBounds().width)
				cats.erase(cats.begin() + j);
		}

		// Update

		// DOG
		dog.setPosition(dog.getPosition().x, Mouse::getPosition(window).y);
		if(dog.getPosition().y < 0)
			dog.setPosition(dog.getPosition().x, 0);
		if(dog.getPosition().y >=window.getSize().y - dog.getGlobalBounds().height)
			dog.setPosition(dog.getPosition().x, window.getSize().y-dog.getGlobalBounds().height);

		//	CAT
		if (catSpawnTimer < 40)
			catSpawnTimer++;
		if (catSpawnTimer >= 40) {
			cat.setPosition(window.getSize().x, rand() % int(window.getSize().y - cat.getGlobalBounds().height));
			cats.push_back(Sprite(cat));
			catSpawnTimer = 0;
		}
		// Coillision
		for (int i = 0; i < cats.size(); i++)
		{
			if (dog.getGlobalBounds().intersects(cats[i].getGlobalBounds())) {
				hp--;
				// hp Bar
				hpbar.setSize(Vector2f((float)hp * 20.f, 20.f));
				cats.erase(cats.begin() + i);
			}
			if (cats[i].getPosition().x < 0)
				cats.erase(cats.begin() + i);

		}

		window.clear(Color::White);

		// cat 
		for (int i = 0; i < cats.size(); i++)
		{
				window.draw(cats[i]);
		}
		window.draw(dog);
		window.draw(hpbar);
		window.display();
	}

	return 0;
}