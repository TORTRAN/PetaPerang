#include "clipper.h"
#include "base.h"

using namespace std;

FrameBuffer::FrameBuffer(){
	/* open the file for reading and writing */
	fbfd = open("/dev/fb0",O_RDWR);
	if (!fbfd) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}
	printf ("The framebuffer device was opened successfully.\n");

	/* get the fixed screen information */
	if (ioctl (fbfd, FBIOGET_FSCREENINFO, &finfo)) {
		printf("Error reading fixed information.\n");
		exit(2);
	}

	/* get variable screen information */
	if (ioctl (fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
		printf("Error reading variable information.\n");
		exit(3);
	}
	/* map the device to memory */
	fbp = (char*)mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	screensize = 0;

	if ((int)fbp == -1) {
		printf ("Error: failed to map framebuffer device to memory.\n");
		exit(4);
	}
	printf ("Framebuffer device was mapped to memory successfully.\n");
}

void FrameBuffer::setPixel(int x, int y,Color color){
    int location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
    *(fbp + location) = color.Blue; // Some blue 
    *(fbp + location + 1) = color.Green; // A little green 
    *(fbp + location + 2) = color.Red; // A lot of red
    *(fbp + location + 3) = 0; // No transparency 
}

void drawLine(int x0, int y0, int x1, int y1,FrameBuffer fb){
	int dx = abs (x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = - abs (y1-y0), sy = y0<y1 ? 1 : -1;
	int error = dx + dy, e2;
	Color c(255,255,0);

	for (;;){
		fb.setPixel(x0,y0,c);
		if (x0==x1 && y0==y1) break;
		e2 = 2 * error;
		if (e2 >= dy) {error += dy; x0 += sx;}
		if (e2 <= dx) {error += dx; y0 += sy;}
	}
}

Color::Color(){
		Red=255;
		Green=255;
		Blue=255;
	}
	
Color::Color(int red, int green, int blue){
	if(red<=255 && red>=0 && green<=255 && green>=0 && blue>=0&& blue<=255){
		
		Red=red;
		Green=green;
		Blue=blue;
	}
	else{
		Red=0;
		Green=0;
		Blue=0;
	}
}
	
void Color::setRed(int r){
	if(r<=0&&r>=255)Red=r;
}

void Color::setGreen(int g){
	if(g<=0&&g>=255)Green=g;
}

void Color::setBlue(int b){
	if(b<=0&&b>=255)Blue=b;
}

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(int x1, int y1){
	x = x1;
	y = y1;
}