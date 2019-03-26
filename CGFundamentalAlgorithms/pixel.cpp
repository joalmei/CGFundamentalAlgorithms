#include "pixel.h"
#define min(x, y) x > y ? y : x;


// ====================================================================================
// PUBLIC MEMBERS
// ====================================================================================
Pixel::Pixel() {
}

Pixel::~Pixel() {
}

void Pixel::Init(unsigned char r, unsigned char g, unsigned char b) {
	this->red = r;
	this->green = g;
	this->blue = b;
}

Pixel Pixel::operator+=(Pixel p) {
	int r = (int)this->red + (int)p.red;
	int g = (int)this->green + (int)p.green;
	int b = (int)this->blue + (int)p.blue;


	this->red = (unsigned char)min(r, 255);
	this->green = (unsigned char)min(g, 255);
	this->blue = (unsigned char)min(b, 255);
	return *this;
}

Pixel Pixel::Create(unsigned char r, unsigned char g, unsigned char b) {
	Pixel pixel;
	pixel.Init(r, g, b);
	return pixel;
}

