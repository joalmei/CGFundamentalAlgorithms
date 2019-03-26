#pragma once

#include "pixel.h"
#include <vector>


class ImgUtils {
public:
	struct sPoint {
	};


public:
	// File methods
	void static WriteBMP(std::string filename, int width, int height, std::vector<std::vector<Pixel>> pixels);
};
