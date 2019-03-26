#include "line.h"
#include <list>

using namespace std;

#define abs(x) (x < 0 ? -x : x)


// ====================================================================================
// PUBLIC MEMBERS
// ====================================================================================
Line::Line(Point start, Point end) {
	initValues(start, end);
}

Line::~Line() {
}

vector<Point> Line::GetValues() {
	return values;
}

// ====================================================================================
// PRIVATE MEMBERS
// ====================================================================================
void Line::initValues(Point start, Point end) {
	int deltaX = end.x - start.x;
	int deltaY = end.y - start.y;

	list<Point> tempList;
	if (deltaY > 0 && deltaX > 0) {
		if (deltaX < deltaY) {				// 2nd octant
			auto tempValues = generateValues1stOctant(Point::Create(start.y, start.x), Point::Create(end.y, end.x));
			for (int y = 0; y <= deltaY; y++)
				tempList.push_back(Point::Create(tempValues[y], y));
		}
		else {								// 1st octant
			auto tempValues = generateValues1stOctant(start, end);
			for (int x = 0; x <= deltaX; x++)
				tempList.push_back(Point::Create(x, tempValues[x]));
		}
	}
	else if (deltaY < 0 && deltaX > 0) {
		if (abs(deltaX) > abs(deltaY)) {	// 4th
			auto tempValues = generateValues1stOctant(Point::Create(0,end.y), Point::Create(deltaX, start.y));
			for (int x = 0; x < tempValues.size(); x++)
				tempList.push_back(Point::Create(end.x - x, tempValues[x]));
		}
		else {								// 3rd
			auto tempValues = generateValues1stOctant(Point::Create(end.y, 0), Point::Create(start.y, deltaX));
			for (int y = 0; y < tempValues.size(); y++)
				tempList.push_back(Point::Create(end.x - tempValues[y], end.y + y));
		}
	}

	values.reserve(tempList.size());
	copy(tempList.begin(), tempList.end(), back_inserter(values));
}

vector<int> Line::generateValues1stOctant(Point start, Point end) {
	int deltaX = end.x - start.x;
	int deltaY = end.y - start.y;

	vector<int> line(deltaX + 1);

	// the decision variable incremental equation is defined as:
	// d[n] = d[n - 1] + a       if the LOWER pixel is chosen
	// d[n] = d[n - 1] + a + b   otherwise
	int d = 0;
	int a = 2 * deltaY;
	int b = 2 * deltaX;


	// starts in the origin
	int y = start.y;
	line[0] = y;
	d = a - b / 2;

	for (int x = 1; x <= deltaX; x++) {
		if (d > 0) {
			d += a - b;
			y++;
		}
		else {
			d += a;
		}

		line[x] = y;
	}

	return line;
}
