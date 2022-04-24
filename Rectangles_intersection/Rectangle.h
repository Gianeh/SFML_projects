#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Rectangle{
    
	private: 
		int base = 1, height = 1;
		int x = 0,y = 0;
		std::string name = "Default";
		RectangleShape body;
		int speed = 1;
	
	public:
		Rectangle(int b, int h, int X = 0, int Y = 0, std::string color = "Blue", std::string N = "Default");
        int coordX();
        int coordY();
        int Base();
        int Height();
        void State();
        void Perimeter();
        void Area();
        void Center();
        void Show();
        void Show(RenderWindow* screen);
        void Control(Keyboard* k, bool WASD = true);
        void Translate(int offset_x, int offset_y);
        bool intersect(Rectangle* other);
        Rectangle intersection(Rectangle* other);
        void setColor(std::string color);
        void setNewSize(int b, int h);
        void setScale(int scale);
};
        