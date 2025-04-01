#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
   RenderWindow window(VideoMode(800, 600), "SFML Button Example");
   window.setFramerateLimit(60);

   RectangleShape button;
   button.setPosition(100.f, 100.f);
   button.setSize(Vector2f(150.f, 50.f));
   button.setFillColor(Color::Blue);

   bool isHovered=false;

   auto onClick([]() {        std::cout << "Button clicked!\n";        });

   while (window.isOpen()) {
       Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed)
               window.close();
       }

       if (event.type == Event::MouseMoved) {
           // Check if mouse is over the button
           Vector2i mousePos = Mouse::getPosition(window);
           if(button.getGlobalBounds().contains(mousePos.x, mousePos.y))
               isHovered = true; 
           else
               isHovered = false; 

       }
       button.setFillColor(isHovered ? Color::Green : Color::Blue);

       if (event.type == Event::MouseButtonPressed && isHovered) {
           if (event.mouseButton.button == Mouse::Left && onClick) {
               //onClick();
               std::cout << "Button clicked!\n";
               isHovered = false;
           }
       }
       window.clear(Color::White);
       window.draw(button);
       window.display();
   }
   return 0;
}
