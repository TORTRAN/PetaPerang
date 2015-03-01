#include "Clipper.h"
#include "Base.h"
using namespace std;

Clipper::Clipper(){
	size=20;
	location.x=40; // Center clipper
	location.y=40; // Center clipper
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

void Clipper::Delete(FrameBuffer FB){
	deleteLine(Rect[0].x, Rect[0].y, Rect[1].x, Rect[1].y,FB);
	deleteLine(Rect[1].x, Rect[1].y, Rect[2].x, Rect[2].y,FB);
	deleteLine(Rect[2].x, Rect[2].y, Rect[3].x, Rect[3].y,FB);
	deleteLine(Rect[3].x, Rect[3].y, Rect[0].x, Rect[0].y,FB);
}

void Clipper::GetContent(Indonesia I){
	for (int i=0; i<I.vectorIndonesia.size(); i++){
		if (((I.vectorIndonesia[i].P1.x >= Rect[0].x && I.vectorIndonesia[i].P1.x <= Rect[1].x) && (I.vectorIndonesia[i].P1.y >= Rect[0].y && I.vectorIndonesia[i].P1.y <= Rect[3].y)) || ((I.vectorIndonesia[i].P2.x >= Rect[0].x && I.vectorIndonesia[i].P2.x <= Rect[1].x) && (I.vectorIndonesia[i].P2.y >= Rect[0].y && I.vectorIndonesia[i].P2.y <= Rect[3].y))){
			Line line;
			line.line(I.vectorIndonesia[i].P1.x,I.vectorIndonesia[i].P1.y,I.vectorIndonesia[i].P2.x,I.vectorIndonesia[i].P2.y);
			inside.push_back(line);
			//printf("%d %d %d %d\n", I.vectorIndonesia[i].P1.x, I.vectorIndonesia[i].P1.y,I.vectorIndonesia[i].P2.x,I.vectorIndonesia[i].P2.y);
		}
	}
}