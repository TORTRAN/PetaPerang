#ifndef LINE_H
#define LINE_H

class Line{
public:
	Point P1;
	Point P2;

	Line();
	Line(int x1, int y1, int x2, int y2);
	void draw();
};