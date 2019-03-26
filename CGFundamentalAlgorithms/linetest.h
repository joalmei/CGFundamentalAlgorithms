#pragma once
#include "basetest.h"
#include "imgutils.h"
#include "pixel.h"
#include "point.h"
#include <vector>

class LineTest : BaseTest {
public:
	virtual bool Run();
	

private:
	void addLine(Point start, Point end,
		std::vector<std::vector<Pixel>>& image);
};

