#include "clipper.h"
#include "base.h"
using namespace std;

Clipper::Clipper(){
	size=20;
	location.x=40;
	location.y=40;
	UpdateClip();
}

void Clipper::UpdateClip(){
	Rect[0].x=location.x-size;
	Rect[0].y=location.y-size;

	Rect[1].x=location.x+size;
	Rect[1].y=location.y-size;

	Rect[2].x=location.x+size;
	Rect[2].y=location.y+size;

	Rect[3].x=location.x-size;
	Rect[3].y=location.y+size;
}

void Clipper::MoveUp(){
	location.y-=2;
	UpdateClip();
}

void Clipper::MoveLeft(){
	location.x-=2;
	UpdateClip();
}

void Clipper::MoveDown(){
	location.y+=2;
	UpdateClip();
}

void Clipper::MoveRight(){
	location.x+=2;
	UpdateClip();
}

void Clipper::ZoomOut(){
	size+=2;
	UpdateClip();
}

void Clipper::ZoomIn(){
	size-=2;
	UpdateClip();
}

void Clipper::Draw(FrameBuffer FB){
	drawLine(Rect[0].x, Rect[0].y, Rect[1].x, Rect[1].y,FB);
	drawLine(Rect[1].x, Rect[1].y, Rect[2].x, Rect[2].y,FB);
	drawLine(Rect[2].x, Rect[2].y, Rect[3].x, Rect[3].y,FB);
	drawLine(Rect[3].x, Rect[3].y, Rect[0].x, Rect[0].y,FB);
}