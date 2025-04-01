#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<math.h>
#include<cstdlib>
#include<vector>

using namespace sf;

/*
	Vector Math
	Length of Vector :-	|V| =	sqrt(  pow(Vx,2)	+  pow(Vy,2)	 )

	Normalize Vector :- (Vx,Vy)/	|V|
*/

class Bullet {
public:
	Sprite bullet;
	Texture* texture;

	Bullet(Texture *texture,Vector2f pos) {
		this->bullet.setTexture(*texture);
		this->bullet.setScale(0.05f, 0.05f);
		this->bullet.setPosition(pos.x+60.f,pos.y+42.f);
	}

	~Bullet(){}
};

class Player {
public:
	Sprite shape;
	Texture* texture;
	int Hp;
	int HpMax;

	std::vector<Bullet> bullets;

	Player(Texture* texture) {
		this->HpMax=10;
		this->Hp=this->HpMax;
		this->texture = texture;
		this->shape.setTexture(*texture);
		this->shape.setScale(0.2f, 0.2f);
	}
	~Player() {}
};

class Enemy {
public:
	int Hp;
	int HpMax;
	Sprite shape;
	Texture* texture;
	Enemy(Texture* texture,Vector2u windowSize) {
		this->HpMax = rand() % 3 + 1;
		this->Hp = this->HpMax;
		this->shape.setTexture(*texture);
		this->shape.setScale(0.3f, 0.3f);
		this->shape.setPosition(windowSize.x, rand() % int(windowSize.y - this->shape.getGlobalBounds().height));
	}
	~Enemy(){}
};


int main() {
	srand(time(NULL));
	bool GamePause = false;

	RenderWindow window(VideoMode(1000.f, 800.f), "Space Shooter");
	window.setFramerateLimit(40);

	// Init Text
	Font font;
	font.loadFromFile("Fonts/CascadiaCode.ttf");
	Font font2;
	font2.loadFromFile("Fonts/HARNGTON.TTF");


	// Init Texture
	Texture playerTex;
	playerTex.loadFromFile("Textures/ship.png");

	Texture enemyTex;
	enemyTex.loadFromFile("Textures/enemy.png");

	Texture bullteTex;
	bullteTex.loadFromFile("Textures/missile.png");


	// Player init
	Player player(&playerTex);
	int shootTimmer = 20;
	Text hpText;
	hpText.setFont(font);
	hpText.setFillColor(Color::Green);
	hpText.setCharacterSize(30.f);

	// Score 
	int score = 0;
	Text Score;
	Score.setFont(font2);
	Score.setCharacterSize(50.f);
	Score.setFillColor(Color::Blue);
	Score.setPosition(Vector2f(10.f,10.f));
	
	// Game Over
	Text GameOver;
	GameOver.setFont(font2);
	GameOver.setString("Game Over!!");
	GameOver.setCharacterSize(100.f);
	GameOver.setFillColor(Color::Red);
	GameOver.setPosition(Vector2f(200.f,300.f));

	// Enemy init
	std::vector<Enemy> enemies;
	int spawnTimmer = 0;
	RectangleShape hpShape;
	hpShape.setFillColor(Color::Green);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
				if (GamePause)
					GamePause = false;
				else
					GamePause = true;
			}
		}
		if(GamePause){}
		else if (player.Hp > 0) {
			//Update

			// Player
			if (Keyboard::isKeyPressed(Keyboard::Up) && player.shape.getPosition().y > -25)
				player.shape.move(0.f, -10.f);
			if (Keyboard::isKeyPressed(Keyboard::Down) && player.shape.getPosition().y < window.getSize().y - 65)
				player.shape.move(0.f, 10.f);
			if (Keyboard::isKeyPressed(Keyboard::Right) && player.shape.getPosition().x < window.getSize().x - 90)
				player.shape.move(10.f, 0.f);
			if (Keyboard::isKeyPressed(Keyboard::Left) && player.shape.getPosition().x > 0)
				player.shape.move(-10.f, 0.f);

			hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - 30);
			hpText.setString(std::to_string(player.Hp) + "/" + std::to_string(player.HpMax));


			// Bullets
			if (shootTimmer <= 3)
				shootTimmer++;
			if (Keyboard::isKeyPressed(Keyboard::Space) && shootTimmer > 3) {
				player.bullets.push_back(Bullet(&bullteTex, player.shape.getPosition()));
				shootTimmer = 0;
			}
			for (int i = 0; i < player.bullets.size(); i++)
			{
				player.bullets[i].bullet.move(10.f, 0.f);
				if (player.bullets[i].bullet.getPosition().x >= window.getSize().x - 40) {
					player.bullets.erase(player.bullets.begin() + i);
					break;
				}
				for (int k = 0; k < enemies.size(); k++)
				{
					if (player.bullets[i].bullet.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds())) {
						player.bullets.erase(player.bullets.begin() + i);
						if (enemies[k].Hp <= 0) {
							score += enemies[k].HpMax;
							enemies.erase(enemies.begin() + k);
							break;
						}
						else
							enemies[k].Hp--; // Damage to Enemy
						break;
					}
				}
			}

			// Enemy
			if (spawnTimmer < 15)
				spawnTimmer++;
			if (enemies.size() <= 5 && spawnTimmer >= 15) {
				enemies.push_back(Enemy(&enemyTex, window.getSize()));
				spawnTimmer = 0;
			}
			for (int i = 0; i < enemies.size(); i++)
			{
				enemies[i].shape.move(-5.f, 0.f);
				if (enemies[i].shape.getPosition().x < 0) {
					enemies.erase(enemies.begin() + i);
					break;
				}
				if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
					enemies.erase(enemies.begin() + i);
					player.Hp--; // Damage to player
					break;
				}
			}

			// Score
			Score.setString("Score :" + std::to_string(score));

			window.clear(Color::White);
			// Draw
			// Player
			window.draw(player.shape);
			//vBullets
			for (int i = 0; i < player.bullets.size(); i++)
			{
				window.draw(player.bullets[i].bullet);
			}
			// Enemy
			for (int i = 0; i < enemies.size(); i++)
			{
				window.draw(enemies[i].shape);
				hpShape.setSize(Vector2f((enemies[i].Hp + 1) * 20.f, 10.f));
				hpShape.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y + 20);
				window.draw(hpShape);
			}

			window.draw(hpText);
			window.draw(Score);
		}
		if (player.Hp <= 0) {
			window.clear(Color::Green);
			window.draw(Score);
			window.draw(GameOver);
		}
		window.display();
	}

	return 0;
}