#ifndef BASE_H
#define BASE_H

#include <unistd.h>
#include <fcntl.h>		/* for fcntl */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>		/* for mmap */
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <vector>
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//class color defines color that needed with rgb
class Color{
	public:
	int Red;
	int Green;
	int Blue;
	
	Color();
	Color(int red, int green, int blue);
	
	void setRed(int r);
	void setGreen(int g);
	void setBlue(int b);
};

//class Point defines point for coordinate to set
class Point{
public:
	float x;
	float y;

	Point();
	Point(float x1, float y1);
};


//class FrameBuffer supaya frame buffer dapat diset secara general.
class FrameBuffer
{
public:
	char* fbp;
	long int screensize;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	int fbfd;					/* frame buffer file descriptor */

	FrameBuffer();
	void setPixel(int x, int y,Color color);
	void deletePixel(int x, int y);
	/* data */
};

void drawLine(int x0, int y0, int x1, int y1,FrameBuffer fb);
void deleteLine(int x0, int y0, int x1, int y1,FrameBuffer fb);

#endif