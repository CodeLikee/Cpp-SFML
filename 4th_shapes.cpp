#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main() {

   RenderWindow window(VideoMode(1000, 800), "Basic of SFML!", Style::Default);
   window.setFramerateLimit(40);

  /* Shapes:- */
   CircleShape circle(50.f);   // it takes radius as para.me
   circle.setPosition(Vector2f(100.f, 100.f));   // x,y     from top
   circle.setFillColor(Color::Yellow);

   RectangleShape rect(Vector2f(100.f,50.f)); // width , height
   rect.setPosition(Vector2f(500.f, 100.f));     
   rect.setFillColor(Color(0,0,255,200));  // also do like this with rgb value  and last change brightness

   while (window.isOpen())
   {
       Event event;


       while (window.pollEvent(event))
       {
           if (event.type == Event::Closed)
               window.close();
       }

       // rotate shapes   : about origin which  is top left
       circle.rotate(0.1f);
       rect.rotate(5.5f);

       
       window.clear(Color:: Red);

       window.draw(circle);
       window.draw(rect);
       
       
       
       window.display();
   }
   return 0;
}