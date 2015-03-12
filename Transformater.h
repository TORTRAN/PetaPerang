/*
 * Author: Try Ajitiono 13512052
 * Module: Transformation header for IF3260 Computer Graphics
 *
 */

#ifndef TRANSFORMATER_H
#define TRANSFORMATER_H

#define PI 3.14159265
 
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Transformater {	
	public:
		Transformater();
		~Transformater();
		vector<Point> translatePoligon(vector<Point> P, float xMovement, float yMovement);
		vector<Point> reflectPoligon(vector<Point> P, Point reflectionPoint);
		vector<Point> rotatePoligon(vector<Point> P, float degrees);
		vector<Point> resizePoligon(vector<Point> P, float multiplier);
};\

#endif