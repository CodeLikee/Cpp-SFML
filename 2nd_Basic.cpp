#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
	
using namespace sf;

int main() {
   // creating object of RenderWindow Class : window
	 RenderWindow window( VideoMode(800, 600), "Basic of SFML!",Style::Default);
   // having constructor (window size, title, style)

   /* Setup frane rate limit to save graphis card */
    window.setFramerateLimit(40);


    /* Starting the main loop   by checking window is open? */
   while (window.isOpen())
   {
        Event event;

       /* pollEvent takes all the events in event object */
       while (window.pollEvent(event))
       {
           // if event_type is close then we call fun:
           if (event.type ==  Event::Closed)
               window.close();
       }




       // Update window here
       window.clear();      // it clears all the old stuff that you represent

       // code to show all stuff as new


       window.display();    // it display new things that you write before it.
   }	
	return 0;
}