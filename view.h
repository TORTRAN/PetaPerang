#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include "line.h"
#include "base.h"
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
#include "clipper.h"

using namespace std;
class View{
public:
	View();
	void Draw(Clipper clipper, FrameBuffer FB);
	void DrawLineView(Point P1, Point P2, Clipper clipper, FrameBuffer FB);
};
#endif