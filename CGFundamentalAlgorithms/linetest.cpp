#include "linetest.h"
#include "line.h"
#include "imgutils.h"

using namespace std;

bool LineTest::Run() {
	int n = 1024;

	vector<vector<Pixel>> pixels(n);
	for (int i = 0; i < n; i++)
		pixels[i].resize(n);

	int power = 1;
	for (int i = 1; i < 10; i++) {
		addLine(Point::Create(0, 0), Point::Create(n, n / power), pixels);
		addLine(Point::Create(0, 0), Point::Create(n / power, n), pixels);
		addLine(Point::Create(0, n / power), Point::Create(n, 0), pixels);
		addLine(Point::Create(n - n / power, n), Point::Create(n, 0), pixels);
		power = power << 1;
	}

	ImgUtils::WriteBMP("Tests/LineTest.bmp", n, n, pixels);

	return true;
}

void LineTest::addLine(Point start, Point end, vector<vector<Pixel>>& image) {
	Line line(start, end);

	for (auto point : line.GetValues()) {
		if (point.x < image.size() && point.y < image[point.x].size())
			image[point.x][point.y] += Pixel::Create(255, 255, 255);
	}
}

