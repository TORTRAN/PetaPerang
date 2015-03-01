#include "Line.h"

Line::Line(){
}
Line::Line(int x1, int y1, int x2, int y2){
	P1.x = x1;
	P1.y = y1;
	P2.x = x2;
	P2.y = y2;
}
void Line::draw(){
	int dx = abs (P2.x-P1.x), sx = P1.x<P2.x ? 1 : -1;
	int dy = - abs (P2.y-P1.y), sy = P1.y<P2.y ? 1 : -1;
	int error = dx + dy, e2;

	for (;;){
		setPixel(P1.x,P1.y);
		if (P1.x==P2.x && P1.y==P2.y) break;
		e2 = 2 * error;
		if (e2 >= dy) {error += dy; P1.x += sx;}
		if (e2 <= dx) {error += dx; P1.y += sy;}
	}
}