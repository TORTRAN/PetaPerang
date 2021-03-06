#include "kendaraan.h"


Pesawat::Pesawat(){
	center = Point(150,130);
	phase=0;
	init();
}

Pesawat::Pesawat(Point c){
	center = c;
	phase=0;
	init();
}
		
void Pesawat::Draw(FrameBuffer fb){
	for(int i = 0 ; i < vectorPesawat.size() ; i++)
		vectorPesawat[i].draw(fb);
}

void Pesawat::init(){
	vectorPesawat.clear();

	//line = Line(center.x+0, center.y+0, center.x+25, center.y+0); vectorPesawat.push_back(line);
	//line = Line(center.x+0, center.y-12, center.x+25, center.y-12); vectorPesawat.push_back(line);
	
	line = Line(center.x+0, center.y+4, center.x+0, center.y-4); vectorPesawat.push_back(line);//back
	line = Line(center.x+0, center.y+4, center.x+3, center.y+2); vectorPesawat.push_back(line);//tri-atas
	line = Line(center.x+0, center.y-4, center.x+3, center.y-2); vectorPesawat.push_back(line);//tri-bawah

	line = Line(center.x+3, center.y+2, center.x+8, center.y+2); vectorPesawat.push_back(line);//bodi-beakang-atas
	line = Line(center.x+3, center.y-2, center.x+8, center.y-2); vectorPesawat.push_back(line);///body-belakang-bawah

	line = Line(center.x+8, center.y-2, center.x+8, center.y-6); vectorPesawat.push_back(line);//sayap-base
	line = Line(center.x+8, center.y+2, center.x+8, center.y+6); vectorPesawat.push_back(line);

	line = Line(center.x+8, center.y+6, center.x+16, center.y+2); vectorPesawat.push_back(line);//sayap-miring
	line = Line(center.x+8, center.y-6, center.x+16, center.y-2); vectorPesawat.push_back(line);

	line = Line(center.x+16, center.y-2, center.x+20, center.y-2); vectorPesawat.push_back(line);//bodi depan
	line = Line(center.x+16, center.y+2, center.x+20, center.y+2); vectorPesawat.push_back(line);

	line = Line(center.x+20, center.y-2, center.x+25, center.y); vectorPesawat.push_back(line);//kepala
	line = Line(center.x+20, center.y+2, center.x+25, center.y); vectorPesawat.push_back(line);
}

void Pesawat::move(){
	phase++;
	if(phase<=2){
		center.x+=4;
	}else if(phase<=5){
		center.x-=4;
	}else{
		phase=0;
		center.x+=4;
	}
	init();
}

//	line = Line(center.x+0, center.y+0, center.x+0, center.y+0); vectorPesawat.push_back(line);

//	line = Line(center.x+0, center.y+0, center.x+0, center.y+0); vectorPerahu.push_back(line);

Perahu::Perahu(){
	center = Point(150,180);
	phase=0;
	init();
}

Perahu::Perahu(Point c){
	center = c;
	phase=0;
	init();
}
		
void Perahu::Draw(FrameBuffer fb){
	for(int i = 0 ; i < vectorPerahu.size() ; i++)
		vectorPerahu[i].draw(fb);
}

void Perahu::init(){
	vectorPerahu.clear();

	//atas
	line = Line(center.x+0, center.y+0, center.x+10, center.y+0); vectorPerahu.push_back(line);
	line = Line(center.x+10, center.y+0, center.x+10, center.y-5); vectorPerahu.push_back(line);
	line = Line(center.x+10, center.y-5, center.x+15, center.y-5); vectorPerahu.push_back(line);
	line = Line(center.x+15, center.y-5, center.x+15, center.y); vectorPerahu.push_back(line);
	line = Line(center.x+15, center.y+0, center.x+25, center.y+0); vectorPerahu.push_back(line);

	//bawah
	line = Line(center.x+0, center.y+0, center.x+5, center.y+7); vectorPerahu.push_back(line);
	line = Line(center.x+5, center.y+7, center.x+20, center.y+7); vectorPerahu.push_back(line);
	line = Line(center.x+20, center.y+7, center.x+25, center.y+0); vectorPerahu.push_back(line);

}

void Perahu::move(){
	phase++;
	if(phase<=10){
		center.x+=4;
	}else if(phase<=21){
		center.x-=4;
	}else{
		phase=0;
		center.x+=4;
	}
	init();
}
