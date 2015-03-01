/*
	Nama File: kendaraan.h
	Penulis: Tito

	CATATAN:

	Cara makenya sama kayak indonesia.h. Kalo mau digambar panggil Draw(FrameBuffer fb).
	Center itu pantatnya si pesawat dan perahu. Biar gerak panggil move() terus Draw(FrameBuffer fb),
	ntar dia bolak balik sendiri.

*/

#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <vector>
#include "line.h"
#include "base.h"
using namespace std;

class Pesawat{
public:

	vector<Line> vectorPesawat;
	Line line;
	Point center;

	Pesawat();
	Pesawat(Point c);

	void Draw(FrameBuffer fb);
	void move();
private:
	int phase;
	void init();
};

class Perahu{
public:

	vector<Line> vectorPerahu;
	Line line;
	Point center;

	Perahu();
	Perahu(Point c);

	void Draw(FrameBuffer fb);
	void move();
private:
	int phase;
	void init();
};

#endif