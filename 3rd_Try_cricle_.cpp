#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {
  
   RenderWindow window(VideoMode(800, 600), "Basic of SFML!", Style::Default);
   window.setFramerateLimit(40);

   // Creating circle shape
   CircleShape shape(50.f);

   while (window.isOpen())
   {
       Event event;


       while (window.pollEvent(event))
       {
           if (event.type == Event::Closed)
               window.close();
       }

       // moving the circle
       shape.move(5.0f, 0.0f);


       // clear by color the window also
       window.clear(Color::Red);

       // show shape on window
       window.draw(shape);

       window.display();
   }
   return 0;
}