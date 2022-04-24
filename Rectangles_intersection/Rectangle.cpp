#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Rectangle.h"

using namespace sf;

    Rectangle::Rectangle(int b, int h, int X, int Y, std::string color, std::string N){
			base = b;
			height = h;
			name = N;
			x = X, y = Y;
			body.setPosition(Vector2f(x,y));
			body.setSize(Vector2f(base,height));
			if(color == "Blue")	body.setFillColor(Color::Blue);
			if(color == "Green")	body.setFillColor(Color::Green);
			if(color == "Red")	body.setFillColor(Color::Red);
			
		}
		
		int Rectangle::coordX(){
			return x;
		}
		int Rectangle::coordY(){
			return y;
		}
		
		int Rectangle::Base(){ 
			return base;
		}
		
		int Rectangle::Height(){ 
			return height;
		}
		
		bool Rectangle::intersect(Rectangle* other){
			return (x < other->coordX() + other->Base() &&
			 x + base > other->coordX() &&
			  y < other->coordY() + other->Height() &&
			   other->coordY() < y + height);
		}
		
		Rectangle Rectangle::intersection(Rectangle* other){
			int x2 = other->coordX();
			int y2 = other->coordY();
			int base2 = other->Base();
			int height2 = other->Height();
			
			if(intersect(other)){
				int new_x, new_y, new_base, new_height;
				if(x < x2 && y < y2){
					
					new_x = x2;
					new_y = y2;
					x + base <= x2 + base2 ? new_base = x + base - x2 : new_base = base2;
					y + height <= y2 + height2 ? new_height = y + height - y2 : new_height = height2;
					
				}else if(x < x2 && y > y2){
					
					new_x = x2;
					new_y = y;
					x + base <= x2 + base2 ? new_base = x + base - x2 : new_base = base2;
					y + height >= y2 + height2 ? new_height = y2 + height2 - y : new_height = height;
					
				}else if(x > x2 && y < y2){
					
					new_x = x;
					new_y = y2;
					x + base >= x2 + base2 ? new_base = x2 + base2 - x : new_base = base;
					y + height <= y2 + height2 ? new_height = y + height - y2 : new_height = height2;
				
				}else if(x > x2 && y > y2){
					
					new_x = x;
					new_y = y;
					x + base >= x2 + base2 ? new_base = x2 + base2 - x : new_base = base;
					y + height >= y2 + height2 ? new_height = y2 + height2 - y : new_height = height;
				}
			Rectangle New(new_base, new_height, new_x, new_y, "Red");
				
			return New;
			} else {
				Rectangle New(0,0);
				std::cout << "\nDont't intersect! Return standard rectangle";
				return New;
			}
		}
		
		void Rectangle::setColor(std::string color){
			if(color == "Blue")	body.setFillColor(Color::Blue);
			if(color == "Green") body.setFillColor(Color::Green);
			if(color == "Red")	body.setFillColor(Color::Red);
		}

		void Rectangle::setNewSize(int b, int h){
			base = b;
			height = h;
			body.setSize(Vector2f(base,height));
		}
		
		void Rectangle::State(){
			printf("\nRectangle status, Base: %d , Height: %d, X: %d, Y: %d", this->Base(), this->Height(), x, y) ;
		}
		
		void Rectangle::Perimeter(){
			printf("\nPerimeter: %d", (this->Base() + this->Height())*2);
		}
		
		void Rectangle::Area(){
			printf("\nArea: %d", this->Base()*this->Height());
		}
		void Rectangle::Center(){
			printf("\nIl centro e': {%f,%f}", x + float(this->Base())/2, y + float(this->Height())/2);
		}
		void Rectangle::Translate(int offset_x, int offset_y){
			x += offset_x; y += offset_y;
			body.setPosition(Vector2f(x,y));
		}
		void Rectangle::setScale(int scale){
			base *= scale; height *= scale;
			body.setSize(Vector2f(base*scale, height*scale));
		}
		
		void Rectangle::Show(){
			printf("\n");
			int i = 0, j = 0;
			for(i = 0; i < this->Height(); i++){
				for(j = 0; j < this->Base(); j++){
					j == 0 || j == this->Base() - 1 || i == 0 || i == this->Height() - 1 ? printf("# ") : printf("  ");
				}
				printf("\n");
			}
		}

		void Rectangle::Show(RenderWindow* screen){
			screen->draw(body);
		}

		void Rectangle::Control(Keyboard* k, bool WASD){
			if(WASD){
				if(Keyboard::isKeyPressed(Keyboard::W)){    /////////
					y -= speed;
					body.move(0,-speed);
				}else if(k->isKeyPressed(Keyboard::S)){
					y += speed;
					body.move(0,speed);
				}else if(k->isKeyPressed(Keyboard::A)){
					x -= speed;
					body.move(-speed,0);
				}else if(k->isKeyPressed(Keyboard::D)){
					x += speed;
					body.move(speed,0);
				}
			} else {
				if(k->isKeyPressed(Keyboard::Up)){
					y -= speed;
					body.move(0,-speed);
				}else if(k->isKeyPressed(Keyboard::Down)){
					y += speed;
					body.move(0,speed);
				}else if(k->isKeyPressed(Keyboard::Left)){
					x -= speed;
					body.move(-speed,0);
				}else if(k->isKeyPressed(Keyboard::Right)){
					x += speed;
					body.move(speed,0);
				}
			}
		}