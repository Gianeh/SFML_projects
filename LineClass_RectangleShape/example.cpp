#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Line.h"

int main(){
  unsigned int size = 1000;
  sf::RenderWindow screen(sf::VideoMode(size, size), "Usage example", sf::Style::Close() | sf::Style::Titlebar);
  sf::Event e;
  int controlSpeed = 2;
  Line L1(0,0 , size,size, "green", 5);
  while(screen.isOpen()){
    while(screen.pollEvent(e)){
      if(e.type == e.Closed)  screen.close();
    }
    L1.control();
    screen.draw(L1);
    screen.display(controlSpeed);
  }
  return 0;
}
