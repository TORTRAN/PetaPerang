/*
 * Author: Try Ajitiono 13512052
 * Module: Transformation header for IF3260 Computer Graphics
 *
 */

#ifndef TRANSFORMATOR_H
#define TRANSFORMATOR_H

#define PI 3.14159265
 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point{
	public:
		float x;
		float y;

		Point() {
			x = 0; y = 0;
		}
		
		Point(float x1, float y1) {
			x = x1; y = y1;
		}
};

class Transformator {	
	public:
		Transformator();
		~Transformator();
		vector<Point> translatePoligon(vector<Point> P, float xMovement, float yMovement);
		vector<Point> reflectPoligon(vector<Point> P, Point reflectionPoint);
		vector<Point> rotatePoligon(vector<Point> P, float degrees);
		vector<Point> rotatePoligonWithPivot(vector<Point> P, float degrees, Point pivot);
		vector<Point> resizePoligon(vector<Point> P, float multiplier);
};\

#endif