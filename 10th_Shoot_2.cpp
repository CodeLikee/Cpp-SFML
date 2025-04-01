#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include<cstdlib>
#include<vector>

using namespace sf;

int main() {
	srand(time(NULL));

	RenderWindow window(VideoMode(1000.f, 800.f), "Ball Shooter");
	window.setFramerateLimit(60);

	// Player
	CircleShape player(50.f);
	player.setFillColor(Color::Cyan);
	player.setPosition(window.getSize().x/2 - player.getRadius(), window.getSize().y - player.getRadius()*2-10.f);
	Vector2f playerCenter;
	int ShootTimer = 0;


	// Enemy
	RectangleShape enemy(Vector2f(50.f, 50.f));
	enemy.setFillColor(Color::Blue);
	int enemySpawnTimer = 0;

	std::vector<RectangleShape> enemies;
	enemies.push_back(RectangleShape(enemy));


	// Projecitles
	CircleShape projectile(5.f);
	projectile.setFillColor(Color::Red);

	std::vector<CircleShape> projectiles;
	projectiles.push_back(CircleShape(projectile));



	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		//Upadate
		playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());

		// player location
		player.setPosition(Mouse::getPosition(window).x, player.getPosition().y);

		// Shooting
		if (ShootTimer < 5)
			ShootTimer++;

		if (Keyboard::isKeyPressed(Keyboard::Space) && ShootTimer >= 5) {
			projectile.setPosition(playerCenter);
			projectiles.push_back(CircleShape(projectile));
			ShootTimer = 0;
		}
		for (int i = 0; i < projectiles.size(); i++)
		{
			projectiles[i].move(0.f, -5.f);
			// erase or remove extra 
			if (projectiles[i].getPosition().y <= 0) {
				projectiles.erase(projectiles.begin() + i);
			}
		}

		// Enemy
		if (enemySpawnTimer < 10)
			enemySpawnTimer++;

		if (enemySpawnTimer >= 10) {
			enemy.setPosition(rand() % int(window.getSize().x - enemy.getSize().x), 0.f);
			enemies.push_back(RectangleShape(enemy));
			enemySpawnTimer = 0;
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].move(0.f, 5.f);
			// erase or remove extra 
			if (enemies[i].getPosition().y >= window.getSize().y - 100.f) {
				enemies.erase(enemies.begin() + i);
			}
		}

		/* Collision */
		if (!enemies.empty() && !projectiles.empty()){
			for (int i = 0; i < projectiles.size(); i++)
			{
				for (int k = 0; k < enemies.size(); k++)
				{
					if (projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds())) {
						projectiles.erase(projectiles.begin() + i);
						enemies.erase(enemies.begin() + k);
						break;
					}
				}
			}
		}

		window.clear(Color::White);

		// draw
		window.draw(player);

		for (int i = 0; i < enemies.size(); i++)
		{
			window.draw(enemies[i]);
		}
		
		for (int i = 0; i < projectiles.size(); i++)
		{
			window.draw(projectiles[i]);
		}

		window.display();
	}
	return 0;
}