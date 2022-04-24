#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace sf;
//not the most precisce line ever, but an efficient RectangleShap-ed model that easily fits two points.
//Inspired from the argument of a complex number.
class Line
{
	private:
		int x1, y1, x2, y2;
		float thickness, length;
		float slope = 1;
		std::string color;
		RectangleShape lin;

	public:
		Line(int x1_, int y1_, int x2_, int y2_, std::string color = "", float thick = 2.0);
		void update(int x1_, int y1_, int point = 1);
		void control(int speed);
		void setColor(std::string color);
		RectangleShape line();
};

