#include "indonesia.h"


Indonesia::Indonesia(){
	//sumatera
	line.line(10,10,20,10);vectorIndonesia.push_back(line);
	line.line(20,10,25,15);vectorIndonesia.push_back(line);
	line.line(25,15,35,15);vectorIndonesia.push_back(line);
	line.line(35,15,45,30);vectorIndonesia.push_back(line);
	line.line(45,30,55,30);vectorIndonesia.push_back(line);//5
	line.line(55,30,65,40);vectorIndonesia.push_back(line);
	line.line(65,40,70,40);vectorIndonesia.push_back(line);
	line.line(70,40,85,55);vectorIndonesia.push_back(line);
	line.line(85,55,90,55);vectorIndonesia.push_back(line);
	line.line(90,55,115,85);vectorIndonesia.push_back(line);//10
	line.line(115,85,115,95);vectorIndonesia.push_back(line);
	line.line(115,95,100,100);vectorIndonesia.push_back(line);
	line.line(100,100,85,80);vectorIndonesia.push_back(line);
	line.line(85,80,80,80);vectorIndonesia.push_back(line);
	line.line(80,80,65,65);vectorIndonesia.push_back(line);//15
	line.line(65,65,60,65);vectorIndonesia.push_back(line);
	line.line(60,65,45,50);vectorIndonesia.push_back(line);
	line.line(45,50,40,50);vectorIndonesia.push_back(line);
	line.line(40,50,25,30);vectorIndonesia.push_back(line);
	line.line(25,30,20,30);vectorIndonesia.push_back(line);
	line.line(20,30,10,10);vectorIndonesia.push_back(line);
	//bangka
	line.line(95,55,105,55);vectorIndonesia.push_back(line);
	line.line(105,55,115,70);vectorIndonesia.push_back(line);
	line.line(115,70,105,70);vectorIndonesia.push_back(line);
	line.line(105,70,95,55);vectorIndonesia.push_back(line);
	//belitung
	line.line(115,65,125,65);vectorIndonesia.push_back(line);
	line.line(125,65,125,75);vectorIndonesia.push_back(line);
	line.line(125,75,115,75);vectorIndonesia.push_back(line);
	line.line(115,75,115,65);vectorIndonesia.push_back(line);
	//jawa
	line.line(105,95,120,95);vectorIndonesia.push_back(line);
	line.line(120,95,120,100);vectorIndonesia.push_back(line);
	line.line(120,100,135,100);vectorIndonesia.push_back(line);
	line.line(135,100,135,105);vectorIndonesia.push_back(line);
	line.line(135,105,155,105);vectorIndonesia.push_back(line);//5
	line.line(155,105,155,95);vectorIndonesia.push_back(line);
	line.line(155,95,175,95);vectorIndonesia.push_back(line);
	line.line(175,95,175,105);vectorIndonesia.push_back(line);
	line.line(175,105,195,105);vectorIndonesia.push_back(line);
	line.line(195,105,195,115);vectorIndonesia.push_back(line);//10
	line.line(195,115,205,115);vectorIndonesia.push_back(line);
	line.line(205,115,205,125);vectorIndonesia.push_back(line);
	line.line(205,125,165,125);vectorIndonesia.push_back(line);
	line.line(165,125,165,115);vectorIndonesia.push_back(line);
	line.line(165,115,155,115);vectorIndonesia.push_back(line);//15
	line.line(155,115,155,120);vectorIndonesia.push_back(line);
	line.line(155,120,135,120);vectorIndonesia.push_back(line);
	line.line(135,120,135,115);vectorIndonesia.push_back(line);
	line.line(135,115,115,115);vectorIndonesia.push_back(line);
	line.line(115,115,115,105);vectorIndonesia.push_back(line);//20
	line.line(115,105,105,105);vectorIndonesia.push_back(line);
	line.line(105,105,105,95);vectorIndonesia.push_back(line);
	//kalimantan
	// line.line(175,25,195,27);vectorIndonesia.push_back(line);
	// line.line(195,27,210,20);vectorIndonesia.push_back(line);
	// line.line(210,20,230,5);vectorIndonesia.push_back(line);
	// line.line(230,5,250,5);vectorIndonesia.push_back(line);
	// line.line(250,5,255,10);vectorIndonesia.push_back(line);
	// line.line(255,10,255,15);vectorIndonesia.push_back(line);
	// line.line(255,15,265,23);vectorIndonesia.push_back(line);
	// line.line(265,23,263,28);vectorIndonesia.push_back(line);
	// line.line(263,28,253,25);vectorIndonesia.push_back(line);
	// line.line(253,25,243,35);vectorIndonesia.push_back(line);
	// line.line(243,35,253,40);vectorIndonesia.push_back(line);
	// line.line(253,40,255,50);vectorIndonesia.push_back(line);
	// line.line(255,50,245,65);vectorIndonesia.push_back(line);
	// line.line(245,65,240,65);vectorIndonesia.push_back(line);
	// line.line(240,65,240,72);vectorIndonesia.push_back(line);
	// line.line(240,72,230,72);vectorIndonesia.push_back(line);
	// line.line(230,72,230,65);vectorIndonesia.push_back(line);
	// line.line(230,65,215,65);vectorIndonesia.push_back(line);
	// line.line(215,65,215,71);vectorIndonesia.push_back(line);
	// line.line(215,71,205,71);vectorIndonesia.push_back(line);
	// line.line(205,71,205,67);vectorIndonesia.push_back(line);
	// line.line(205,67,195,67);vectorIndonesia.push_back(line);
	// line.line(195,67,185,60);vectorIndonesia.push_back(line);
	// line.line(185,60,185,45);vectorIndonesia.push_back(line);
	// line.line(185,45,178,40);vectorIndonesia.push_back(line);
	// line.line(178,40,173,30);vectorIndonesia.push_back(line);
	// line.line(173,30,175,25);vectorIndonesia.push_back(line);
	//sulawesi
	// line.line(290,24,298,24);vectorIndonesia.push_back(line);
	// line.line(298,24,298,18);vectorIndonesia.push_back(line);
	// line.line(298,18,305,18);vectorIndonesia.push_back(line);
	// line.line(305,18,205,24);vectorIndonesia.push_back(line);
	// line.line(205,24,240,23);vectorIndonesia.push_back(line);
	// line.line(240,23,240,10);vectorIndonesia.push_back(line);
}
		
void Indonesia::Draw(FrameBuffer fb){
	for(int i = 0 ; i < vectorIndonesia.size() ; i++)
		vectorIndonesia[i].draw(fb);
}