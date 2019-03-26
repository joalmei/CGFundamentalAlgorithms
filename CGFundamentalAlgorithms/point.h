#pragma once
class Point
{
public:
	unsigned int x = -1;
	unsigned int y = -1;

	Point();
	~Point();

	static Point Create(unsigned int x, unsigned int y);
	void Init(int x, int y);
	Point operator+=(Point point);

};

