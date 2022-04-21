#include "Line.h"
#define PI 3.1415926535897 //Conversion from rad to deg

//not the most precisce line ever, but an efficient RectangleShap-ed model that easily fits two points.
Line::Line(int x1_, int y1_, int x2_, int y2_, std::string color, float thick) {
	x1 = x1_; y1 = y1_; x2 = x2_; y2 = y2_;
	thickness = thick;
	float Dx, Dy;
	Dx = abs(x1 - x2);
	Dy = abs(y1 - y2);
	length = sqrt(pow(Dx, 2) + pow(Dy, 2));
	lin.setSize(Vector2f(length,thickness));

	//SLOPE RULES
	if (Dx == 0 && y1 < y2) slope = 90;
	else if (Dx == 0 && y1 > y2) slope = -90;
	else if (x1 < x2 && y1 < y2) slope = atan(Dy/Dx)*180/PI;
	else if (x1 < x2 && y1 > y2) slope = -atan(Dy/Dx)*180/PI;
	else if (x1 < x2 && y1 == y2) slope = 0;
	else if (x1 > x2 && y1 > y2) slope = atan(Dy/Dx)*180/PI + 180;
	else if (x1 > x2 && y1 < y2) slope = -atan(Dy/Dx)*180/PI + 180;

	else if (Dx == 0 && Dy == 0) {
		slope = 0; printf("\nWarning! slope is 0, check if is given two times the same point");
	}
	
	//SFML FUNCTION, TAKES DEG VALUES
	lin.setRotation(slope);

	//doesn't create any bugs on first positioning
	float dx, dy;
	dx = thickness/2 * cos(slope);
	dy = thickness/2 * sin(slope);
	lin.setPosition(x1 + dx , y1 - dy);


	//sets color, if NULL -> black
	if (color == "black" || color == "Black") {
		lin.setFillColor(Color::Black);
	}else if (color == "white" || color == "White") {
		lin.setFillColor(Color::White);
	}else if (color == "green" || color == "Green") {
		lin.setFillColor(Color::Green);
	}else if (color == "red" || color == "Red") {
		lin.setFillColor(Color::Red);
	}else {
		lin.setFillColor(Color::Black);
	}
}

void Line::control(int speed){
	if(Keyboard::isKeyPressed(Keyboard::W)){
            update(x1 , y1 - speed, 1);
    }
	else if(Keyboard::isKeyPressed(Keyboard::S)){
            update(x1 , y1 + speed, 1);
    }
	else if(Keyboard::isKeyPressed(Keyboard::D)){
            update(x1 + speed , y1, 1);
    }
	else if(Keyboard::isKeyPressed(Keyboard::A)){
            update(x1 - speed , y1, 1);
    }


	if(Keyboard::isKeyPressed(Keyboard::Up)){
            update(x2 , y2 - speed, 2);
    }
	else if(Keyboard::isKeyPressed(Keyboard::Down)){
            update(x2 , y2 + speed, 2);
    }
	else if(Keyboard::isKeyPressed(Keyboard::Right)){
            update(x2 + speed , y2, 2);
    }
	else if(Keyboard::isKeyPressed(Keyboard::Left)){
            update(x2 - speed , y2, 2);
    }

	
}

void Line::update(int x, int y, int point){
	if (point == 1) { x1 = x; y1 = y; }
	else if (point == 2) { x2 = x; y2 = y; }
	else return;
	
	float Dx, Dy;
	Dx = abs(x1 - x2);
	Dy = abs(y1 - y2);
	length = sqrt(pow(Dx, 2) + pow(Dy, 2));
	lin.setSize(Vector2f(length,thickness));

	//SLOPE RULES
	if (Dx == 0 && y1 < y2) slope = 90;
	else if (Dx == 0 && y1 > y2) slope = -90;
	else if (x1 < x2 && y1 < y2) slope = atan(Dy/Dx)*180/PI;
	else if (x1 < x2 && y1 > y2) slope = -atan(Dy/Dx)*180/PI;
	else if (x1 < x2 && y1 == y2) slope = 0;
	else if (x1 > x2 && y1 > y2) slope = atan(Dy/Dx)*180/PI + 180;
	else if (x1 > x2 && y1 < y2) slope = -atan(Dy/Dx)*180/PI + 180;

	else if (Dx == 0 && Dy == 0) {
		slope = 0; printf("\nWarning! slope is 0, check if is given two times the same point");
	}
	
	
	lin.setRotation(slope);


	//This setup should (in my idea) correct the position based on thickness.
	//Currently creates some strange movements (when calling control() function).
	// 
	//float dx, dy;
	//dx = thickness/2 * cos(slope);
	//dy = thickness/2 * sin(slope);
	//lin.setPosition(x1, y1 );
}

void Line::setColor(std::string color) {
	//sets color, if NULL -> black
	if (color == "black" || color == "Black") {
		lin.setFillColor(Color::Black);
	}
	else if (color == "white" || color == "White") {
		lin.setFillColor(Color::White);
	}
	else if (color == "green" || color == "Green") {
		lin.setFillColor(Color::Green);
	}
	else if (color == "red" || color == "Red") {
		lin.setFillColor(Color::Red);
	}
	else {
		lin.setFillColor(Color::Black);
	}
}

RectangleShape Line::line() {
	return lin;
}