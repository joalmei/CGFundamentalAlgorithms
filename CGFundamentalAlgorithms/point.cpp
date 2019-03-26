#include "point.h"


// ====================================================================================
// PUBLIC MEMBERS
// ====================================================================================
Point::Point() {
}

Point::~Point() {
}

Point Point::Create(unsigned int x, unsigned int y) {
	Point point;
	point.Init(x, y);
	return point;
}

void Point::Init(int x, int y) {
	this->x = x;
	this->y = y;
}

Point Point::operator+=(Point point) {
	this->x += point.x;
	this->y += point.y;
	return *this;
}
