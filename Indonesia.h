#ifndef INDONESIA_H
#define INDONESIA_H

#include <vector>
#include "line.h"
#include "base.h"
using namespace std;

class Indonesia{
public:

	vector<Line> vectorIndonesia;
	Line line;

	Indonesia();

	void Draw(FrameBuffer fb);
};

#endif