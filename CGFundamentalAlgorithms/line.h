#pragma once

#include "point.h"
#include <vector>


class Line
{
private:
	int minX, maxX;
	int minY, maxY;
	std::vector<Point> values;

public:
	Line(Point start, Point end);
	~Line();
	std::vector<Point> GetValues();

private:
	void initValues(Point start, Point end);
	std::vector<int> static generateValues1stOctant(Point start, Point end);
};

