#ifndef CLIPPER_H
#define CLIPPER_H

#include <unistd.h>
#include <fcntl.h>		/* for fcntl */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>		/* for mmap */
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <vector>
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "base.h"
#include "indonesia.h"
//class clipper kota kecil berkursor yang dapat dibesar/diperkecil untuk memilih gambar mana yang akan diambil.
class Clipper{
private:
	Indonesia map;

public:
	Point location;
	Point Rect[4];//berisi point-point pada titik ujung segiempat
	int size;

	Clipper();
	void UpdateClip();//penomoran pojok dari sisi kiri atas lalu searah jarum jam, berisi definisi titik pojok

	//mover
	void MoveUp();
	void MoveLeft();
	void MoveDown();
	void MoveRight();

	//zoomer
	void ZoomOut();
	void ZoomIn();
	
	void Draw(FrameBuffer FB);
	//void get_content();
};


#endif