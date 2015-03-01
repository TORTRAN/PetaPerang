#include "Clipper.h"
#include "Base.h"
#include "View.h"
#include "Line.h"

using namespace std;

View::View(){

}

void View::Draw(Clipper clipper, FrameBuffer FB){
	for (int i=0; i<clipper.inside.size(); i++){
		if ((clipper.inside[i].P1.x >= clipper.Rect[0].x && clipper.inside[i].P1.x <= clipper.Rect[1].x) && (clipper.inside[i].P1.y >= clipper.Rect[0].y && clipper.inside[i].P1.y <= clipper.Rect[3].y)){ // P1 ada di dalam clipper
			if ((clipper.inside[i].P2.x >= clipper.Rect[0].x && clipper.inside[i].P2.x <= clipper.Rect[1].x) && (clipper.inside[i].P2.y >= clipper.Rect[0].y && clipper.inside[i].P2.y <= clipper.Rect[3].y)){ // P2 ada di dalam clipper
				// P1 dan P2 ada di dalam
				// clipper.inside[i].P1.y += 50;
				// clipper.inside[i].P2.y += 50;
				DrawLineView(clipper.inside[i].P1, clipper.inside[i].P2, clipper, FB);
				// printf("%d %d %d %d\n", clipper.inside[i].P1.x, clipper.inside[i].P1.y, clipper.inside[i].P2.x, clipper.inside[i].P2.y);
			}
			else{
				// P1 di dalam, P2 di luar
				// clipper.inside[i].P1.y += 50;
				// clipper.inside[i].P2.y += 50;
				DrawLineView(clipper.inside[i].P1, clipper.inside[i].P2, clipper, FB);
				// printf("%d %d\n", clipper.inside[i].P1.x, clipper.inside[i].P1.y);
			}
		}
		else{
			if ((clipper.inside[i].P2.x >= clipper.Rect[0].x && clipper.inside[i].P2.x <= clipper.Rect[1].x) && (clipper.inside[i].P2.y >= clipper.Rect[0].y && clipper.inside[i].P2.y <= clipper.Rect[3].y)){ // P2 ada di dalam clipper
				// P1 di luar, P2 ada di dalam
				// clipper.inside[i].P1.y += 50;
				// clipper.inside[i].P2.y += 50;
				DrawLineView(clipper.inside[i].P2, clipper.inside[i].P1, clipper, FB);
				// printf("%d %d\n", clipper.inside[i].P2.x, clipper.inside[i].P2.y);
			}
		}
		// printf("%d %d\n", clipper.inside[i].P1.x, clipper.inside[i].P1.y);
	}
}

void View::DrawLineView(Point P1, Point P2, Clipper clipper, FrameBuffer FB){
	int dx = abs (P2.x-P1.x), sx = P1.x<P2.x	 ? 1 : -1;
	int dy = - abs (P2.y-P1.y), sy = P1.y<P2.y ? 1 : -1;
	int error = dx + dy, e2;
	Color c(255,0,0);
	// printf("Halooo \n");
	for (;;){
		if ((P1.x >= clipper.Rect[0].x && P1.x <= clipper.Rect[1].x) && (P1.y >= clipper.Rect[0].y && P1.y <= clipper.Rect[3].y)){
			
			FB.setPixel(P1.x,P1.y+100,c);
			// printf("Halooo \n");	
		}
		if (P1.x==P2.x && P1.y==P2.y) break;
		e2 = 2 * error;
		if (e2 >= dy) {error += dy; P1.x += sx;}
		if (e2 <= dx) {error += dx; P1.y += sy;}
	}
}
