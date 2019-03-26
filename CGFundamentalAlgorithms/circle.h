#pragma once

#include "point.h"
#include <vector>


class Circle {
private:
	std::vector<Point> values;

public:
	Circle(Point center, int radius);
	~Circle();
	std::vector<Point> GetValues();

private:
	void initValues(Point start, int radius);
	std::vector<int> static generateValues1stOctant(Point start, Point end);
};

