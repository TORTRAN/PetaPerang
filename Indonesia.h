#ifndef INDONESIA_H
#define INDONESIA_H

#include <vector>
#include "line.h"
#include "base.h"
#include "kendaraan.h"
using namespace std;

class Indonesia{
public:
	
	Pesawat pes;
	Perahu per;

	vector<Line> vectorIndonesia;
	Line line;

	Indonesia();

	void Draw(FrameBuffer fb);
};

#endif
