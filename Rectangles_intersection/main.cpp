#include <iostream>
#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


//USAGE EXAMPLE
int main(){
    unsigned int w = 800,h = 800;
	RenderWindow screen(VideoMode(w,h), "Rect", Style::Close | Style::Titlebar);
	Event e;
	Keyboard k;

	Rectangle A(400,200, 200,200, "Green");
	Rectangle B(400,250, 50,20, "Blue");
	A.State();
	B.State();
	
	Rectangle C(0,0,0,0);

    while(screen.isOpen()){
		while(screen.pollEvent(e)){
			if(e.type == e.Closed) screen.close();
		}
        
        A.intersect(&B) ? printf("\nIntersect!") : printf("\nDon't intersect");
		C = A.intersection(&B);
		screen.clear(Color::Black);
		A.Control(&k, true);
		B.Control(&k, false);
		A.Show(&screen);
		B.Show(&screen);
		C.Show(&screen);
		screen.display();
	
	}
    return 0;
}