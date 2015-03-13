/*
 * Author: Try Ajitiono 13512052
 * Module: Transformation header for IF3260 Computer Graphics
 *
 */

/* Header and Pre-processor */
 
#ifndef TRANSFORMATOR_H
#define TRANSFORMATOR_H

#define PI 3.14159265
 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* Point Class (for debugging) */

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
		/*
		 * Constructor
		 */
		~Transformator();
		vector<Point> translatePoligon(vector<Point> P, float xMovement, float yMovement);
		/*
		 * Destructor
		 */
		vector<Point> reflectPoligonXAxis(vector<Point> P);
		/*
		 * Reflects a vector of Point to the X Axis
		 */
		vector<Point> reflectPoligonYAxis(vector<Point> P);
		/*
		 * Reflects a vector of Point to the Y Axis
		 */
		vector<Point> rotatePoligon(vector<Point> P, float degrees);
		/*
		 * Rotates a vector of Point by some degrees
		 */
		vector<Point> rotatePoligonWithPivot(vector<Point> P, float degrees, Point pivot);
		/*
		 * Rotates a vector of Point by some degrees to a pivot point
		 */
		vector<Point> resizePoligon(vector<Point> P, float multiplier);
		/*
		 * Not yet implemented
		 */
};

#endif