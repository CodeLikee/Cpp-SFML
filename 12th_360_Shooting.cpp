#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<vector>
#include<cstdlib>  // ????

#include<math.h> // easy to use maths functions

// Length of vector :- |V| = sqrt(V.x^2 + V.y^2)
// Normalize vector :- U = V/ |V| 

using namespace sf;

class Bullet {
public:

	CircleShape shape;
	Vector2f currVelocity;
	float maxSpeed;

	Bullet(float radius = 5.f) 
		: currVelocity(0.f,0.f),maxSpeed(15.f)
	{	
		this->shape.setRadius(radius);
		this->shape.setFillColor(Color::Red); 
	}
};

int main() {

	srand(time(NULL));
	RenderWindow window(VideoMode(1000.f, 800.f), "360 Shooting");
	window.setFramerateLimit(40);

	/* Player information:- */
	CircleShape player(50.f);
	player.setFillColor(Color::Green);
	player.setPosition(500.f, 400.f);

	// Bullets:
	Bullet b1;
	std::vector<Bullet> bullets;
	

	// Enemy :
	RectangleShape enemy(Vector2f(50.f,50.f));
	int spawnCounter = 20;
	enemy.setFillColor(Color::Blue);
	std::vector<RectangleShape> enemies;
	//enemies.push_back(RectangleShape(enemy));


	/* vector: */
	Vector2f playerCenter;
	Vector2f mousePosWindow;
	Vector2f aimDir;
	Vector2f aimDirNorm;




	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		//Update
		/*Vector*/
		playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
		mousePosWindow = Vector2f(Mouse::getPosition(window));
		aimDir = mousePosWindow - playerCenter;
		aimDirNorm = Vector2f(aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)), aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
		
		//std::cout << aimDirNorm.x << "  " << aimDirNorm.y << "\n";

		/* Player */
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.move(0.f, -10.f);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.move(0.f, 10.f);
		if (Keyboard::isKeyPressed(Keyboard::Right))
			player.move(10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			player.move(-10.f, 0.f);

		/* Enemies: */
		if (spawnCounter < 20)
			spawnCounter++;
		if (spawnCounter >= 20 && enemies.size()<20) {
			enemy.setPosition(Vector2f(rand() % window.getSize().x,rand() % window.getSize().y));
			enemies.push_back(RectangleShape(enemy));
			spawnCounter = 0;
		}

		// Shooting
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			b1.shape.setPosition(playerCenter);
			b1.currVelocity = aimDirNorm * b1.maxSpeed;
			bullets.push_back(b1);
		}

		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].shape.move(bullets[i].currVelocity);

			if (bullets[i].shape.getPosition().x<0 || bullets[i].shape.getPosition().x > window.getSize().x
				|| bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window.getSize().y) {
				bullets.erase(bullets.begin() + i);
			
			}
			else {
				// Enemy Collision
				for (int j = 0; j < enemies.size(); j++)
				{
					if (bullets[i].shape.getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
						bullets.erase(bullets.begin() + i);
						enemies.erase(enemies.begin() + j);
						break;
					}
				}
			}

		}


		//Draw
		window.clear(Color::White);
		for (size_t i = 0; i < enemies.size(); i++)
		{
			window.draw(enemies[i]);
		}

		window.draw(player);

		for (int i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i].shape);
		}

		window.display();
	}



	return 0;
}