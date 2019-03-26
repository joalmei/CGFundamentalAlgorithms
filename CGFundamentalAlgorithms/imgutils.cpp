#include "imgutils.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>



// ====================================================================================
// PUBLIC MEMBERS
// ====================================================================================
void ImgUtils::WriteBMP(std::string filename, int w, int h, std::vector<std::vector<Pixel>> pixels)
{
	// prepare data
	int dataSize = 3 * w * h;
	unsigned char *img = (unsigned char *) malloc(dataSize);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			int x = i;
			int y = (h - 1) - j;

			img[(x + y * w) * 3 + 2] = pixels[i][j].red;
			img[(x + y * w) * 3 + 1] = pixels[i][j].green;
			img[(x + y * w) * 3 + 0] = pixels[i][j].blue;
		}
	}

	// create file structure
	FILE *f;
	int filesize = 54 + dataSize;		// + header

	unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
	unsigned char bmppad[3] = { 0,0,0 };

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);

	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);

	// save data into file
	fopen_s(&f, filename.c_str(), "wb");
	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);
	for (int i = 0; i<h; i++)
	{
		fwrite(img + (w*(h - i - 1) * 3), 3, w, f);
		fwrite(bmppad, 1, (4 - (w * 3) % 4) % 4, f);
	}

	free(img);
	fclose(f);
}
