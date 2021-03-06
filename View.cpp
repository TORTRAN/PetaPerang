#include "clipper.h"
#include "base.h"
#include "view.h"
#include "line.h"

using namespace std;

View::View(){
	Pl.x = 400;
	Pl.y = 200;
	Pr.x = 600;
	Pr.y = 400;
}

void View::Draw(Clipper clipper, FrameBuffer FB){
	Line l1(Pl.x,Pl.y,Pr.x,Pl.y);
	Line l2(Pr.x,Pl.y,Pr.x,Pr.y);
	Line l3(Pr.x,Pr.y,Pl.x,Pr.y);
	Line l4(Pl.x,Pr.y,Pl.x,Pl.y);
	l1.draw(FB);
	l2.draw(FB);
	l3.draw(FB);
	l4.draw(FB);
	for (int i=0; i<=clipper.inside.size(); i++){
		if ((clipper.inside[i].P1.x >= clipper.Rect[0].x && clipper.inside[i].P1.x <= clipper.Rect[1].x) && (clipper.inside[i].P1.y >= clipper.Rect[0].y && clipper.inside[i].P1.y <= clipper.Rect[3].y)){ // P1 ada di dalam clipper
			if ((clipper.inside[i].P2.x >= clipper.Rect[0].x && clipper.inside[i].P2.x <= clipper.Rect[1].x) && (clipper.inside[i].P2.y >= clipper.Rect[0].y && clipper.inside[i].P2.y <= clipper.Rect[3].y)){ // P2 ada di dalam clipper
				// P1 dan P2 ada di dalam
				// clipper.inside[i].P1.y += 50;
				// clipper.inside[i].P2.y += 50;
				Point Pt1;
				Point Pt2;
				Pt1.x = (clipper.inside[i].P1.x - clipper.Rect[0].x) * (200 / (clipper.Rect[2].x-clipper.Rect[0].x)) + 400;
				Pt1.y = (clipper.inside[i].P1.y - clipper.Rect[0].y) * (200 / (clipper.Rect[2].y-clipper.Rect[0].y)) + 200;
	
				Pt2.x = (clipper.inside[i].P2.x - clipper.Rect[0].x) * (200 / (clipper.Rect[2].x-clipper.Rect[0].x)) + 400;
				Pt2.y = (clipper.inside[i].P2.y - clipper.Rect[0].y) * (200 / (clipper.Rect[2].y-clipper.Rect[0].y)) + 200;	
	
				Line line(Pt1.x,Pt1.y,Pt2.x,Pt2.y);		
				line.draw(FB);	
				
				 //printf("%d %d %d %d\n", clipper.inside[i].P1.x, clipper.inside[i].P1.y, clipper.inside[i].P2.x, clipper.inside[i].P2.y);
			}
			else{
				Point Pt1;
				Point Pt2;
				Pt1.x = (clipper.inside[i].P1.x - clipper.Rect[0].x) * (200 / (clipper.Rect[2].x-clipper.Rect[0].x)) + 400;
				Pt1.y = (clipper.inside[i].P1.y - clipper.Rect[0].y) * (200 / (clipper.Rect[2].y-clipper.Rect[0].y)) + 200;

				Pt2.x = (clipper.inside[i].P2.x - clipper.Rect[0].x) * (200 / (clipper.Rect[2].x-clipper.Rect[0].x)) + 400;
				Pt2.y = (clipper.inside[i].P2.y - clipper.Rect[0].y) * (200 / (clipper.Rect[2].y-clipper.Rect[0].y)) + 200;	
	
				int index2 = clipper.inside[i].P2.getIndex(clipper.Rect[0],clipper.Rect[2]);
				
				printf("%d\n",index2);			
	
				Line templine(Pt1.x,Pt1.y,Pt2.x,Pt2.y);
				//dikiri
				if(index2&0x1){
					int tempx = 400;
					int tempy = templine.getY(400);
					Line line(Pt1.x,Pt1.y,tempx,tempy);
					line.draw(FB);
				}		
				//dikanan
				else if(index2&0x2){
					int tempx = 600;
					int tempy = templine.getY(600);
					Line line(Pt1.x,Pt1.y,tempx,tempy);
					line.draw(FB);
				}		
				//dibawah
				else if(index2&0x4){
					int tempx = templine.getX(400);
					int tempy = 400;
					Line line(Pt1.x,Pt1.y,tempx,tempy);
					line.draw(FB);
				}		
				//diatas
				else if(index2&0x8){
					int tempx = templine.getX(200);
					int tempy = 200;
					Line line(Pt1.x,Pt1.y,tempx,tempy);
					line.draw(FB);
				}				
						
				// P1 di dalam, P2 di luar
				// clipper.inside[i].P1.y += 50;
				// clipper.inside[i].P2.y += 50;
		//		DrawLineView(clipper.inside[i].P1, clipper.inside[i].P2, clipper, FB);
				// printf("%d %d\n", clipper.inside[i].P1.x, clipper.inside[i].P1.y);
			}
		}
		else{
			if ((clipper.inside[i].P2.x >= clipper.Rect[0].x && clipper.inside[i].P2.x <= clipper.Rect[1].x) && (clipper.inside[i].P2.y >= clipper.Rect[0].y && clipper.inside[i].P2.y <= clipper.Rect[3].y)){ // P2 ada di dalam clipper
				// P1 di luar, P2 ada di dalam
				// clipper.inside[i].P1.y += 50;
				// clipper.inside[i].P2.y += 50;
			//	DrawLineView(clipper.inside[i].P2, clipper.inside[i].P1, clipper, FB);
				// printf("%d %d\n", clipper.inside[i].P2.x, clipper.inside[i].P2.y);
				Point Pt1;
				Point Pt2;
				Pt1.x = (clipper.inside[i].P1.x - clipper.Rect[0].x) * (200 / (clipper.Rect[2].x-clipper.Rect[0].x)) + 400;
				Pt1.y = (clipper.inside[i].P1.y - clipper.Rect[0].y) * (200 / (clipper.Rect[2].y-clipper.Rect[0].y)) + 200;

				Pt2.x = (clipper.inside[i].P2.x - clipper.Rect[0].x) * (200 / (clipper.Rect[2].x-clipper.Rect[0].x)) + 400;
				Pt2.y = (clipper.inside[i].P2.y - clipper.Rect[0].y) * (200 / (clipper.Rect[2].y-clipper.Rect[0].y)) + 200;	
	
				char index2 = clipper.inside[i].P1.getIndex(clipper.Rect[0],clipper.Rect[2]);

				Line templine(Pt1.x,Pt1.y,Pt2.x,Pt2.y);
				//dikiri
				if(index2&0x1){
					int tempx = 400;
					int tempy = templine.getY(400);
					Line line(Pt2.x,Pt2.y,tempx,tempy);
					line.draw(FB);
				}		
				//dikanan
				else if(index2&0x2){
					int tempx = 600;
					int tempy = templine.getY(600);
					Line line(Pt2.x,Pt2.y,tempx,tempy);
					line.draw(FB);
				}		
				//dibawah
				else if(index2&0x4){
					int tempx = templine.getX(400);
					int tempy = 400;
					Line line(Pt2.x,Pt2.y,tempx,tempy);
					line.draw(FB);
				}		
				//diatas
				else if(index2&0x8){
					int tempx = templine.getX(200);
					int tempy = 200;
					Line line(Pt2.x,Pt2.y,tempx,tempy);
					line.draw(FB);
				}			
			}
		}
		// printf("%d %d\n", clipper.inside[i].P1.x, clipper.inside[i].P1.y);
	}
}

void View::DrawLineView(Point P1, Point P2, Clipper clipper, FrameBuffer FB){
	Point Pt1;
	Point Pt2;
	Pt1.x = (P1.x - clipper.Rect[0].x) * (200 / (clipper.Rect[0].x-clipper.Rect[2].x)) + 400;
	Pt1.y = (P1.y - clipper.Rect[0].y) * (200 / (clipper.Rect[0].y-clipper.Rect[2].y)) + 400;
	
	Pt2.x = (P2.x - clipper.Rect[0].x) * (200 / (clipper.Rect[0].x-clipper.Rect[2].x)) + 400;
	Pt2.y = (P2.y - clipper.Rect[0].y) * (200 / (clipper.Rect[0].y-clipper.Rect[2].y)) + 400;
	

	
	
	int dx = abs (Pt2.x-Pt1.x), sx = Pt1.x<Pt2.x	 ? 1 : -1;
	int dy = - abs (Pt2.y-Pt1.y), sy = Pt1.y<Pt2.y ? 1 : -1;
	int error = dx + dy, e2;
	Color c(255,0,0);
	// printf("Halooo \n");
	for (;;){
		//printf("%d %d %d %d\n", Pt1.x, Pt1.y, Pt2.x, Pt2.y);	
		//if ((Pt1.x >= 200 && Pt1.x <= 400) && (Pt1.y >= 200 && Pt1.y <= 400)){
			
			FB.setPixel(Pt1.x,Pt1.y,c);
				
		//}
		if (Pt1.x==Pt2.x && Pt1.y==Pt2.y) break;
		e2 = 2 * error;
		if (e2 >= dy) {error += dy; Pt1.x += sx;}
		if (e2 <= dx) {error += dx; Pt1.y += sy;}
	}
}
