#pragma once
class Pixel
{
public:
	Pixel();
	~Pixel();

	unsigned char red = 0;
	unsigned char green = 0;
	unsigned char blue = 0;

	static Pixel Create(unsigned char r, unsigned char g, unsigned char b);
	void Init(unsigned char r, unsigned char g, unsigned char b);
	Pixel operator+= (Pixel p);
};

